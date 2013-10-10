/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ParallelTeamProcessCount3

Data: 10/09/2013

*/
#include "ParallelTeamProcessCount3.h"
#include <iostream>
#include <string>
#include <stdlib.h>   // Declaration for exit() and rand()
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <algorithm>

#include <sys/ipc.h>
#include <sys/shm.h>

using namespace std;

ParallelTeam::ParallelTeam(int* workList, int workListSize):pids() {
	_workList = workList;
	_workListSize = workListSize;
	// TODO Auto-generated constructor stub
	cout << "ParallelTeam started" << endl;
}

ParallelTeam::~ParallelTeam() {
	// TODO Auto-generated destructor stub
}

// Count the 3s
void ParallelTeam::childLogic(int i, Memory *mem) {
	//cout << "zzchild " << i << endl;
	int stopTill = min<int>(i*workSegment+workSegment, _workListSize);

	int total = 0;
	for(int x = i*workSegment; x < stopTill; x++) if(_workList[x]==3) total++;
	mem->write(i, total);
	cout << "Total in child "<< i << ": " << total << endl;
}

// Fold the 3s
void ParallelTeam::onChildrenComplete(int n, Memory *mem) {
	int total = 0;
	for(int x = 0; x < n; x++) total += mem->read(x);
	cout << "Total 3s folded from shared memory: " << total << endl;

	delete mem;
	shmdt(shmAddr);
	shmctl(shmPos, IPC_RMID, 0);
}

Memory* ParallelTeam::createShm(int n) {
	shmPos = shmget(IPC_PRIVATE, n*sizeof(int), IPC_CREAT | SHM_R | SHM_W);
	shmAddr = (int*) shmat(shmPos, NULL, 0);
	return new Memory(shmAddr, n);
}

void ParallelTeam::createProcessTeam(int n) {
	workSegment = (int) _workListSize / n;
	createShm(n);
	Memory* mem = createShm(n);

	// create process
	time_t start_time = time(NULL);

	pid_t t;
	for(int i = 0; i < n; i++) {
		t = fork();
		if(t < 0) {
			cout << "error spawning process" << endl;
			_exit(1);
		}
		else if(t==0) { // CHILD PROCESS
			//mem.write(i, 32);
			struct tm *tm;
			time_t now = time(0);
			tm = localtime (&now);

			//srand(i * time(NULL)); // pick a random number in a system range
			//int x = 1 + rand() % 7; // random number constraint
			//sleep(x); // child process sleep for x seconds
			childLogic(i, mem);
			cout << "Child says: my process is ending. PPID:" << getppid() << ", PID:" << getpid();
			printf (" Launched %04d-%02d-%02d %02d:%02d:%02d\n",
			        tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
			        tm->tm_hour, tm->tm_min, tm->tm_sec);
			_exit(0); // exit the child process
		}
		else if(t > 0) {

			pids.push_back(t);
		}
	}


	int status;
	for(int i = 0; i < n; i++) {
		pid_t wid = waitpid(-1, &status, 0); // waitpid(-1...) signifies to wait until any child process ends
		cout << "Parent says: my child process #" << wid << " ended. Second Duration: " << (time(NULL) - start_time) << endl;
	}
	onChildrenComplete(n, mem); //Post process

}


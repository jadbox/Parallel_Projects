/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ParallelTeamProcessThreadCount3

Data: 10/16/2013

*/
#include "ParallelTeamProcessThreadCount3s.h"
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
#include <cassert>

using namespace std;

ParallelTeam::ParallelTeam(int* workList, int workListSize):mem(NULL),pthreadsSize(0),pthreads(NULL) {
	_workList = workList;
	_workListSize = workListSize;
	// TODO Auto-generated constructor stub
	cout << "ParallelTeam started" << endl;
}

ParallelTeam::~ParallelTeam() {
	// TODO Auto-generated destructor stub
}

// Count the 3s
void ParallelTeam::childLogic(int i) {
	//cout << "zzchild " << i << endl;
	int stopTill = min<int>(i*workSegment+workSegment, _workListSize);

	int total = 0;
	for(int x = i*workSegment; x < stopTill; x++) if(_workList[x]==3) total++;
	mem->write(i, total);
	cout << "Total in child "<< i << ": " << total << endl;
	pthread_exit(NULL);
}

void ParallelTeam::childLogicWrapper() {

	int i  = pthreadsSize;
	cout << "childLogicWrapper " << i;

	//mem.write(i, 32);
	struct tm *tm;
	time_t now = time(0);
	tm = localtime (&now);

	//srand(i * time(NULL)); // pick a random number in a system range
	//int x = 1 + rand() % 7; // random number constraint
	//sleep(x); // child process sleep for x seconds
	childLogic(i);
	cout << "Child says: my process is ending. PPID:" << getppid() << ", PID:" << getpid();
	printf (" Launched %04d-%02d-%02d %02d:%02d:%02d\n",
			tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
			tm->tm_hour, tm->tm_min, tm->tm_sec);
}

// Fold the 3s
void ParallelTeam::onChildrenComplete(int n) {
	int total = 0;
	for(int x = 0; x < n; x++) total += mem->read(x);
	cout << "Total 3s folded from shared memory: " << total << endl;

	delete mem;
//	shmdt(shmAddr);
//	shmctl(shmPos, IPC_RMID, 0);
}

Memory* ParallelTeam::createShm(int n) {
	return new Memory(n); // doesn't use shared memory for threads
}

static void* hello_helper(void *This)
{
		cout << "hello_helper";
		((ParallelTeam *)This)->childLogicWrapper();

		pthread_exit(NULL);
		return 0;
}

void ParallelTeam::createProcessTeam(int n) {
	cout << "createProcessTeam";
	assert(pthreadsSize == 0); // can't be already running

	workSegment = (int) _workListSize / n;
	createShm(n);
	mem = createShm(n);

	// create process
	time_t start_time = time(NULL);
	pthreads = new pthread_t[n];
	for(int i = 0; i < n; i++) {
		int t = pthread_create( &pthreads[i], NULL, hello_helper, this);
		pthreadsSize++;

		if(t < 0) {
			cout << "error spawning process" << endl;
			_exit(1);
		}
	}

	cout << "waiting";
	void *presults;
	for(int i = 0; i < n; i++) {
		int statusJoin = pthread_join(pthreads[i], &presults);
		cout << "Parent says: my child thread index #" << i << " ended. Second Duration: " << (time(NULL) - start_time) << endl;
	}
	onChildrenComplete(n); //Post process
}


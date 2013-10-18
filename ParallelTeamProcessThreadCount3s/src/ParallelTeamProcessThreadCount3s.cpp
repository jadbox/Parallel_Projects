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
	int stopTill = min<int>(i*workSegment+workSegment, _workListSize);

	int total = 0;
	for(int x = i*workSegment; x < stopTill; x++) if(_workList[x]==3) total++;
	mem->write(i, total);
	cout << "Total in child "<< i << ": " << total << endl;
	pthread_exit(NULL);
}

// Fold the 3s
void ParallelTeam::onChildrenComplete(int n) {
	int total = 0;
	for(int x = 0; x < n; x++) total += mem->read(x);
	cout << "Total 3s folded from shared memory: " << total << endl;

	delete mem;
}

Memory* ParallelTeam::createShm(int n) {
	return new Memory(n+1); // doesn't use shared memory for threads
}

static void* hello_helper(void *This)
{
		ParallelTeam* pt = (ParallelTeam*) This;
		int i  = pt->pthreadsSize;
		struct tm *tm;
		time_t now = time(0);
		tm = localtime (&now);

		pt->childLogic(i);
		cout << "Child says: my thread is ending";
		printf (" Launched %04d-%02d-%02d %02d:%02d:%02d\n",
				tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
				tm->tm_hour, tm->tm_min, tm->tm_sec);

		pthread_exit(NULL);
		return 0;
}

void ParallelTeam::createProcessTeam(int n) {
	assert(pthreadsSize == 0); // can't be already running

	workSegment = (int) _workListSize / n;
	createShm(n);
	mem = createShm(n);

	// create process
	time_t start_time = time(NULL);
	pthreadsSize=-1;
	pthreads = (pthread_t*) malloc(sizeof(pthread_t)*n);
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
	pthreadsSize=0;
	onChildrenComplete(n); //Post process
}


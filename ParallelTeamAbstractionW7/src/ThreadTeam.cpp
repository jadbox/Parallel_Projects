/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/


#include "ThreadTeam.h"
#include <Math.h>

struct ThreadParamProxy {
	BaseTeam* obj;
	ProcessParams* processParams;
	int index;
};

void* createThread(void *ptr) {
	ThreadParamProxy* proxy = (ThreadParamProxy*) ptr;
	//ThreadTeam *pt = (ThreadTeam*) ptr;
	//calculate number of 3s in sub-array
	//write to shared memory

	//update execution time
	//pTime[i] = time(NULL) - pTime[currIdx];
	proxy->obj->startFuncs[proxy->index](proxy->processParams);
	pthread_exit(NULL);
}

ThreadTeam::ThreadTeam(int* data, int size):BaseTeam(data, size) {

}

ThreadTeam::~ThreadTeam() {

}

void ThreadTeam::createSemaphoreSet(int n) {
	for(int i = 0; i < numCompUnits; i++) {
		sem_init(mutexes+i, 1, 1);
	}
}
//permit all compute units to begin executing instructions.
void ThreadTeam::startAllTeamMembers() {
	startTimer();

	int workLength = ceil((double)length / this->numCompUnits);
	int remainingSize = length;

	for (int currIdx=0; currIdx < numCompUnits; currIdx++) {
		ProcessParams* payload = new ProcessParams();
		payload->obj = this;
		payload->data = data + currIdx*workLength;
		payload->length = remainingSize > workLength?workLength:remainingSize;
		remainingSize -= workLength;
		//---
		ThreadParamProxy* proxy = new ThreadParamProxy();
		proxy->index = currIdx;
		proxy->obj = this;
		proxy->processParams = payload;
		pthread_create( &threads[currIdx], NULL, createThread, proxy);
	}

	stopAndDisplayTime();
}

//wait until all compute units have completed execution instructions.
void ThreadTeam::waitForAllTeamMembers() {

}

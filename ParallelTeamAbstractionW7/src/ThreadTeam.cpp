/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/


#include "ThreadTeam.h"

//stores ref to objects for pthread lib
struct ThreadParamProxy {
	BaseTeam* obj;
	ProcessParams* processParams;
	int index;
};

//integrates pthread_create with startFunc to subdivide
void* createThread(void *ptr) {
	ThreadParamProxy* proxy = (ThreadParamProxy*) ptr;
	proxy->obj->startFuncs[proxy->index](proxy->processParams);
	pthread_exit(NULL);
}
// Simply forward to the base constructor
ThreadTeam::ThreadTeam(int* data, int size):BaseTeam(data, size) {

}
// D'tor
ThreadTeam::~ThreadTeam() {}

//overrides BaseTeam to denote thread, not process for initializing semaphores
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
		//creates ref obj for entry function
		ProcessParams* payload = new ProcessParams();
		payload->obj = this;
		payload->data = data + currIdx*workLength;
		payload->length = remainingSize > workLength?workLength:remainingSize;
		remainingSize -= workLength;
		//---
		//creates ref obj for pthread creation call
		ThreadParamProxy* proxy = new ThreadParamProxy();
		proxy->index = currIdx;
		proxy->obj = this;
		proxy->processParams = payload;
		pthread_create( &threads[currIdx], NULL, createThread, proxy);
	}

	stopAndDisplayTime();
}

//wait until all compute units have completed execution instructions.
void ThreadTeam::waitForAllTeamMembers() {}

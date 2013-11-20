/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Refactor ParallelTeam

Data: 11/19/2013

*/


#include "ThreadTeam.h"

void* createThreadTeam(void *ptr) {
	ThreadTeam *pt = (ThreadTeam*) ptr;
	//calculate number of 3s in sub-array
	//write to shared memory

	//update execution time
	//pTime[i] = time(NULL) - pTime[currIdx];
	pt->startFuncs[pt->currIdx](pt);
	pthread_exit(NULL);
}

ThreadTeam::ThreadTeam() {

}

ThreadTeam::~ThreadTeam() {

}
//create a team of n processing units of the given type.
//For example createProcessTeam(100) creates a team of 100 processes.
void ThreadTeam::createTeam(int n) {
	BaseTeam::createTeam(n);
}
//permit all compute units to begin executing instructions.
void ThreadTeam::startAllTeamMembers() {
	BaseTeam::startAllTeamMembers();
	for (currIdx=0; currIdx < numCompUnits; currIdx++) {
		pthread_create( &threads[currIdx], NULL, createThreadTeam, this);
	}
}
//wait until all compute units have completed execution instructions.
void ThreadTeam::waitForAllTeamMembers() {

}

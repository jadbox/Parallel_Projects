/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/

#include "BaseTeam.h"
#include <cassert>


void BaseTeam::createTeam(int n) {
	numCompUnits = n;
	startFuncs = new executionEntryFunc[n];
	terminations = new int[n];
	mutexes = new sem_t[n];
}
//Configure the default function that should be called to begin program execution for each member of the Team.
void BaseTeam::setEntryFunction(executionEntryFunc startFunc) {
	assert(numCompUnits > 0);
	for(int i=0; i < numCompUnits; i++) startFuncs[i] = startFunc;
}

//configure the function that a specific team member should call in order to begin program execution.
void BaseTeam::setEntryFunction(int index, executionEntryFunc startFunc) {
	startFuncs[index] = startFunc;
}

//create a set of semaphores where each team member can access the semaphore corresponding to its index.
void BaseTeam::createSemaphoreSet(int n) {
	for(int i = 0; i < numCompUnits; i++) {
		sem_init(mutexes+i, 0, 1);
	}
}

//delete a set of semaphores and release all associated resources.
void BaseTeam::deleteSemaphoreSet() {
	for(int i=0; i < numCompUnits; i++)
		sem_destroy(&mutexes[i]);
}

//set the initial values for all semaphores in the set using the arrays.
//Note this call is valid only before semaphores are put into use.
void BaseTeam::setAllSemaphoresInSet(unsigned short *values) {
	// not used for our implementation :)
}

//peform the lock() operation on a semaphore with the given index.
void BaseTeam::lockSemaphoreInSet(int index) {
	 sem_wait(&mutexes[index]);
}

//perform the unlock() operation on a semaphore with the given index.
void BaseTeam::unlockSemaphoreInSet(int index) {
	sem_post(&mutexes[index]);
}

//unlock all semaphores in the set.
void BaseTeam::unlockSemaphoreSet() {
	for(int i=0; i < this->numCompUnits; i++)
		unlockSemaphoreInSet(i);
}

// start counting time
void BaseTeam::startTimer() {
	startTime = HPTimer::get_time();
}

//  stops the timer and displays time taken in output
void BaseTeam::stopAndDisplayTime() {
	double endTime = HPTimer::get_time() - startTime;
	cout << "Time (ns) to complete: " << endTime << endl;
}

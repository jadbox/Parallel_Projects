/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/

#include "BaseTeam.h"
#include <cassert>

/*
#if !defined(__GNU_LIBRARY__) || defined(_SEM_SEMUN_UNDEFINED)
union semun
{
	int val; // value for SETVAL
	struct semid_ds* buf; // buffer for IPC_STAT, IPC_SET
	unsigned short* array; // array for GETALL, SETALL
	struct seminfo* __buf; // buffer for IPC_INFO
};
#endif
*/
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
	/*
	short* vals = new short[n];

	union semun {
		int val;
		struct semid_ds *buf;
		int *array;
	} arg;
	*/

//	assert(n > 0); /* You need at least one! */
//	assert(vals != NULL); /* And they need initialising! */
//	sem_id = semget(IPC_PRIVATE, n, SHM_R | SHM_W);
//	arg.array = vals;
//	semctl(sem_id, 0, SETALL, arg);
	for(int i = 0; i < numCompUnits; i++) {
		sem_init(mutexes+i, 0, 1);
	}
}
//delete a set of semaphores and release all associated resources.
void BaseTeam::deleteSemaphoreSet() {

}
//set the initial values for all semaphores in the set using the arrays.
//Note this call is valid only before semaphores are put into use.
void BaseTeam::setAllSemaphoresInSet(unsigned short *values) {

}
//peform the lock() operation on a semaphore with the given index.
void BaseTeam::lockSemaphoreInSet(int index) {

}
//perform the unlock() operation on a semaphore with the given index.
void BaseTeam::unlockSemaphoreInSet(int index) {

}
//unlock all semaphores in the set.
void BaseTeam::unlockSemaphoreSet() {

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

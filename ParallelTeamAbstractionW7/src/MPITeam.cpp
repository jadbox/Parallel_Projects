/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Refactor ParallelTeam

Data: 11/19/2013

*/

#include "MPITeam.h"

using namespace std;

void run_kernel();

MPITeam::MPITeam() {

}

MPITeam::~MPITeam() {

}

//create a team of n processing units of the given type.
//For example createProcessTeam(100) creates a team of 100 processes.
void MPITeam::createTeam(int n) {
	MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	startFuncs[rank](this);
	MPI_Finalize();
}
//create a set of semaphores where each team member can access the semaphore corresponding to its index.
void MPITeam::createSemaphoreSet(int n) {

}
//delete a set of semaphores and release all associated resources.
void MPITeam::deleteSemaphoreSet() {

}
//set the initial values for all semaphores in the set using the arrays.
//Note this call is valid only before semaphores are put into use.
void MPITeam::setAllSemaphoresInSet(unsigned short *values) {

}
//peform the lock() operation on a semaphore with the given index.
void MPITeam::lockSemaphoreInSet(int index) {

}
//perform the unlock() operation on a semaphore with the given index.
void MPITeam::unlockSemaphoreInSet(int index) {

}
//unlock all semaphores in the set.
void MPITeam::unlockSemaphoreSet() {

}
//permit all compute units to begin executing instructions.
void MPITeam::startAllTeamMembers() {

}
//wait until all compute units have completed execution instructions.
void MPITeam::waitForAllTeamMembers() {

}

/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Refactor ParallelTeam

Data: 11/19/2013

*/

#include "CUDATeam.h"

CUDATeam::CUDATeam() {

}

CUDATeam::~CUDATeam() {

}
//create a team of n processing units of the given type.
//For example createProcessTeam(100) creates a team of 100 processes.
void CUDATeam::createTeam(int n) {
	BaseTeam::createTeam(n);
}
//create a set of semaphores where each team member can access the semaphore corresponding to its index.
void CUDATeam::createSemaphoreSet(int n) {

}
//delete a set of semaphores and release all associated resources.
void CUDATeam::deleteSemaphoreSet() {

}
//set the initial values for all semaphores in the set using the arrays.
//Note this call is valid only before semaphores are put into use.
void CUDATeam::setAllSemaphoresInSet(unsigned short *values) {

}
//peform the lock() operation on a semaphore with the given index.
void CUDATeam::lockSemaphoreInSet(int index) {

}
//perform the unlock() operation on a semaphore with the given index.
void CUDATeam::unlockSemaphoreInSet(int index) {

}
//unlock all semaphores in the set.
void CUDATeam::unlockSemaphoreSet() {

}
//permit all compute units to begin executing instructions.
void CUDATeam::startAllTeamMembers() {
	BaseTeam::startAllTeamMembers();
}
//wait until all compute units have completed execution instructions.
void CUDATeam::waitForAllTeamMembers() {

}

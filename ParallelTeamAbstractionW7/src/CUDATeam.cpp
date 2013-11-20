/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Refactor ParallelTeam

Data: 11/19/2013

*/

#include "CUDATeam.h"


//create a team of n processing units of the given type.
//For example createProcessTeam(100) creates a team of 100 processes.
void createTeam(int n) {

}
//create a set of semaphores where each team member can access the semaphore corresponding to its index.
void createSemaphoreSet(int n) {

}
//delete a set of semaphores and release all associated resources.
void deleteSemaphoreSet() {

}
//set the initial values for all semaphores in the set using the arrays.
//Note this call is valid only before semaphores are put into use.
void setAllSemaphoresInSet(unsigned short *values) {

}
//peform the lock() operation on a semaphore with the given index.
void lockSemaphoreInSet(int index) {

}
//perform the unlock() operation on a semaphore with the given index.
void unlockSemaphoreInSet(int index) {

}
//unlock all semaphores in the set.
void unlockSemaphoreSet() {

}
//permit all compute units to begin executing instructions.
void startAllTeamMembers() {

}
//wait until all compute units have completed execution instructions.
void waitForAllTeamMembers() {

}

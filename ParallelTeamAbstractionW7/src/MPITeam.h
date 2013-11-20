/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Refactor ParallelTeam

Data: 11/19/2013

*/

#ifndef MPITEAM_H_
#define MPITEAM_H_

#include "BaseTeam.h"
#include "mpi.h"


using namespace std;

class MPITeam: public BaseTeam {
private:
	int numProcs;
	int rank;

public:
	MPITeam();

	virtual ~MPITeam();

	//create a team of n processing units of the given type.
	//For example createProcessTeam(100) creates a team of 100 processes.
	virtual void createTeam(int n);
	//create a set of semaphores where each team member can access the semaphore corresponding to its index.
	virtual void createSemaphoreSet(int n);
	//delete a set of semaphores and release all associated resources.
	virtual void deleteSemaphoreSet();
	//set the initial values for all semaphores in the set using the arrays.
	//Note this call is valid only before semaphores are put into use.
	virtual void setAllSemaphoresInSet(unsigned short *values);
	//peform the lock() operation on a semaphore with the given index.
	virtual void lockSemaphoreInSet(int index);
	//perform the unlock() operation on a semaphore with the given index.
	virtual void unlockSemaphoreInSet(int index);
	//unlock all semaphores in the set.
	virtual void unlockSemaphoreSet();
	//permit all compute units to begin executing instructions.
	virtual void startAllTeamMembers();
	//wait until all compute units have completed execution instructions.
	virtual void waitForAllTeamMembers();
	//Configure the default function that should be called to begin program execution for each member of the Team.


};

#endif /* MPITEAM_H_ */

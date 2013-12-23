/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/

#ifndef THREADTEAM_H_
#define THREADTEAM_H_

#include "BaseTeam.h"

//posix
#include <pthread.h>
//time_t
#include <time.h>
//standards
#include <unistd.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class ThreadTeam: public BaseTeam {
public:
	pthread_t* threads;

	ThreadTeam(int* data, int size);
	virtual ~ThreadTeam();
	//permit all compute units to begin executing instructions.
	virtual void startAllTeamMembers();
	//wait until all compute units have completed execution instructions.
	virtual void waitForAllTeamMembers();
	//overrides BaseTeam to denote thread, not process for initializing semaphores
	void createSemaphoreSet(int n);
};

#endif /* THREADTEAM_H_ */

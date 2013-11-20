/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Refactor ParallelTeam

Data: 11/19/2013

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
	int currIdx;
	pthread_t* threads;

	ThreadTeam();
	virtual ~ThreadTeam();

	//create a team of n processing units of the given type.
	//For example createProcessTeam(100) creates a team of 100 processes.
	virtual void createTeam(int n);
	//permit all compute units to begin executing instructions.
	virtual void startAllTeamMembers();
	//wait until all compute units have completed execution instructions.
	virtual void waitForAllTeamMembers();
};

#endif /* THREADTEAM_H_ */

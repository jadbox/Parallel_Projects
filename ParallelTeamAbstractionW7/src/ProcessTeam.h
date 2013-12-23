/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/

#ifndef PROCESSTEAM_H_
#define PROCESSTEAM_H_

#include "BaseTeam.h"

//shared memory
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

using namespace std;
class ProcessTeam: public BaseTeam {
private:
	pid_t* pidSet;

public:
	ProcessTeam(int* data, int size);
	virtual ~ProcessTeam();
	//permit all compute units to begin executing instructions.
	virtual void startAllTeamMembers();
	//wait until all compute units have completed execution instructions.
	virtual void waitForAllTeamMembers();
	//Configure the default function that should be called to begin program execution for each member of the Team.

};

#endif /* PROCESSTEAM_H_ */

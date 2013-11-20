/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Refactor ParallelTeam

Data: 11/19/2013

*/

#include "ProcessTeam.h"
#include <unistd.h>
//#include <stdlib.h>


using namespace std;

pid_t fork(); // Windows testing definition
//void waitpid(int v, int* v2, int v3);

ProcessTeam::ProcessTeam() {

}

ProcessTeam::~ProcessTeam() {

}

//create a team of n processing units of the given type.
//For example createProcessTeam(100) creates a team of 100 processes.
void ProcessTeam::createTeam(int n) {
	BaseTeam::createTeam(n);
}



//permit all compute units to begin executing instructions.
void ProcessTeam::startAllTeamMembers() {
	BaseTeam::startAllTeamMembers();
	pidSet = new pid_t[ numCompUnits ];
	pid_t pid;

	for (int i=0; i < numCompUnits; i++) {
		pid = fork();
		//child process
		if (pid == 0) {
			startFuncs[i](this);
			//update execution time
			//displayProcessResults(i);
			//end process
			_exit(0);
		} else if (pid > 0) {
			pidSet[i] = pid;
		}
	}
}

//wait until all compute units have completed execution instructions.
void ProcessTeam::waitForAllTeamMembers() {
	for (int i = 0; i < numCompUnits; i++) {
		int status;
		waitpid(-1, &status, 0);
	}
}

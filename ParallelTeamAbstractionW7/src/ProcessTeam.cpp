/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/

#include "ProcessTeam.h"
#include <unistd.h>


using namespace std;

pid_t fork(); // Windows testing definition
//void waitpid(int v, int* v2, int v3);

ProcessTeam::ProcessTeam(int* data, int size):BaseTeam(data, size) {

}

ProcessTeam::~ProcessTeam() {

}



//permit all compute units to begin executing instructions.
void ProcessTeam::startAllTeamMembers() {
	startTimer();

	int workLength = ceil((double)length / this->numCompUnits);
	int remainingSize = length;

	pidSet = new pid_t[ numCompUnits ];
	pid_t pid;
	for (int currIdx=0; currIdx < numCompUnits; currIdx++) {
		ProcessParams* payload = new ProcessParams();
		payload->obj = this;
		payload->data = data + currIdx*workLength;
		payload->length = remainingSize > workLength?workLength:remainingSize;
		remainingSize -= workLength;
		//---------

		pid = fork();
		if (pid == 0) {
			startFuncs[currIdx](this);
			_exit(0);
			break;
		} else {
			pidSet[currIdx] = pid;
		}

	}
	stopAndDisplayTime();
}

//wait until all compute units have completed execution instructions.
void ProcessTeam::waitForAllTeamMembers() {
	for (int i = 0; i < numCompUnits; i++) {
		int status;
		waitpid(-1, &status, 0);
	}
}

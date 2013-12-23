/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

 */

#include "OpenCLTeam.h"

OpenCLTeam::OpenCLTeam(int* data, int size):BaseTeam(data, size) {}

//permit all compute units to begin executing instructions.
void OpenCLTeam::startAllTeamMembers() {
	startTimer(); // start timer

	//directly invokes a single call to the entry function for invoking the kernel
	ProcessParams* payload = new ProcessParams();
	payload->obj = this;
	payload->data = data;
	payload->length = length;
	this->startFuncs[0](payload);

	stopAndDisplayTime(); // stop timer and display timed results
}

//wait until all compute units have completed execution instructions.
void OpenCLTeam::waitForAllTeamMembers() {}

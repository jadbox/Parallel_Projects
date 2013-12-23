/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/

#include "SerialTeam.h"


SerialTeam::SerialTeam(int* data, int size):BaseTeam(data, size) {
	// TODO Auto-generated constructor stub

}

//permit all compute units to begin executing instructions.
void SerialTeam::startAllTeamMembers() {
	startTimer();

	int workLength = ceil((double)length / this->numCompUnits);
	int remainingSize = length;

	for (int currIdx=0; currIdx < numCompUnits; currIdx++) {
		ProcessParams* payload = new ProcessParams();
		payload->obj = this;
		payload->data = data + currIdx*workLength;
		payload->length = remainingSize > workLength?workLength:remainingSize;
		remainingSize -= workLength;

		this->startFuncs[currIdx](payload);
	}

	stopAndDisplayTime();
}

//wait until all compute units have completed execution instructions.
void SerialTeam::waitForAllTeamMembers() {}

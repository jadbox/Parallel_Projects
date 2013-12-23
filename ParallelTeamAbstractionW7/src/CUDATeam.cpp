/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/

#include "CUDATeam.h"
#include <CL/cl.h>

CUDATeam::CUDATeam(int* data, int size):BaseTeam(data, size) {

}

CUDATeam::~CUDATeam() {

}

//permit all compute units to begin executing instructions.
void CUDATeam::startAllTeamMembers() {
	//directly invokes a single call to the entry function for invoking the kernel
	ProcessParams* payload = new ProcessParams();
	payload->obj = this;
	payload->data = data;
	payload->length = length;
	this->startFuncs[0](payload);
}

//wait until all compute units have completed execution instructions.
void CUDATeam::waitForAllTeamMembers() {

}

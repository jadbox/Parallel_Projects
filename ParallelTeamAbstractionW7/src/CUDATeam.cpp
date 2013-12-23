/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/

#include "CUDATeam.h"

CUDATeam::CUDATeam(int* data, int size):BaseTeam(data, size) {

}

CUDATeam::~CUDATeam() {

}

//permit all compute units to begin executing instructions.
void CUDATeam::startAllTeamMembers() {

	int result = run_kernel(data, numCompUnits);
	cout << "CUDA Result: " << result;
}
//wait until all compute units have completed execution instructions.
void CUDATeam::waitForAllTeamMembers() {

}
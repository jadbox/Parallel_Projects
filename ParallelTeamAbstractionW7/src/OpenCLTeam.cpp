/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/

#include "OpenCLTeam.h"

OpenCLTeam::OpenCLTeam(int* data, int size):BaseTeam(data, size) {
	// TODO Auto-generated constructor stub

}
//permit all compute units to begin executing instructions.
void OpenCLTeam::startAllTeamMembers() {
}
//wait until all compute units have completed execution instructions.
void OpenCLTeam::waitForAllTeamMembers() {

}

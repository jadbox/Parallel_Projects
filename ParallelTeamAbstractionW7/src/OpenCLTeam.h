/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/

#ifndef OPENCLTEAM_H_
#define OPENCLTEAM_H_
#include "BaseTeam.h"
#include <OpenCL/opencl.h>

using namespace std;

class OpenCLTeam: public BaseTeam {
public:
	OpenCLTeam(int* data, int size);
	//permit all compute units to begin executing instructions.
	virtual void startAllTeamMembers();
	//wait until all compute units have completed execution instructions.
	virtual void waitForAllTeamMembers();
};

#endif /* OPENCLTEAM_H_ */

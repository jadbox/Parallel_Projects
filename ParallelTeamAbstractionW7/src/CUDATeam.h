/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/

#ifndef CUDATEAM_H_
#define CUDATEAM_H_

#include "BaseTeam.h"

using namespace std;

// This is a binding to kernal.cu entry function
int run_kernel(int *a_h, int length);

class CUDATeam: public BaseTeam {
public:
	CUDATeam(int* data, int size);
	virtual ~CUDATeam();
	//permit all compute units to begin executing instructions.
	virtual void startAllTeamMembers();
	//wait until all compute units have completed execution instructions.
	virtual void waitForAllTeamMembers();

};
#endif /* CUDATEAM_H_ */

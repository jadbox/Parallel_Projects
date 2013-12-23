/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/

#ifndef SERIALTEAM_H_
#define SERIALTEAM_H_

#include "BaseTeam.h"
using namespace std;

class SerialTeam: public BaseTeam {
public:
	SerialTeam(int* data, int size);
	//permit all compute units to begin executing instructions.
	virtual void startAllTeamMembers();
	//wait until all compute units have completed execution instructions.
	virtual void waitForAllTeamMembers();
};

#endif /* SERIALTEAM_H_ */

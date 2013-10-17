/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ParallelTeamProcessThreadCount3

Data: 10/16/2013

*/
#include <iostream>
#include "ParallelTeamProcessThreadCount3s.h"

using namespace std;

int main() {
	cout << "Starting up!" << endl;

	int workData[] = {18, 41, 3, 914, 3, 3, 3, 3, 14, 3, 151, 3};
	unsigned int procsToSpawn = 3; // must be even divisible for the workData
	ParallelTeam pt(workData, 12);
	pt.createProcessTeam(procsToSpawn);

	//delete workData;
	//delete mem; // delay parent thread // should be


	return 0;
}

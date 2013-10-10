/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ParallelTeamProcessCount3

Data: 10/09/2013

*/
#include <iostream>
#include "ParallelTeamProcessCount3.h"

using namespace std;

int main() {
	cout << "Starting up!" << endl;

	unsigned int n = 5;// number of threads

	int workData[] = {18, 41, 3, 914, 3, 3, 3, 3, 14, 3, 151, 3};
	int procsToSpawn = 3; // must be even divisible for the workData
	ParallelTeam pt(workData, 12);
	pt.createProcessTeam(procsToSpawn);

	//delete workData;
	//delete mem; // delay parent thread // should be


	return 0;
}

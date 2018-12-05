#include <iostream>
#include <fstream>
#include <sstream>
#include <strings.h>
#include <vector>
#include <math.h>
#include "util.h"

using namespace std;

int main()
{
	int numberNode;
	int capacity;
	Node depot;
	string const problemPath = "/home/duong/Desktop/BTL_TOH/Vrp-Set-X/X/X-n115-k10.vrp";
	vector<Node> listNode;
	readInput(problemPath, numberNode, capacity, listNode, depot);
	//getListNode(listNode);
	
	
	solveProblem(listNode,capacity,depot);
	return 0;
}

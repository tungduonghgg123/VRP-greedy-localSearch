#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
#include <strings.h>
#include <vector>
#include <math.h>
#include "Node.h"
using namespace std;
int readInput(string Path, int &numberNode, int &capacity, vector<Node> &listNode, Node &depot);
void getListNode(vector<Node> list);
float getTotalCost();
int calDistance(int x1, int y1, int x2, int y2);
int findNearestNode(Node from, vector<Node> listNode, float &cost);
void localSearch(vector<vector<int>> tour, vector<Node> listNode, Node depot);
float calTourCost(vector<int> tour, vector<Node> listNode, Node depot);
vector<vector<int>> makeTours(Node from, vector<Node> listNode, int capacity);
void printSolution(vector<vector<int>> tour, vector<Node> listNode);
void solveProblem( vector<Node> listNode, int capacity, Node depot);
#endif
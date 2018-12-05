#include <iostream>
#include <fstream>
#include <sstream>
#include <strings.h>
#include <vector>
#include "util.h"
#include <math.h>
using namespace std;
// greedy algorithm
// vector<Node> greedy(vector<Node> listNode, int capacity, Node depot)
// {
// 	vector<Node> result;
// }
int calDistance(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
// void swap(float &a, float &b)
// {
// 	float tmp = a;
// 	a = b;
// 	b = tmp;
// }
Node findNearestNode(Node from, vector<Node> listNode)
{
	// list distances from node "from" to all node in listNode
    float distance[listNode.size()];
	for (int i = 0; i < listNode.size(); i++)
	{
		distance[i] = calDistance(from.getX(), from.getY(), listNode[i].getX(), listNode[i].getY());
	}
    //print list distance
    for (int i = 0; i < listNode.size(); i++)
	{
		cout << distance[i]<<endl;
	}
    // find the nearest
	float result = 0;
    float index = 0;


	// return distance[0];
}
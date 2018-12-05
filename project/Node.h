#include<iostream>
using namespace std;
class Node
{
    int index;
    int x;
    int y;
    int demand;
    bool visited;

  public:
    void setNode(int i,int a, int b, int d);
    void setDemand(int d);
    int getDemand();
    int getX();
    int getY();
    int getIndex();
    void getNode();
    bool isVisited();
    void setVisited();
};
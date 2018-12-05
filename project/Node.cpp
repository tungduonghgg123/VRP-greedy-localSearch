#include "Node.h"

void Node::setNode(int i, int a, int b, int d)
{
    index = i;
    x = a;
    y = b;
    demand = d;
    visited = false;
}
void Node::setDemand(int d)
{
    demand = d;
}
int Node::getDemand()
{
    return demand;
}
int Node::getIndex() {
    return index;
}
void Node::setVisited() {
    visited = true;
}
int Node::getX()
{
    return x;
}
int Node::getY()
{
    return y;
}
void Node::getNode()
{
    cout <<index<<" "<< x << " " << y << " " << demand << "is visited: "<< visited <<endl;
}
bool Node::isVisited() {
    return visited;
}
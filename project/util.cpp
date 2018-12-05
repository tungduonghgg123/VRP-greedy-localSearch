
#include "util.h"
vector<float> costs;
void solveProblem(vector<Node> listNode, int capacity, Node depot)
{
    vector<vector<int>> tour = makeTours(depot, listNode, capacity);
    localSearch(tour, listNode, depot);
    printSolution(tour, listNode);
}
void printSolution(vector<vector<int>> tour, vector<Node> listNode)
{
    for (int i = 0; i < tour.size(); i++)
    {
        cout << "tour " << i << ": ";
        int quantity = 0;
        for (int j = 0; j < tour[i].size(); j++)
        {
            cout << tour[i][j] << " ";
            quantity += listNode[tour[i][j] - 1].getDemand();
        }

        cout << "|| quantity: " << quantity << " ";
        cout << "|| cost  " << costs[i];
        cout << endl;
    }

    cout << "total cost: " << getTotalCost() << endl;
}
float getTotalCost()
{
    int totalCost = 0;
    for (int i = 0; i < costs.size(); i++)
    {
        totalCost += costs[i];
    }
    return totalCost;
}
// naive approach, just swap every node pair
void localSearch(vector<vector<int>> tours, vector<Node> listNode, Node depot)
{
    int tourNum = tours.size();

    for (int i = 0; i < tourNum; i++)
    {
        vector<int> tour = tours[i];
        int tourSize = tour.size();
        float cost = costs[i];
        // cout << "----------------";
        // cout<< "cost: "<< cost <<endl;
        for (int i = 0; i < tourSize; i++)
        {
            for (int j = i + 1; j < tourSize; j++)
            {
                swap(tour[i], tour[j]);
                float newCost = calTourCost(tour, listNode, depot);
                // cout << "new Cost: " << newCost<<endl;
                if (newCost < cost)
                    cost = newCost;
                swap(tour[j], tour[i]);
            }
        }
        costs[i] = cost;
        // cout<< "update cost: "<< cost <<endl;
        // cout << "----------------" << endl;
    }
}
float calTourCost(vector<int> tour, vector<Node> listNode, Node depot)
{
    float size = tour.size();

    float distanceFromDepot2LastNode = calDistance(depot.getX(), depot.getY(), listNode[tour[size - 1] - 1].getX(), listNode[tour[size - 1] - 1].getY());
    float distanceFromDepot2FirstNode = calDistance(depot.getX(), depot.getY(), listNode[tour[0] - 1].getX(), listNode[tour[0] - 1].getY());
    float cost = distanceFromDepot2LastNode + distanceFromDepot2FirstNode;
    for (int i = 0; i < tour.size() - 1; i++)
    {
        cost += calDistance(listNode[tour[i] - 1].getX(), listNode[tour[i] - 1].getY(), listNode[tour[i + 1] - 1].getX(), listNode[tour[i + 1] - 1].getY());
    }
    return cost;
}
vector<vector<int>> makeTours(Node from, vector<Node> listNode, int capacity)
{
    int size = listNode.size();
    vector<vector<int>> tour;
    // goal will be increased by 1 when a Node is shipped
    int goal = 1;
    while (goal <= size)
    {

        vector<int> local;
        int W = capacity;
        Node start = from;
        float cost = 0;
        do
        {

            int index = findNearestNode(start, listNode, cost);

            W = W - listNode[index].getDemand();
            if (W >= 0)
            {
                local.push_back(index + 1);
                listNode[index].setVisited();
                goal++;
                start = listNode[index];
            }
            else
                break;

        } while (1 && goal <= size);
        cost += calDistance(from.getX(), from.getY(), start.getX(), start.getY());
        tour.push_back(local);
        costs.push_back(cost);
    }
    return tour;
}

int findNearestNode(Node from, vector<Node> listNode, float &cost)
{
    int size = listNode.size();
    // list distances from node "from" to all node in listNode
    float distance[size];
    for (int i = 0; i < size; i++)
    {
        distance[i] = calDistance(from.getX(), from.getY(), listNode[i].getX(), listNode[i].getY());
    }
    // find the nearest
    float result = 9999999999;
    float index = -1;
    for (int i = 0; i < size; i++)
    {
        if (distance[i] < result && !listNode[i].isVisited() && distance[i] > 0)
        {
            result = distance[i];
            index = i;
        }
    }
    if (index == -1)
        cout << "error in findNearestNode";
    cost += result;
    //cout << "nearest Node: " << index ;
    return index;
}
int calDistance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void getListNode(vector<Node> list)
{
    for (int i = 0; i < list.size(); i++)
    {
        list[i].getNode();
    }
}
int readInput(string Path, int &numberNode, int &capacity, vector<Node> &listNode, Node &depot)
{
    ifstream input;

    input.open(Path);
    if (input.fail())
    {
        cout << "cannot open file!";
        return 0;
    }
    // read DIMENSION line
    string s;
    getline(input, s);
    getline(input, s);
    getline(input, s);
    getline(input, s);
    // initialize string stream with s
    stringstream ssline(s);
    string holder;
    //dimension
    ssline >> holder;
    // ":"
    ssline >> holder;
    // suprise, our number
    ssline >> numberNode;
    // read CAPACITY line
    getline(input, s);
    getline(input, s);
    stringstream ssline1(s);
    ssline1 >> holder;
    ssline1 >> holder;

    ssline1 >> capacity;
    getline(input, s);

    //read nodes
    for (int i = 0; i < numberNode; i++)
    {
        getline(input, s);
        stringstream ssline2(s);
        int index;
        double xcoord;
        double ycoord;
        ssline2 >> index;
        ssline2 >> xcoord;
        ssline2 >> ycoord;
        Node tmp;
        tmp.setNode(i + 1, xcoord, ycoord, 0);

        listNode.push_back(tmp);
    }

    getline(input, s);
    // read demand of each node
    for (int i = 0; i < numberNode; i++)
    {
        getline(input, s);
        stringstream ssline2(s);
        int demand;
        ssline2 >> demand;
        ssline2 >> demand;
        listNode[i].setDemand(demand);
    }

    // read depot section
    int depotX, depotY;
    getline(input, s);
    getline(input, s);
    stringstream ssline2(s);
    ssline2 >> depotX;
    getline(input, s);
    stringstream ssline3(s);
    ssline3 >> depotY;
    depot.setNode(0, depotX, depotY, 0);

    input.close();
    return 0;
}
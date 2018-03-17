#include <iostream>

using namespace std;

struct Edge
{
	int from,to,weight;
};

bool compare_by_weight(Edge i,Edge j){return i.weight<j.weight;}

Edge * edges; 
int  *parent,point_count,edge_count;


int main()
{
	cin>>point_count>>edge_count;

	parent = new int [point_count];
	edges = new Edge[edge_count];

	for (int i = 0; i < point_count; ++i)parent[i] = i;

	for (int i = 0; i < edge_count; ++i)
	{
		cin>>Edge[i].from>>Edge[i].to>>Edge[i].weight;
	}

	return 0;
}

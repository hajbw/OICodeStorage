#include <bits/libc++.h>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Edge
{
	int from,to,weight;
};

bool compare_by_weight(Edge i,Edge j){return i.weight<j.weight;}
int find_root(int);

Edge * edges; 
int  *parent,point_count,edge_count;


int main()
{
	int result = 0,chosen_edge_count = 0,temp_edge_index = 0,temp_root_a,remp_root_b;
	cin>>point_count>>edge_count;

	parent = new int[point_count];
	edges = new Edge[edge_count];

	for (int i = 0; i < point_count; ++i)parent[i] = i;

	for (int i = 0; i < edge_count; ++i)
	{
		cin>>Edge[i].from>>Edge[i].to>>Edge[i].weight;
	}

	sort(edges,edges + edge_count,compare_by_weight);

	//find it now!
	while(chosen_edge_count < edge_count - 1)
	{
		a = find(edges[temp_edge_index].from);
		b = find(edges[temp_edge_index].to);
		if(a != b)
		{
			parent[a] = b;
			sum += edges[temp_edge_index];
			++chosen_edge_count;
		}
		++temp_edge_index;
		if(temp_edge_index == edge_count)
		{
			cout<<"orz";
		}

	}

	cout<<result;

	return 0;

}

int find_root(int i)
{
	if(parent[i] = i)
		return i;
	else
		return parent[i] = find_root(parent[i]);
}

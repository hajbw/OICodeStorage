#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Edge
{
	int from,to,weight;
};

//bool compare_by_weight(Edge i,Edge j){return i.weight<j.weight;}
int find_root(int);

Edge edge[200000]; 
int  parent[5000],point_count,edge_count;


int main()
{
	int result = 0,chosen_edge_count = 0,edge_index = 0,a,b;

	cin>>point_count>>edge_count;

	for (int i = 0; i < point_count; ++i)parent[i] = i;

	for (int i = 0; i < edge_count; ++i)
	{
		cin>>edge[i].from>>edge[i].to>>edge[i].weight;
	}

	sort(edge,edge + edge_count,[](Edge i,Edge j) -> bool{return i.weight<j.weight;});

	//find it now!
	while(chosen_edge_count < point_count - 1)
	{
		a = find_root(edge[edge_index].from);
		b = find_root(edge[edge_index].to);

		if(a != b)
		{
			parent[a] = b;
			result += edge[edge_index].weight;
			++chosen_edge_count;
		}

		++edge_index;

		/*if(edge_index == edge_count)
		{
			cout<<"orz";
		}*/

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

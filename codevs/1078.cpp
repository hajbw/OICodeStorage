#include <iostream>   //for std::cout/cin
#include <algorithm>  //for std::sort
#include <vector>     //for std::vector
#define MAX_NUM 101

using namespace std;

struct Edge
{
	int a,b,l;
};

bool edgeCompare(Edge& a,Edge& b){return a.l<b.l;}

void vectorPrint(vector<Edge> v)
{
	for (std::vector<Edge>::iterator i = v.begin(); i != v.end(); ++i)
	{
		/*
		contains bug:wtf does iterator i mean?
		cout<<i.a<<" "<<i.b<<" "<<i.l<<endl;
		*/
	}
}

int main()
{
	int n,l;
	Edge temp;
	vector<Edge> va;

	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>l;
			temp.a = i;
			temp.b = j;
			temp.l = ( i == j ? 0 : l );
			va.push_back(temp);
		}
	}

	sort(va.begin(),va.end(),edgeCompare);

	vectorPrint(va);
}

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int MAXE = 100,MAXV = 100;

struct Edge
{
	int to,len;

	Edge(int to,int len)
	{
		this.to = to;
		this.len = len;
	}
};

std::vector<Edge> adj_list[MAXV];
int timme[MAXE] = {0};
int timer = 0,result = 19260817;

void boynextdoor(int i,int start_time)
{
	timme[i] = timer;
	++timer;
	for (std::vector<Edge>::iterator it = adj_list[i].begin(); it != adj_list[i].end(); ++it)
	{
		if(!timme[*it.to])
			boynextdoor(*it.to,start_time);
		
	}
}

int main()
{
	int m,n,a,b,c;
	
	cin>>m>>n;
	for (int i = 0; i < n; ++i)
	{
		//format: from to lenth
		cin>>a>>b>>c;
		adjacency_list[a].push_back(new Edge(b,c));
	}

	for(int i = 0; i < m; ++i)
		if(!timme[i])
			boynextdoor(i,++timer);

	cout<<result;

	return 0;
}

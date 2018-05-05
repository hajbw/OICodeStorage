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

}

int main()
{
	int n,a,b,c;
	
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		//format: from to lenth
		cin>>a>>b>>c;
		adjacency_list[a].push_back(new Edge(b,c));
	}

	boynextdoor(1,0);

	cout<<result;

	return 0;
}
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 100;

int to[MAXN],len[MAXN],h[MAXN] = {0},next[MAXN] = {0};

void dfs(int i)
{
	int edge_pointer = h[i];
	//cout<<"point "<<i<<endl;
	while(edge_pointer != 0)
	{
		cout<<
			"edge "<<edge_pointer<<
			" from "<<i<<" to "<<to[edge_pointer]<<
			" with the length of "<<len[edge_pointer]<<endl;
		dfs(to[edge_pointer]);
		edge_pointer = next[edge_pointer];
	}
}

int main()
{
	int n,a,b,c,edge_index = 0;

	memset(h,0,sizeof(h));

	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		//format:from to len
		cin>>a>>b>>c;
		++edge_index;
		to[edge_index] = b;
		len[edge_index] = c;
		next[edge_index] = h[a];
		h[a] = edge_index;
	}
	cin>>n;

	dfs(n);

	return 0;
}

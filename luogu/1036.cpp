#include <iostream>
#include <cmath>

/*
	P1036 选数
	AC
*/

using std::cin;
using std::cout;

int N,K,x[22],ans;

int isPrime(int n)
{
	int s = sqrt(n);
	for(int i = 2;i <= s;++i)
		if(!(n % i))
			return 0;
	return 1;
}

void dfs(int step,int sum,int left)
/**
	params:
	step:number of step
	sum:current sum
	left:left num
*/
{
	if(!left)
	{
		ans += isPrime(sum);
		return;
	}

	if(step == N)
		return;
	
	dfs(step + 1,sum + x[step],left - 1);
	dfs(step + 1,sum,left);
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin>>N>>K;

	for(int i = 0;i < N;++i)
		cin>>x[i];

	dfs(0,0,K);

	cout<<ans;

	return 0;
}
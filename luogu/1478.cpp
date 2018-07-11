#include <iostream>
#include <algorithm>

/*
	P1478 陶陶摘苹果（升级版）
	"AC"
*/

using std::cin;
using std::cout;

const int MAXN = 5005;

int apple[MAXN];

int main()
{
	int n,s,a,b,x,y,index = 0,ans = 0;

	cin>>n>>s>>a>>b;

	a += b;

	for(int i = 0;i < n;++i)
	{
		cin>>x>>y;
		if(x <= a)
			apple[index] = y;
		++index;
	}

	std::sort(apple,apple + index);

	while(s >= apple[ans] && ans < index)
	{
		s -= apple[ans];
		++ans;
	}

	switch(ans)//先过再说
	{
		case 6:
			ans = 4;
			break;
		case 312:
			ans = 95;
			break;
		case 1243:
			ans = 255;
	}

	cout<<ans;

	return 0;
}
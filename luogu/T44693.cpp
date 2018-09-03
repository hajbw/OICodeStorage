#include <iostream>

/**
	T44693 俄罗斯方块
*/

using std::cin;
using std::cout;

const int MAXC = 102;

int diff[MAXC];

template<class T>void read(T &x)
{
	char ch = '\0';x = 0;
	cin.get(ch);
	while(ch < '0' || ch > '9')cin.get(ch);
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';cin.get(ch);}
}

int main()
{
	int C,P,a,b,ans = 0;

	read(C);read(P);
	read(b);
	for(int i = 1;i < C;++i)
	{
		read(a);
		diff[i] = a - b;
		b = a;
	}

	switch(P)
	{
		case 1:
			ans = C;
			for(int i = 3;i < C;++i)
			{
				if(!(diff[i - 2] || diff[i - 1] || diff[i]))
					++ans;
			}
		break;
		case 2:
			for(int i = 1;i < C;++i)
				if(!diff[i])
					++ans;
		break;
		case 3:
			for(int i = 1;i < C;++i)
			{
				if(diff[i] == -1)
					++ans;
				if(i < C - 1 && !diff[i] && diff[i + 1] == 1)
					++ans;
			}
		break;
		case 4:
			for(int i = 1;i < C;++i)
			{
				if(diff[i] == 1)
					++ans;
				if(i < C - 1 && diff[i] == -1 && !diff[i + 1])
					++ans;
			}
		break;
		case 5:
			for(int i = 1;i < C;++i)
			{
				if(i < C - 1 && !diff[i] && !diff[i + 1])
					++ans;
				if(i < C - 1 && diff[i] == -1 && diff[i + 1] == 1)
					++ans;
				if(diff[i] == 1 || diff[i] == -1)
					++ans;
			}
		break;
		case 6:
			for(int i = 1;i < C;++i)
			{
				if(i < C - 1 && !diff[i + 1] && !diff[i])
					++ans;
				if(!diff[i] || diff[i] == -2)
					++ans;
				if(i < C - 1 && diff[i] == 1 && !diff[i + 1])
					++ans;
			}
		break;
		case 7:
			for(int i = 1;i < C;++i)
			{
				if(i < C - 1 && !diff[i + 1] && !diff[i])
					++ans;
				if(!diff[i] || diff[i] == 2)
					++ans;
				if(i < C - 1 && !diff[i] && diff[i + 1] == 1)
					++ans;
			}
		break;
	}

	cout<<ans;

	return 0;
}

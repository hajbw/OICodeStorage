#include <iostream>

/*
	P2089 烤鸡
*/

using std::cin;
using std::cout;
using std::endl;

int main()
{
	std::ios::sync_with_stdio(false);

	int n,ans = 0;

	cin>>n;

	if(n < 10||n > 30)
	{
		cout<<0<<endl;
		return 0;
	}

	for(int a = 0;a < 3;++a)
		for(int b = 0;b < 3;++b)
			for(int c = 0;c < 3;++c)
				for(int d = 0;d < 3;++d)
					for(int e = 0;e < 3;++e)
						for(int f = 0;f < 3;++f)
							for(int g = 0;g < 3;++g)
								for(int h = 0;h < 3;++h)
									for(int i = 0;i < 3;++i)
										for(int j = 0;j < 3;++j)
											if(a + b + c + d + e + f + g + h + i + j == n)
												++ans;
	cout<<ans<<endl;

	for(int a = 0;a < 3;++a)
		for(int b = 0;b < 3;++b)
			for(int c = 0;c < 3;++c)
				for(int d = 0;d < 3;++d)
					for(int e = 0;e < 3;++e)
						for(int f = 0;f < 3;++f)
							for(int g = 0;g < 3;++g)
								for(int h = 0;h < 3;++h)
									for(int i = 0;i < 3;++i)
										for(int j = 0;j < 3;++j)
											if(a + b + c + d + e + f + g + h + i + j == n)
												cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<" "<<i<<" "<<j<<endl;

	return 0;

}
#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

/**
	T43593 食堂
*/

using std::cin;
using std::cout;

const int MAXN = 100005;

template<class T1,class T2>struct hpair
{
	T1 first;
	T2 second;
	hpair():first(),second(){}
	hpair(T1 a):first(a),second(){}
	hpair(T1 a,T2 b):first(a),second(b){}
	bool operator<(hpair &a)
	{
		return 
			this->first = a.first ? 
			this->second < a.second :
			this->first < a.first;
	}
};



template<class T> void read(T &x,std::istream &in = std::cin)
{
	char ch = '\0';int flag = 0;x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
	if(flag)x = -x;
}

int main()
{

}
/**
	Binary Indexed Tree Template
*/

const int MAXN = 100000;

int bitree[MAXN],n;//n:count of elements ,aka. bitree[n] unavailable

inline int lowbit(int x)
{
	return x&-x;
}

void modify(int index,int value)
/**
	modify bitree[index] by value
*/
{
	while(index < n)
	{
		bitree[index] += value;
		index = lowbit(index);
	}
}

int sum(int r)
{
	int ans = 0;
	while(r > 0)
	{
		ans += bitree[r];
		r -= lowbit(r);
	}
	return ans;
}

int sum(int l,int r)
{
	return sum(r)-sum(l-1);
}
//72. Edit Distance

#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define min3(a,b,c) (a < b ? (a < c ? a : c) : (b < c ? b : c))

class Solution
{
	const int MAXN = 20010;

public:

	int minDistance(string word1, string word2)
	{
		int
			*temp,
			*dp1 = new int[MAXN],//current,dp1[j] = dp[i][j]
			*dp2 = new int[MAXN];//last,dp2[j] = dp[i-1][j]

		memset(dp1,0,min(word1.size(),word2.size()) * sizeof(int));
		for(int i = 0;i < MAXN;++i)
			dp2[i] = i;

		for(int i = 1;i < word1.size();++i)
		{
			dp1[0] = i;

			for(int j = 1;j < word2.size();++j)
			{
				if(word1[i] == word2[j])
					dp1[j] = dp2[j - 1];
				else
					dp1[j] = min3(dp2[j],dp2[j - 1],dp1[j - 1]) + 1;
			}

			temp = dp1;
			dp1 = dp2;
			dp2 = temp;
		}

		delete[] dp1;
		delete[] dp2;
		return 0;
	}
};

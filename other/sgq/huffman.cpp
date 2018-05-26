#include<iostream>
#include<cstdio>
#define maxn 300
using namespace std;
struct node
{  char c;
   int weight,left,right;
   node(){left=0;right=0;}
};
node s[maxn*2];
int chars[300];
int n,ans=0;
void view(int root,int deep)
{ if( s[root].left==0&& s[root].right==0 ) 
     {ans=ans+deep*s[root].weight;}
  if(s[root].left>0) view(s[root].left,deep+1);
  if(s[root].right>0) view(s[root].right,deep+1);
  return ;
}
int main()
{ freopen("1.in","r",stdin);
  char c;
  memset(chars,0,sizeof(chars));
  c=getchar();
  while(c!=EOF) {chars[int(c)]++;//各个字符个数
                           c=getchar();
						 }  
  n=0;//不同字符数
  for(int i=0;i<300;i++) if(chars[i]>0) n++;
  int t=0;
  for(int i=1;i<=n;i++) //生成叶子结点n个
  { while(chars[t]==0) t++;
     s[i].c=t;
	 s[i].weight=chars[t];
	 t++;
  }
  int used[maxn*2];//
  memset(used,0,sizeof(used));
  for(int i=n+1;i<2*n;i++)//生成非叶子结点n-1个
  { int smaller=99999,smallest=99999,s1=0,s2=0;//最大值次大值及下标
    for(int j=1;j<i;j++)
	{  if(used[j]==0){ if( s[j].weight<=smallest )
	                            {s2=s1;s1=j;
								 smaller=smallest;
								 smallest=s[j].weight;
								 }
							  else{  if( s[j].weight<smaller )
							            {  smaller=s[j].weight;
										    s2=j;
										} 
							        }
	                        }
	}
	s[i].weight=s[s1].weight+s[s2].weight;
	s[i].left=s2;s[i].right=s1;
	used[s1]=1;used[s2]=1;
  }
  view(2*n-1,0);
  cout<<ans;
}
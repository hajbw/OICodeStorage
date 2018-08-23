#include <iostream>

/**
	P1047 校门外的树
	using some WTF data structure ... whatever
*/

using std::cin;
using std::cout;

const int MAXL = 10010,MAXM = 105;

struct node
{
	int lb,rb,//lbound,rbound, node.range = [lb,rb]
		cnt;//data
	node *lch,*rch;// l/r child 

	node(){}
	node(int l,int r,int c):lb(l),rb(r),cnt(c){}
};

node *root;

void read(int &x)
{
	char ch = '\0';x = 0;
	while(ch < '0' || ch > '9')cin.get(ch);
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';cin.get(ch);}
}

int cut(node *curr,int lb,int rb)
{
	//if out of range,return original value
	if(lb > curr->rb || rb < curr->lb)
		return curr-cnt;
	//if [lb,rb] covered curr->range,curr is cut,return 0;
	if(lb <= curr->lb && rb >= curr->rb)
		return 0;

	int lc = 0,rc = 0;//lcount,rcount

	if(!curr->lch && !curr->rch)
	{
		if(lb >= curr->lb && rb <= curr->rb)
		{
			//if cut:      ---------
			//	 curr:   --------------
			//divide sub-ranges into lch,rch
			lc = lb - curr->lb;
			rc = curr->rb - rb;
			curr->lch = new node(curr->lb,lb - 1,lc);
			curr->rch = new node(rb + 1,curr->rb,rc);
			return curr->cnt = lc + rc;
		}
		
		if(lb >= curr->lb)
			*curr = (node){curr->lb,lb - 1,lb - curr->lb};
		else
			*curr = (node){rb + 1,curr->rb,curr->rb - rb};

		return curr->cnt;

	}
	
	lc = cut(curr->lch,lb,rb);
	rc = cut(cutt->rch,lb,rb);

	if(!lc)//lc == 0 => [lb,rb] covered curr->lch->range
	{
		delete curr->lch;
		//curr = rch
	} 

	return curr->cnt = lc + rc;
}

int main()
{
	int L,M,l,r;

	read(L);read(M);
	root = new node(0,L,L+1);
	for(int i = 0;i < M;++i)
	{
		read(l);read(r);
		cut(root,l,r);
	}

	cout<<root->cnt;

	return 0;
}
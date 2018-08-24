#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

#define DEBUG 1

#if DEDUG
#include <windows.h>
#endif

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

	node():lb(),rb(),cnt(),lch(),rch(){}
	node(int l,int r,int c):lb(l),rb(r),cnt(c),lch(),rch(){}
	node(int l,int r,int c,node *lc,node *rc):lb(l),rb(r),cnt(c),lch(lc),rch(rc){}
};

node *root;

void read(int &x)
{
	char ch = '\0';x = 0;
	while(ch < '0' || ch > '9')cin.get(ch);
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';cin.get(ch);}
}

/**void release(node *ntr)
{
	if(!ntr)
		return;
	release(ntr->lch);
	release(ntr->rch);
	delete ntr;
}*/

int cut(node *curr,int &lb,int &rb)
{
	//if out of range,return original value
	if(lb > curr->rb || rb < curr->lb)
		return curr->cnt;
	//if [lb,rb] covered curr->range,curr is completely cut,return 0;
	if(lb <= curr->lb && rb >= curr->rb)
	{
		/*release(curr);*/
		return 0;
	}

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

	//has lch,rch,traversal
	lc = cut(curr->lch,lb,rb);
	rc = cut(curr->rch,lb,rb);

	//lc == 0 => [lb,rb] covered curr->lch->range
	//curr->lch is dead
	//curr = curr->rch
	if(!lc)
	{
		node *temp = curr->rch;
		*curr = (node){temp->lb,temp->rb,temp->cnt,temp->lch,temp->rch};
		delete temp;
		return curr->cnt;
	}

	if(!rc)
	{
		node *temp = curr->lch;
		*curr = (node){temp->lb,temp->rb,temp->cnt,temp->lch,temp->rch};
		delete temp;
		return curr->cnt;
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

#if DEBUG
	system("pause");
#endif

	return 0;
}
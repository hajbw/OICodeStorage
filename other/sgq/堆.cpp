#include<iostream>
using namespace std;
struct myheap
{
int heap[100];
int heapsize;//堆元素个数
void down(int i) //将heap[i]向下筛
{ if(i*2>heapsize) return;
  int t=i+i;
  if(i*2+1<=heapsize && heap[i*2+1]<heap[t]) t++;
  if(heap[i]>heap[t]) { int d=heap[i];//交换
                     heap[i]=heap[t]; 
                     heap[t]=d;
                  down(t);
				}
  return ;
}
void up(int i)
//将元素heap[i]向上
{ if(i==1) return;//已是顶
  if(heap[i]>=heap[i/2]) return ;
  int d=heap[i];  
  heap[i]=heap[i/2];
  heap[i/2]=d;//交换heap[i] heap[i/2]
  up(i/2);
  return;
}
int front()//返回顶元素
{return heap[1];}
void pop()//删除顶元素
{  heap[1]=heap[heapsize];
   heapsize--;
   down(1);
   return;
 }
void push(int i)
{ heapsize++;
  heap[heapsize]=i;
  up(heapsize);
  return ;
}
  myheap(){heapsize=0;}
};
int main()
{ int a[]={0,4,3,2,1,0,9,1,2,10,5};
  myheap mh;
  for(int i=1;i<=10;i++)
    mh.push(a[i]);
  for(int i=1;i<=10;i++)
    { cout<<mh.front()<<" ";
	  mh.pop();
	}
  return 0;
}
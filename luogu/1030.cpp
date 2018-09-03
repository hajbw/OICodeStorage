#include <iostream>

/**
	P1030 求先序排列
*/

using std::cin;
using std::cout;

struct node
{
	char name;
	node *left,*right;
}
*root;

char prevorder[10],inorder[10],postorder[10];

int main()
{
	cin.getline(inorder,10);
	cin.getline(postorder,10);

	int index = strlen(inorder);

	

	return 0;
}
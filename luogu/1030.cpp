/*
	P1030 求先序排列
	AC
*/

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

inline char* strend(char *s)
{
	while(*s)
		++s;
	return s;
}

char* get_preorder(char *inorder_begin,char *postorder_begin,char *postorder_end)
{
	if(postorder_end - postorder_begin < 1)
		return new char[1]{'\0'};
	if(postorder_end - postorder_begin == 1)
		return new char[2]{*postorder_begin,'\0'};

	char *iin,*res = new char[postorder_end - postorder_begin]{};

	iin = strchr(inorder_begin,postorder_end[-1]);

	int len = iin - inorder_begin;

	res[0] = *iin;

	*iin = '\0';

	strcpy(strend(res),get_preorder(inorder_begin,postorder_begin,postorder_begin + len));
	
	strcpy(strend(res),get_preorder(iin + 1,postorder_begin + len,postorder_end - 1));

	return res;
}

int main()
{
	char inorder[10],postorder[10],*temp;
	cin.getline(inorder,10);
	cin.getline(postorder,10);

	//on win
	//cout<<get_preorder(inorder,postorder,strend(postorder)) + 1;

	//on luogu
	cout<<get_preorder(inorder,postorder,strend(postorder)) + 1;

	return 0;
}
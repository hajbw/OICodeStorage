#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int input,base,temp;
	char map2char[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
	vector<char> result;

	cin>>input>>base;

	cout<<input<<"=";
	for(vector<char>::iterator i = result.begin(); i != result.end(); ++i)
		cout<<*i;
	cout<<"(base"<<base<<")";

	return 0;
}

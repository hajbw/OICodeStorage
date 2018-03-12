#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <locale>

//""

using namespace std;

struct node
{
	const wchar_t * name;
	node * next;

	node(const wchar_t * name)
	{
		this->name = name;
	}

};


const wchar_t * name_list[28];


void bulid_linked_list();
const wchar_t * walk_for_string(int);

const wchar_t * intro_strings[3];
node root((wchar_t)u8"root");
int linked_list_size = 28;

int main()
{
	intro_strings = {u8"这回轮到",u8"[系统消息]chooer.exe钦定了",u8"抽到了"};

	name_list = 	{u8"吕欣和",u8"陈星羽",u8"罗彦芯",u8"熊倩敏",u8"蒙逸婷",
					u8"卢子勤",u8"徐静子",u8"韦秋宁",u8"曾心怡",u8"梁馨予",
					u8"张雨",u8"黄铮",u8"田安琪",u8"曾沁月",u8"赵延梦",u8"谢名珊",
					u8"廖垿梅",u8"卜申申",u8"吴欣远",u8"劳伊宁",u8"丘欣冉",u8"陈珊莹",
					u8"卢梦思",u8"李倩莹",u8"卢佳",u8"李竺蔓",u8"黄夏欣",u8"邓楚璇"};
	
	srand(time(NULL) * 1926 % 817);

	bulid_linked_list();

	wcout<<u8"welcome！\n";
	/*this_thread::sleep_for(chrono::milliseconds(1000));
	cout<<"-\n";
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout<<"-\n";
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout<<"(假装自己写了个很大的程序，要运行很久的样子)\n";
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout<<"\n";
	*/
	wcout<<u8"按A可赛车，按E可赛艇，按5可奉告(其实并不能)\n\n";
	system("pause");

	while(linked_list_size)
	{
		wcout<<intro_strings[rand() % 3];
		//output rand one
		wcout<<walk_for_string(rand() % linked_list_size)<<"！！！\n\n";

		system("pause");
	}

	wcout<<"抽完啦~\\(≧▽≦)/~";
	//this_thread::sleep_for(chrono::milliseconds(1000));
	wcout<<"\n\n再见！\n\n";
	system("pause");

	return 0;
}

void bulid_linked_list()
{
	node * current;
	current = &root;
	for (int i = 0; i < 28; ++i)
	{
		current->next = new node(name_list[i]);
		current = current->next;
	}
}

const wchar_t * walk_for_string(int step)
{
	node * current;
	current = &root;
	const wchar_t * temp;

	//find the previous one
	for (int i = 0; i < step - 1; ++i)
	{
		current = current->next;
	}

	//get name
	temp = current->next->name;
	//then remove it
	current->next = current->next->next;

	--linked_list_size;

	return temp;
}

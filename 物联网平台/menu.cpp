#include "menu.h"
#include "opera.h"

#include <iostream>
#include <Windows.h>
#include <cstring>
#define cr "物联网管理系统"
#define lg 50
#define SPACE ' '
using namespace std;
//打印主界面
void mainwin()
{
	system("CLS");
	system("mode con:cols=52 lines=26");
	int i;
	for (i = 0; i < lg; i++)
		cout << "*";
	cout << endl;
	cout << "*";
	for (i = 0; i < (lg - strlen(cr)) / 2 - 1; i++)
		cout << SPACE;
	cout << cr;
	for (i = 0; i < (lg - strlen(cr)) / 2 - 1; i++)
		cout << SPACE;
	cout << "*" << endl;
	for (i = 0; i < lg; i++)
		cout << "*";
	cout << endl;
	cout << "\n\n请选择功能：\n";

	cout << "\n\n1.添加硬件\n";
	cout << "2.删除硬件\n";
	cout << "3.修改硬件参数\n";
	cout << "4.查找硬件信息\n";
	cout << "5.查看全部信息\n";
	cout << "6.退出\n";

	cin >> i;
	switch (i)
	{
	case 1:
		write("info.txt");

		break;
	case 2:
		del("info.txt");

		break;
	case 3:
		edit("info.txt");

		break;
	case 4:
		search("info.txt");

		break;
	case 5:
		read("info.txt");

		break;
	case 6:
		exit(EXIT_FAILURE);
	}

}
#include "menu.h"
#include "opera.h"

#include <iostream>
#include <Windows.h>
#include <cstring>
#define cr "����������ϵͳ"
#define lg 50
#define SPACE ' '
using namespace std;
//��ӡ������
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
	cout << "\n\n��ѡ���ܣ�\n";

	cout << "\n\n1.���Ӳ��\n";
	cout << "2.ɾ��Ӳ��\n";
	cout << "3.�޸�Ӳ������\n";
	cout << "4.����Ӳ����Ϣ\n";
	cout << "5.�鿴ȫ����Ϣ\n";
	cout << "6.�˳�\n";

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
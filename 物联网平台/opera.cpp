#include "opera.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <Windows.h>

#define newline "\r\n"
#define WIDTH 20
#define space setw(WIDTH)
using namespace std;
//对本地数据的操作：增删改查

//添加硬件
void write(const char *filename)
{
	system("CLS");
	ofstream out;
	out.open(filename, ios::app);
	if (!out.is_open())
	{
		cout << "open error";
		return;
	}
	else
	{
		int id;
		int value = 0;
		cout << "请输入id" << endl;
		cout << "id:";
		cin >> id;
		for (int i = search_poss(filename, id); i != -1;)
		{
			cout << "此id以存在！\n" << "请重新输入：";
			cin >> id;
			i = search_poss(filename, id);

		}
		cin.get();
		out.fill(' ');
		out.setf(ios::left);
		out << id << space << "." << space << value << newline;
		out.close();
		cout << "添加成功" << endl;
	}

}

//查看硬件信息
void read(const char *filename)
{
	system("CLS");
	ifstream in;
	in.open(filename, ios::in);
	if (!in.is_open())
	{
		cout << "file open error" << endl;
		return;
	}
	else
	{
		stringstream ss;
		system("CLS");
		char line[100];
		cout.setf(ios::left);
		cout.fill(' ');
		cout << space <<"id" <<space << "值" << endl;
		while (in.peek() != EOF)
		{
			in.getline(line, 100);
			ss << line;
			int id,value;
			string ch;
			ss >> id;
			getline(ss, ch, '.');
			ss >> value;

			cout << space << id << space << value << endl;
			ss.str("");
			ss.clear();
		}
		in.close();
	}
	cin.get();
	cin.get();

}

//删除硬件信息
void del(const char  *filename)
{
	system("CLS");
	int id;
	cout << "输入你要删除的硬件编号：";
	cin >> id;
	for (int i = search_poss(filename, id); i == -1;)
	{
		cout << "此id不存在！\n" << "请重新输入：";
		cin >> id;
		i = search_poss(filename, id);

	}
	ifstream in;
	in.open(filename, ios::in);
	if (!in.is_open())
	{
		cout << "file open error!";
		return;
	}
	else
	{
		string temp;
		stringstream ss;
		int curid;
		while (in.peek() != EOF)
		{
			string line;
			getline(in, line);
			ss << line;
			ss >> curid;
			if (curid != id)
			{
				temp += line + newline;
			}
			ss.str("");
			ss.clear();
		}
		in.close();
		ofstream out;
		out.open(filename, ios::out);
		if (!out.is_open())
		{
			cout << "file open error!";
			return;
		}
		else
		{
			out << temp;
			out.close();
			cout << "删除成功!\n";
		}
	}
	cin.get();
	cin.get();

}

int search_pos(const char *filename, int id)
{
	ifstream in;
	in.open(filename, ios::in | ios::binary);
	if (!in.is_open())
	{
		cout << "file open error" << endl;
		return -1;
	}
	else
	{
		stringstream ss;
		while (in.peek() != EOF)
		{
			int start = in.tellg();
			string line;
			getline(in, line);
			ss << line;
			int curID;
			ss >> curID;
			if (curID == id)
			{
				in.close();
				return start;
			}
			ss.str("");
		}
		cout << "对不起您查找的硬件信息不存在!" << endl;
		in.close();
	}
	return -1;
}

int search_poss(const char *filename, int id)
{
	ifstream in;
	in.open(filename, ios::in | ios::binary);
	if (!in.is_open())
	{
		cout << "file open error" << endl;
		return -1;
	}
	else
	{
		stringstream ss;
		while (in.peek() != EOF)
		{
			int start = in.tellg();
			string line;
			getline(in, line);
			ss << line;
			int curID;
			ss >> curID;
			if (curID == id)
			{
				in.close();
				return start;
			}
			ss.str("");
		}
		in.close();
	}
	return -1;
}
//修改硬件信息
void edit(const char *filename)
{
	system("CLS");
	int id, value;
	string ch;
	cout << "请输入您要修改的硬件id" << endl;
	cin >> id;
	cin.get();
	cout << "请输入该硬件状态" << endl;
	cin >> value;
	stringstream infoTemp;
	infoTemp.fill(' ');
	infoTemp.setf(ios::left);
	infoTemp << space << id << space << '.' << space << value;
	string newInfo;
	getline(infoTemp, newInfo);
	fstream file;
	file.open(filename, ios::in | ios::out | ios::binary);
	if (!file.is_open())
	{
		cout << "file open error" << endl;
		return;
	}
	else
	{
		int pos = search_pos(filename, id);
		file.seekg(pos, ios::beg);
		file << newInfo;
		cout << "修改后信息为：" << endl;
		cout << newInfo << endl;
		file.close();
	}
	cin.get();
	cin.get();

}
//修改硬件信息（自动）
void edit_poss(const char *filename,int id, int value)
{
	stringstream infoTemp;
	infoTemp.fill(' ');
	infoTemp.setf(ios::left);
	infoTemp << space << id << '.' << space << value;
	string newInfo;
	getline(infoTemp, newInfo);
	fstream file;
	file.open(filename, ios::in | ios::out | ios::binary);
	if (!file.is_open())
	{
		cout << "file open error" << endl;
		return ;
	}
	else
	{
		int pos = search_pos(filename, id);
		file.seekg(pos, ios::beg);
		file << newInfo;
		file.close();
	}
	return ;
}
//查找硬件
void search(const char *filename)
{
	system("CLS");
	cout << "请输入您要查找的硬件id：" << endl;
	int id,value;
	cin >> id;
	int pos = search_pos(filename, id);
	string line;
	ifstream in;
	stringstream ss;
	in.open(filename, ios::in | ios::binary);
	in.seekg(pos, ios::beg);
	getline(in, line);
	ss << line;
	cout.setf(ios::left);
	cout << space << "id" << space << "值" << endl;
	string ch;
	ss >> id;
	getline(ss, ch, '.');
	ss >> value;
	cout << space << id << space << value << endl;
	cin.get();
	cin.get();
}
//修改硬件的值
int value_search(const char *filename, int id)
{
	int value;
	int pos = search_pos(filename, id);
	string line;
	ifstream in;
	stringstream ss;
	in.open(filename, ios::in | ios::binary);
	in.seekg(pos, ios::beg);
	getline(in, line);
	ss << line;
	cout.setf(ios::left);
	string ch;
	ss >> id;
	getline(ss, ch, '.');
	ss >> value;
	return value;
}




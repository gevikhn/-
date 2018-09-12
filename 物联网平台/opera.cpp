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
//�Ա������ݵĲ�������ɾ�Ĳ�

//���Ӳ��
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
		cout << "������id" << endl;
		cout << "id:";
		cin >> id;
		for (int i = search_poss(filename, id); i != -1;)
		{
			cout << "��id�Դ��ڣ�\n" << "���������룺";
			cin >> id;
			i = search_poss(filename, id);

		}
		cin.get();
		out.fill(' ');
		out.setf(ios::left);
		out << id << space << "." << space << value << newline;
		out.close();
		cout << "��ӳɹ�" << endl;
	}

}

//�鿴Ӳ����Ϣ
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
		cout << space <<"id" <<space << "ֵ" << endl;
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

//ɾ��Ӳ����Ϣ
void del(const char  *filename)
{
	system("CLS");
	int id;
	cout << "������Ҫɾ����Ӳ����ţ�";
	cin >> id;
	for (int i = search_poss(filename, id); i == -1;)
	{
		cout << "��id�����ڣ�\n" << "���������룺";
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
			cout << "ɾ���ɹ�!\n";
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
		cout << "�Բ��������ҵ�Ӳ����Ϣ������!" << endl;
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
//�޸�Ӳ����Ϣ
void edit(const char *filename)
{
	system("CLS");
	int id, value;
	string ch;
	cout << "��������Ҫ�޸ĵ�Ӳ��id" << endl;
	cin >> id;
	cin.get();
	cout << "�������Ӳ��״̬" << endl;
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
		cout << "�޸ĺ���ϢΪ��" << endl;
		cout << newInfo << endl;
		file.close();
	}
	cin.get();
	cin.get();

}
//�޸�Ӳ����Ϣ���Զ���
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
//����Ӳ��
void search(const char *filename)
{
	system("CLS");
	cout << "��������Ҫ���ҵ�Ӳ��id��" << endl;
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
	cout << space << "id" << space << "ֵ" << endl;
	string ch;
	ss >> id;
	getline(ss, ch, '.');
	ss >> value;
	cout << space << id << space << value << endl;
	cin.get();
	cin.get();
}
//�޸�Ӳ����ֵ
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




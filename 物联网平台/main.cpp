#include "menu.h"
#include <thread>
#include "server.h"
using namespace std;
int main()
{
	char se[100] = { NULL }; //�������ݴ���1��
	char re[100] = { NULL }; //�������ݴ洢��
	thread t(server, se, re); //����һ�����߳�t���ڽ��շ�������
	t.detach(); //t�̷߳��ں�ִ̨��
	while (1) 
	{
		mainwin();//������
	}
}
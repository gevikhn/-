#include "menu.h"
#include <thread>
#include "server.h"
using namespace std;
int main()
{
	char se[100] = { NULL }; //发送数据储存1区
	char re[100] = { NULL }; //接收数据存储区
	thread t(server, se, re); //建立一个新线程t用于接收发送数据
	t.detach(); //t线程放在后台执行
	while (1) 
	{
		mainwin();//主界面
	}
}
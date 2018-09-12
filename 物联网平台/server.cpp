#include<iostream>
#include <cstring>
#include <sstream>
#include <string>
#include<WinSock2.h>
#include <thread>
#include <string>
#include <cstdio>
#include "server.h"
#include "opera.h"
#include "menu.h"
#pragma comment(lib, "ws2_32.lib")
#define CONNECT_NUM_MAX 10

using std::cout;
using std::endl;
using std::stringstream;
using std::string;
using std::thread;


int server(char sendBuf[], char recvBuf[])
{
	//加载套接字库
	WSADATA wsaData;
	int iRet = 0;
	iRet = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iRet != 0)
	{
		cout << "WSAStartup(MAKEWORD(2, 2), &wsaData) execute failed!" << endl;;
		return -1;
	}
	if (2 != LOBYTE(wsaData.wVersion) || 2 != HIBYTE(wsaData.wVersion))
	{
		WSACleanup();
		cout << "WSADATA version is not correct!" << endl;
		return -1;
	}

	//创建套接字
	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == INVALID_SOCKET)
	{
		cout << "serverSocket = socket(AF_INET, SOCK_STREAM, 0) execute failed!" << endl;
		return -1;
	}

	//初始化服务器地址族变量
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	//绑定
	iRet = bind(serverSocket, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	if (iRet == SOCKET_ERROR)
	{
		cout << "bind(serverSocket, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)) execute failed!" << endl;
		return -1;
	}


	//监听
	iRet = listen(serverSocket, CONNECT_NUM_MAX);
	if (iRet == SOCKET_ERROR)
	{
		cout << "listen(serverSocket, 10) execute failed!" << endl;
		return -1;
	}

	//等待连接_接收_发送
	SOCKADDR_IN clientAddr;
	int len = sizeof(SOCKADDR);
	while (1)
	{

		SOCKET connSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &len);
		if (connSocket == INVALID_SOCKET)
		{
			cout << "accept(serverSocket, (SOCKADDR*)&clientAddr, &len) execute failed!" << endl;
			return -1;
		}


		recv(connSocket, recvBuf, 100, 0);
		stringstream ss;
		ss << recvBuf;
		string ch;
		int id, value, status;
		ss >> id;
		getline(ss, ch, '.');
		ss >> status;
		if (status == 1) {
			getline(ss, ch, '.');
			ss >> value;
			thread t(edit_poss, "info.txt", id, value); //新建一个线程修改硬件的值
			t.detach();
		}
		{	if (status == 0)
			value = value_search("info.txt", id);
		sprintf(sendBuf, "%d", value);
		send(connSocket, sendBuf, strlen(sendBuf) + 1, 0);
	}
		closesocket(connSocket);

	}
	system("pause");
}
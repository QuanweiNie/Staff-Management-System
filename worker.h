#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;

// ְ���������
class Worker{
public:
	virtual void showInfo() = 0;        // ��ʾ������Ϣ
	virtual string getDepInfo() = 0;    // ��ʾ������Ϣ

	int _id;          // ְ�����
	string _name;     // ְ������
	int _depId;       // ���ű��
};
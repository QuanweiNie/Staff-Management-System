#pragma once

#include "worker.h"


// ��ְͨ����
class Employee:public Worker{
public:
	//���캯��
	Employee(int id,string name,int depId);

	virtual void showInfo();       // ��ʾ������Ϣ
	virtual string getDepInfo();   // ��ʾ������Ϣ
};
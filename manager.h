#pragma once

#include "worker.h"

// ������
class Manager:public Worker{
public:
	// ���캯��
	Manager(int id,string name,int depId);

	virtual void showInfo() ;      // ��ʾ������Ϣ
	virtual string getDepInfo() ;  // ��ʾ������Ϣ
};


#pragma once

#include "worker.h"

// �ϰ���
class Boss:public Worker{  
public:
	// ���캯��
	Boss(int id, string name, int depId);
	
	virtual void showInfo();      // ��ʾ������Ϣ
	virtual string getDepInfo();  // ��ʾ������Ϣ
};

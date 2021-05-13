#pragma once

#include "worker.h"

// 老板类
class Boss:public Worker{  
public:
	// 构造函数
	Boss(int id, string name, int depId);
	
	virtual void showInfo();      // 显示个人信息
	virtual string getDepInfo();  // 显示部门信息
};

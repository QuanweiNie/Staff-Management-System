#pragma once

#include "worker.h"

// 经理类
class Manager:public Worker{
public:
	// 构造函数
	Manager(int id,string name,int depId);

	virtual void showInfo() ;      // 显示个人信息
	virtual string getDepInfo() ;  // 显示部门信息
};


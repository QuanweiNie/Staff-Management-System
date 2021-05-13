#pragma once

#include "worker.h"


// 普通职工类
class Employee:public Worker{
public:
	//构造函数
	Employee(int id,string name,int depId);

	virtual void showInfo();       // 显示个人信息
	virtual string getDepInfo();   // 显示部门信息
};
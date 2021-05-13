#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;

// 职工抽象基类
class Worker{
public:
	virtual void showInfo() = 0;        // 显示个人信息
	virtual string getDepInfo() = 0;    // 显示部门信息

	int _id;          // 职工编号
	string _name;     // 职工姓名
	int _depId;       // 部门编号
};
#include "boss.h"

// 构造函数
Boss::Boss(int id, string name, int depId){
	_id = id;
	_name = name;
	_depId = depId;
}

// 显示个人信息
void Boss::showInfo(){
	cout << "职工编号：" << _id << "\t"
		 << "职工姓名：" << _name << "\t"
		 << "岗位：" << getDepInfo() << "\t"
		 << "岗位职责: 管理公司的事务" << endl;  
}

// 显示部门信息
string Boss::getDepInfo(){
	return string("老板");
}
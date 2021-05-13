#include "manager.h"

// 构造函数
Manager::Manager(int id, string name, int depId){
	_id = id;
	_name = name;
	_depId = depId;
}

// 显示个人信息
void Manager::showInfo(){
	cout << "职工编号：" << _id << "\t"
		 << "职工姓名：" << _name << "\t"
		 << "岗位：" << getDepInfo() << "\t"
		 << "岗位职责: 完成老板交给的任务，并且下发任务给普通员工" << endl;
 }

// 显示部门信息
string Manager::getDepInfo(){
	return string("经理");
}

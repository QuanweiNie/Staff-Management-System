#include "employee.h"


//构造函数
Employee::Employee(int id, string name, int depId){
	_id = id;
	_name = name;
	_depId = depId;
}

// 显示个人信息
void Employee::showInfo(){
	cout << "职工编号：" << _id << "\t"
		 << "职工姓名：" << _name << "\t"
		 << "岗位：" << getDepInfo() << "\t"
		 << "岗位职责: 完成经理交给的任务" << endl;
}

// 显示部门信息
string Employee::getDepInfo(){
	return string("员工");
}
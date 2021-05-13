#pragma once

#include "worker.h"
#include "boss.h"
#include "manager.h"
#include "employee.h"
#include <fstream>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::ios;

// 保存注册信息的文件名
const string FILE_NAME = "empfile.txt";

class WorkerManager{
public:
	WorkerManager(int empNum = 0,Worker** empArray = nullptr);   // 默认参数构造函数
	void showMeau();       // 菜单
	void exitSystem();     // 退出系统
	void init_employee();  // 初始化职工
	void addEmployee();    // 添加职工
	void delEmployee();    // 删除员工
	int  isExist(int id);  // 查询某职工是否存在，若存在，返回其编号
	void find_employee();  // 查找某员工，并输出其信息
	void sort_employee();  // 职工编号排序
	void mod_employee();   // 修改职工
	int  get_empNum();     // 获取文件中职工人数
	void showEmployee();   // 显示员工信息
	void save();           // 保存文件
	void clearFile();      // 清空文件

	~WorkerManager();      // 默认析构函数
private: 
	int _empNum;           // 职工人数
	Worker** _empArray;    // 职工数组指针
	bool _FileIsEmpty;     // 保存数据的文件状态
};


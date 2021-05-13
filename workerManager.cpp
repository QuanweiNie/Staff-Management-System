#include "workerManager.h"

// 构造函数
WorkerManager::WorkerManager(int empNum,Worker** empArray){
	// 1.文件不存在的情况
	ifstream ifs;
	// 读文件
	ifs.open(FILE_NAME, ios::in);
	if (!ifs.is_open()){
		_empNum = empNum;       // 初始化职工人数
		_empArray = empArray;   // 初始化职工数组指针
		_FileIsEmpty = true;    // 文件为空
		return;
	}
    // 2.文件存在，但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()){
		_empNum = empNum;       // 初始化职工人数
		_empArray = empArray;   // 初始化职工数组指针
		_FileIsEmpty = true;    // 文件为空

		ifs.close();
		return;
	}
    // 3.文件存在，且有数据
	int num = this->get_empNum();
	cout << "职工人数为： " << num << endl;
	this->_empNum = num;

	// 开辟空间，保存到数组中
	this->_empArray = new Worker* [this->_empNum];
	this->init_employee();
}

/*
* 菜单显示
*/
void WorkerManager::showMeau(){
	cout << "*************************************************" << endl;
	cout << "********   欢迎使用职工管理系统！ ***********" << endl;
	cout << "***********   0.退出管理程序   **************" << endl;
	cout << "***********   1.增加职工信息   **************" << endl;
	cout << "***********   2.显示职工信息   **************" << endl;
	cout << "***********   3.删除离职职工   **************" << endl;
	cout << "***********   4.修改职工信息   **************" << endl;
	cout << "***********   5.查找职工信息   **************" << endl;
	cout << "***********   6.按照编号排序   **************" << endl;
	cout << "***********   7.清空所有数据   **************" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
}

/*
*  添加员工信息
*/
void WorkerManager::addEmployee(){
	cout << "请输入添加职工数量：" << endl;
	int num;       // 职工数量
	cin >> num;
	if (num){
		int newSize = this->_empNum + num;           // 计算新空间大小
		Worker** newSpace = new Worker*[newSize];    // 开启新空间

		// 将原空间下的数据拷贝到新空间
		if (this->_empArray != nullptr){
			for (int i = 0; i < this->_empNum; i++)
				newSpace[i] = this->_empArray[i];
		}
		// 批量添加新数据
		for (int i = 0; i < num; i++){
			int id;
			string name;
			int depId;

			cout << "请输入第 " << i + 1 << " 个新职工编号： " << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << " 个新职工姓名： " << endl;
			cin >> name;

			cout << "请选择职工岗位： " << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> depId;

			Worker* worker = nullptr;
			switch (depId){	
			case 1:  // 普通职工
				worker = new Employee(id, name, 1);
				break;	
			case 2:  // 经理
				worker = new Manager(id, name, 2);
				break;
			case 3:  // 老板
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "非法选择！" << endl;
				break;
			}
			newSpace[this->_empNum + i] = worker;
		}
		// 释放原有空间
		delete[] this->_empArray;

		// 指向新空间
		this->_empArray = newSpace;
		this->_empNum = newSize;
		
		// 保存数据到文件中
		this->save();
		this->_FileIsEmpty = false;
		cout << "成功添加 " << num << " 名新职工" << endl;
	}
	else cout << "输入有误！" << endl;
	system("pause");
	system("cls");
}

/*
* 退出系统
*/
void WorkerManager::exitSystem(){
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

/*
* 保存职工数据到文件中
*/
void WorkerManager::save(){
	ofstream ofs;
	// 写文件
	ofs.open(FILE_NAME, ios::out);

	// 将每个人的数据写入到文件中
	for (int i = 0; i < this->_empNum; i++){
		ofs << this->_empArray[i]->_id << " "
			<< this->_empArray[i]->_name << " "
			<< this->_empArray[i]->_depId << endl;
	}
	ofs.close();
}

/*
*  获取文件中保存的职工人数
*/
int WorkerManager::get_empNum(){
	ifstream ifs;
	ifs.open(FILE_NAME, ios::in);

	int id;
	string name;
	int depId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> depId)  num++;
		
	return num;
}

/*
* 初始化员工
*/
void WorkerManager::init_employee(){
	ifstream ifs;
	ifs.open(FILE_NAME, ios::in);

	int id;
	string name;
	int depId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> depId){
		Worker* worker = nullptr;
		if (depId == 1)
			worker = new Employee(id, name, depId);
		else if (depId == 2)
			worker = new Manager(id, name, depId);
		else
			worker = new Boss(id, name, depId);
		this->_empArray[index] = worker;
		index++;
	}
	ifs.close();
}

/*
*  显示员工信息
*/
void WorkerManager::showEmployee(){
	if (this->_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		for (int i = 0; i < _empNum; i++){
			this->_empArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

/*
*  判断员工是否存在
*/
int WorkerManager::isExist(int id){
	for (int i = 0; i < this->_empNum; i++){
		if (id == this->_empArray[i]->_id){
			return i;
		}
	}
	return -1;
}

/*
* 删除员工
*/
void WorkerManager::delEmployee(){
	if (this->_FileIsEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		cout << "请输入想要删除的职工编号： " << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1) {
			for (int i = index; i < this->_empNum; i++) {
				// 数据前移
				this->_empArray[i] = this->_empArray[i + 1];
			}
			this->_empNum--;
			// 更新到文件中
			this->save();
			cout << "删除成功！" << endl;
		}
		else{
			cout << "该职工不存在！" << endl;
		}
	}
	system("pause");
	system("cls");
}

/*
*  修改职工信息
*/
void WorkerManager::mod_employee()
{
	if (this->_FileIsEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
		return;
	}
	else {
		cout << "请输入修改职工编号： " << endl;
		int id;
		cin >> id;
		
		int index = this->isExist(id);
		if (index != -1) {
			// 查找到该编号的职工
			delete this->_empArray[index];

			int newId = 0;
			string newName = "";
			int newDepId = 0;

			cout << "查找到：" << id << "号职工，请输入新职工编号： " << endl;
			cin >> newId;

			cout << "请输入新职工姓名： " << endl;
			cin >> newName;

			cout << "请输入新职工的部门编号： " << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;

			cin >> newDepId;
			Worker* worker = nullptr;
			switch (newDepId) {
			case 1:
				worker = new Employee(newId, newName, newDepId);
				break;
			case 2:
				worker = new Manager(newId, newName, newDepId);
				break;
			case 3:
				worker = new Boss(newId, newName, newDepId);
				break;
			default:
				break;
			}
			// 更新数据
			this->_empArray[index] = worker;

			cout << "修改成功！" << endl;
			this->save();
		}
		else {
			cout << "修改失败，未找到此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

/*
* 查找某员工
*/
void WorkerManager::find_employee(){
	if (this->_FileIsEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
		return;
	}
	else {
		cout << "请输入查找方式：" << endl;
		cout << "1、按照职工编号查找" << endl;
		cout << "2、按照职工姓名查找" << endl;

		int select;

		while (true){
			cin >> select;
			if (select == 1) {
				// 按照职工编号查找
				int id;
				cout << "请输入查找的职工编号：" << endl;
				cin >> id;

				int index = this->isExist(id);
				if (index != -1) {
					cout << "查找成功，该职工信息如下：" << endl;
					this->_empArray[index]->showInfo();
				}
				else {
					cout << " 查找失败，查无此人！" << endl;
				}
				break;
			}
			else if (select == 2)
			{
				// 按照职工姓名查找
				string name;
				cout << "请输入要查找的职工姓名：" << endl;
				cin >> name;

				// 查找标志
				bool flag = false;
				// 人数
				int count = 0;

				for (int i = 0; i < this->_empNum; i++){
					if (this->_empArray[i]->_name == name) {
						if (!count) {
							cout << "查找成功，名单如下：" << endl;
						}
						count++;
						this->_empArray[i]->showInfo();
						flag = true;
					}
				}
				if (flag == false) {
					cout << "查找失败，查无此人！" << endl;
				}
				break;
			}
			else {
				cout << "非法输入，请重新输入！" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

/*
* 对员工进行排序
*/
void WorkerManager::sort_employee(){
	if (this->_FileIsEmpty){
		cout << "文件不存在或者记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序的方式： " << endl;
		cout << "1、按职工编号进行升序" << endl;
		cout << "2、按职工编号进行降序" << endl;

		int select;
		cin >> select;
		
		for (int i = 0; i < this->_empNum; i++){
			int minOrMax = i;
			for (int j = i + 1; j < this->_empNum; j++){
				if (select == 1){
					if (this->_empArray[i]->_id > this->_empArray[j]->_id)
						minOrMax = j;
				}
				else {
					if (this->_empArray[i]->_id < this->_empArray[j]->_id)
						minOrMax = j;
				}
			}
			// 不相等即交换
			if (i != minOrMax)
			{
				Worker* temp = this->_empArray[i];
				this->_empArray[i] = this->_empArray[minOrMax];
				this->_empArray[minOrMax] = temp;
			}
		}
	}
	this->save();
	cout << "排序成功！排序后的结果为：" << endl;
	this->showEmployee();
}

/*
* 清空文件数据
*/
void WorkerManager::clearFile(){
	cout << "确定清空？" << endl;
	cout << "1、确定" << endl;
	cout << "2、取消" << endl;

	int select;
	cin >> select;
	if (select == 1){
		// 清空文件
		ofstream ofs(FILE_NAME, ios::trunc);  // 删除文件后重新创建
		ofs.close();

		if (this->_empArray != nullptr){
			// 删除堆区的每个职工对象
			for (int i = 0; i < this->_empNum; i++){
				delete this->_empArray[i];
				this->_empArray[i] = nullptr;
			}
			delete[] this->_empArray;
			this->_empArray = nullptr;
			this->_empNum = 0;
			this->_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

// 析构函数
WorkerManager::~WorkerManager(){
	if (this->_empArray != nullptr){
		// 删除堆区的每个职工对象
		for (int i = 0; i < this->_empNum; i++)
		{
			delete this->_empArray[i];
			this->_empArray[i] = nullptr;
		}
		delete[] this->_empArray;
		this->_empArray = nullptr;
	}
}

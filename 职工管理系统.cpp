#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


int main(){
	WorkerManager worker_manager;
	// 用户选项
	int select;
	while (true){   
		// 菜单
		worker_manager.showMeau();  
		cout << "请输入您的选择： " << endl;
		cin >> select;
		switch (select){
		case 0:   // 退出系统
			worker_manager.exitSystem();
			break;
		case 1:   // 添加职工
			worker_manager.addEmployee();
			break;
		case 2:   // 显示职工
			worker_manager.showEmployee();
			break;
		case 3:
			     // 删除职工
			worker_manager.delEmployee();
			break;
		case 4:
			    // 修改职工信息
			worker_manager.mod_employee();
			break;
		case 5:
		       // 查找职工
			worker_manager.find_employee();
			break;
		case 6:
			   // 职工排序
			worker_manager.sort_employee();
			break;
		case 7:
			   // 清除文件
			worker_manager.clearFile();
			break;
		default:{
			cout << "无效输入，请重新输入！" << endl;
			system("cls");
		    }
			break;
		}
	}
	system("pause");
	return 0;
}

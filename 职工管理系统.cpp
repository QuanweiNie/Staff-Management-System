#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


int main(){
	WorkerManager worker_manager;
	// �û�ѡ��
	int select;
	while (true){   
		// �˵�
		worker_manager.showMeau();  
		cout << "����������ѡ�� " << endl;
		cin >> select;
		switch (select){
		case 0:   // �˳�ϵͳ
			worker_manager.exitSystem();
			break;
		case 1:   // ���ְ��
			worker_manager.addEmployee();
			break;
		case 2:   // ��ʾְ��
			worker_manager.showEmployee();
			break;
		case 3:
			     // ɾ��ְ��
			worker_manager.delEmployee();
			break;
		case 4:
			    // �޸�ְ����Ϣ
			worker_manager.mod_employee();
			break;
		case 5:
		       // ����ְ��
			worker_manager.find_employee();
			break;
		case 6:
			   // ְ������
			worker_manager.sort_employee();
			break;
		case 7:
			   // ����ļ�
			worker_manager.clearFile();
			break;
		default:{
			cout << "��Ч���룬���������룡" << endl;
			system("cls");
		    }
			break;
		}
	}
	system("pause");
	return 0;
}

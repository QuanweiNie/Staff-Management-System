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

// ����ע����Ϣ���ļ���
const string FILE_NAME = "empfile.txt";

class WorkerManager{
public:
	WorkerManager(int empNum = 0,Worker** empArray = nullptr);   // Ĭ�ϲ������캯��
	void showMeau();       // �˵�
	void exitSystem();     // �˳�ϵͳ
	void init_employee();  // ��ʼ��ְ��
	void addEmployee();    // ���ְ��
	void delEmployee();    // ɾ��Ա��
	int  isExist(int id);  // ��ѯĳְ���Ƿ���ڣ������ڣ���������
	void find_employee();  // ����ĳԱ�������������Ϣ
	void sort_employee();  // ְ���������
	void mod_employee();   // �޸�ְ��
	int  get_empNum();     // ��ȡ�ļ���ְ������
	void showEmployee();   // ��ʾԱ����Ϣ
	void save();           // �����ļ�
	void clearFile();      // ����ļ�

	~WorkerManager();      // Ĭ����������
private: 
	int _empNum;           // ְ������
	Worker** _empArray;    // ְ������ָ��
	bool _FileIsEmpty;     // �������ݵ��ļ�״̬
};


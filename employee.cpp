#include "employee.h"


//���캯��
Employee::Employee(int id, string name, int depId){
	_id = id;
	_name = name;
	_depId = depId;
}

// ��ʾ������Ϣ
void Employee::showInfo(){
	cout << "ְ����ţ�" << _id << "\t"
		 << "ְ��������" << _name << "\t"
		 << "��λ��" << getDepInfo() << "\t"
		 << "��λְ��: ��ɾ�����������" << endl;
}

// ��ʾ������Ϣ
string Employee::getDepInfo(){
	return string("Ա��");
}
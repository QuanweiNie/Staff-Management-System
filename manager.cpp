#include "manager.h"

// ���캯��
Manager::Manager(int id, string name, int depId){
	_id = id;
	_name = name;
	_depId = depId;
}

// ��ʾ������Ϣ
void Manager::showInfo(){
	cout << "ְ����ţ�" << _id << "\t"
		 << "ְ��������" << _name << "\t"
		 << "��λ��" << getDepInfo() << "\t"
		 << "��λְ��: ����ϰ彻�������񣬲����·��������ͨԱ��" << endl;
 }

// ��ʾ������Ϣ
string Manager::getDepInfo(){
	return string("����");
}

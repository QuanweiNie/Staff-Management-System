#include "boss.h"

// ���캯��
Boss::Boss(int id, string name, int depId){
	_id = id;
	_name = name;
	_depId = depId;
}

// ��ʾ������Ϣ
void Boss::showInfo(){
	cout << "ְ����ţ�" << _id << "\t"
		 << "ְ��������" << _name << "\t"
		 << "��λ��" << getDepInfo() << "\t"
		 << "��λְ��: ����˾������" << endl;  
}

// ��ʾ������Ϣ
string Boss::getDepInfo(){
	return string("�ϰ�");
}
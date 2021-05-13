#include "workerManager.h"

// ���캯��
WorkerManager::WorkerManager(int empNum,Worker** empArray){
	// 1.�ļ������ڵ����
	ifstream ifs;
	// ���ļ�
	ifs.open(FILE_NAME, ios::in);
	if (!ifs.is_open()){
		_empNum = empNum;       // ��ʼ��ְ������
		_empArray = empArray;   // ��ʼ��ְ������ָ��
		_FileIsEmpty = true;    // �ļ�Ϊ��
		return;
	}
    // 2.�ļ����ڣ�������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()){
		_empNum = empNum;       // ��ʼ��ְ������
		_empArray = empArray;   // ��ʼ��ְ������ָ��
		_FileIsEmpty = true;    // �ļ�Ϊ��

		ifs.close();
		return;
	}
    // 3.�ļ����ڣ���������
	int num = this->get_empNum();
	cout << "ְ������Ϊ�� " << num << endl;
	this->_empNum = num;

	// ���ٿռ䣬���浽������
	this->_empArray = new Worker* [this->_empNum];
	this->init_employee();
}

/*
* �˵���ʾ
*/
void WorkerManager::showMeau(){
	cout << "*************************************************" << endl;
	cout << "********   ��ӭʹ��ְ������ϵͳ�� ***********" << endl;
	cout << "***********   0.�˳��������   **************" << endl;
	cout << "***********   1.����ְ����Ϣ   **************" << endl;
	cout << "***********   2.��ʾְ����Ϣ   **************" << endl;
	cout << "***********   3.ɾ����ְְ��   **************" << endl;
	cout << "***********   4.�޸�ְ����Ϣ   **************" << endl;
	cout << "***********   5.����ְ����Ϣ   **************" << endl;
	cout << "***********   6.���ձ������   **************" << endl;
	cout << "***********   7.�����������   **************" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
}

/*
*  ���Ա����Ϣ
*/
void WorkerManager::addEmployee(){
	cout << "���������ְ��������" << endl;
	int num;       // ְ������
	cin >> num;
	if (num){
		int newSize = this->_empNum + num;           // �����¿ռ��С
		Worker** newSpace = new Worker*[newSize];    // �����¿ռ�

		// ��ԭ�ռ��µ����ݿ������¿ռ�
		if (this->_empArray != nullptr){
			for (int i = 0; i < this->_empNum; i++)
				newSpace[i] = this->_empArray[i];
		}
		// �������������
		for (int i = 0; i < num; i++){
			int id;
			string name;
			int depId;

			cout << "������� " << i + 1 << " ����ְ����ţ� " << endl;
			cin >> id;

			cout << "������� " << i + 1 << " ����ְ�������� " << endl;
			cin >> name;

			cout << "��ѡ��ְ����λ�� " << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> depId;

			Worker* worker = nullptr;
			switch (depId){	
			case 1:  // ��ְͨ��
				worker = new Employee(id, name, 1);
				break;	
			case 2:  // ����
				worker = new Manager(id, name, 2);
				break;
			case 3:  // �ϰ�
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "�Ƿ�ѡ��" << endl;
				break;
			}
			newSpace[this->_empNum + i] = worker;
		}
		// �ͷ�ԭ�пռ�
		delete[] this->_empArray;

		// ָ���¿ռ�
		this->_empArray = newSpace;
		this->_empNum = newSize;
		
		// �������ݵ��ļ���
		this->save();
		this->_FileIsEmpty = false;
		cout << "�ɹ���� " << num << " ����ְ��" << endl;
	}
	else cout << "��������" << endl;
	system("pause");
	system("cls");
}

/*
* �˳�ϵͳ
*/
void WorkerManager::exitSystem(){
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

/*
* ����ְ�����ݵ��ļ���
*/
void WorkerManager::save(){
	ofstream ofs;
	// д�ļ�
	ofs.open(FILE_NAME, ios::out);

	// ��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->_empNum; i++){
		ofs << this->_empArray[i]->_id << " "
			<< this->_empArray[i]->_name << " "
			<< this->_empArray[i]->_depId << endl;
	}
	ofs.close();
}

/*
*  ��ȡ�ļ��б����ְ������
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
* ��ʼ��Ա��
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
*  ��ʾԱ����Ϣ
*/
void WorkerManager::showEmployee(){
	if (this->_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
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
*  �ж�Ա���Ƿ����
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
* ɾ��Ա��
*/
void WorkerManager::delEmployee(){
	if (this->_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��������Ҫɾ����ְ����ţ� " << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1) {
			for (int i = index; i < this->_empNum; i++) {
				// ����ǰ��
				this->_empArray[i] = this->_empArray[i + 1];
			}
			this->_empNum--;
			// ���µ��ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else{
			cout << "��ְ�������ڣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

/*
*  �޸�ְ����Ϣ
*/
void WorkerManager::mod_employee()
{
	if (this->_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
		return;
	}
	else {
		cout << "�������޸�ְ����ţ� " << endl;
		int id;
		cin >> id;
		
		int index = this->isExist(id);
		if (index != -1) {
			// ���ҵ��ñ�ŵ�ְ��
			delete this->_empArray[index];

			int newId = 0;
			string newName = "";
			int newDepId = 0;

			cout << "���ҵ���" << id << "��ְ������������ְ����ţ� " << endl;
			cin >> newId;

			cout << "��������ְ�������� " << endl;
			cin >> newName;

			cout << "��������ְ���Ĳ��ű�ţ� " << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;

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
			// ��������
			this->_empArray[index] = worker;

			cout << "�޸ĳɹ���" << endl;
			this->save();
		}
		else {
			cout << "�޸�ʧ�ܣ�δ�ҵ�����" << endl;
		}
	}
	system("pause");
	system("cls");
}

/*
* ����ĳԱ��
*/
void WorkerManager::find_employee(){
	if (this->_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
		return;
	}
	else {
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1������ְ����Ų���" << endl;
		cout << "2������ְ����������" << endl;

		int select;

		while (true){
			cin >> select;
			if (select == 1) {
				// ����ְ����Ų���
				int id;
				cout << "��������ҵ�ְ����ţ�" << endl;
				cin >> id;

				int index = this->isExist(id);
				if (index != -1) {
					cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
					this->_empArray[index]->showInfo();
				}
				else {
					cout << " ����ʧ�ܣ����޴��ˣ�" << endl;
				}
				break;
			}
			else if (select == 2)
			{
				// ����ְ����������
				string name;
				cout << "������Ҫ���ҵ�ְ��������" << endl;
				cin >> name;

				// ���ұ�־
				bool flag = false;
				// ����
				int count = 0;

				for (int i = 0; i < this->_empNum; i++){
					if (this->_empArray[i]->_name == name) {
						if (!count) {
							cout << "���ҳɹ����������£�" << endl;
						}
						count++;
						this->_empArray[i]->showInfo();
						flag = true;
					}
				}
				if (flag == false) {
					cout << "����ʧ�ܣ����޴��ˣ�" << endl;
				}
				break;
			}
			else {
				cout << "�Ƿ����룬���������룡" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

/*
* ��Ա����������
*/
void WorkerManager::sort_employee(){
	if (this->_FileIsEmpty){
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "��ѡ������ķ�ʽ�� " << endl;
		cout << "1����ְ����Ž�������" << endl;
		cout << "2����ְ����Ž��н���" << endl;

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
			// ����ȼ�����
			if (i != minOrMax)
			{
				Worker* temp = this->_empArray[i];
				this->_empArray[i] = this->_empArray[minOrMax];
				this->_empArray[minOrMax] = temp;
			}
		}
	}
	this->save();
	cout << "����ɹ��������Ľ��Ϊ��" << endl;
	this->showEmployee();
}

/*
* ����ļ�����
*/
void WorkerManager::clearFile(){
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;

	int select;
	cin >> select;
	if (select == 1){
		// ����ļ�
		ofstream ofs(FILE_NAME, ios::trunc);  // ɾ���ļ������´���
		ofs.close();

		if (this->_empArray != nullptr){
			// ɾ��������ÿ��ְ������
			for (int i = 0; i < this->_empNum; i++){
				delete this->_empArray[i];
				this->_empArray[i] = nullptr;
			}
			delete[] this->_empArray;
			this->_empArray = nullptr;
			this->_empNum = 0;
			this->_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

// ��������
WorkerManager::~WorkerManager(){
	if (this->_empArray != nullptr){
		// ɾ��������ÿ��ְ������
		for (int i = 0; i < this->_empNum; i++)
		{
			delete this->_empArray[i];
			this->_empArray[i] = nullptr;
		}
		delete[] this->_empArray;
		this->_empArray = nullptr;
	}
}

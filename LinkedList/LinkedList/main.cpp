#include <iostream>
#include <thread>
#include <Windows.h>
#include <string.h>
#include "Student.h"
#include "Node.h"
#include "LinkedList.h"

using namespace std;

const int MENU_INPUT = 1;
const int MENU_REMOVE = 2;
const int MENU_OUTPUT = 3;
const int MENU_EXIT = 0;

int title();
int func_app();

LinkedList<Student<int>* >* addStudent(LinkedList<Student<int>* >* linkedList, 
										Student<int>* student);
LinkedList<Student<int>* >* removeStudent(LinkedList<Student<int>* >* linkedList);
LinkedList<Student<int>* >* printStudent(LinkedList<Student<int>* >* linkedList);

void func_run(int count) {


	/// <summary>
	/// ���μ��� ����
	/// </summary>
	/// <param name="count"></param>
	for (int i = 1; i <= count; i++) {
		//cout << "func point type : count " << i << endl;

		func_app();

	}
}

int main() {

	thread thread1 = thread(func_run, 1);	// C ��Ÿ�� thread ����
	thread1.join();

	return 0;

}

int func_app() {

	int menu = -1;
	LinkedList<Student<int>* > linkedStudent;
	Student<int>* student = NULL;

	while (menu) {

		title();			// Ÿ��Ʋ ���
		cin >> menu;

		// �޴�
		switch (menu)
		{
			// 1��
			case MENU_INPUT:
				student = new Student<int>();
				student->setId(1);
				student->setName("������");
				student->setBirthdate("1991-10-11");
				student->setAddress("OO������");

				addStudent(&linkedStudent, student);
				break;

			// 2��
			case MENU_REMOVE:
				removeStudent(&linkedStudent);
				break;

			// 3��
			case MENU_OUTPUT:
				printStudent(&linkedStudent);
				break;

			// 0��
			case MENU_EXIT:
				break;

			default:
				cout << "�߸��� �Է�" << endl;
				break;

		}

		Sleep(1000);

	}

	return 0;
}

LinkedList<Student<int>* >* addStudent(LinkedList<Student<int>* >* linkedList, 
										Student<int>* student) {
	linkedList->push(student);
	return linkedList;
}

LinkedList<Student<int>* >* removeStudent(LinkedList<Student<int>* >* linkedList) {

	Student<int>* data = linkedList->pop();

	if (data != NULL) {
		cout << "��ȣ:" << data->getId() << endl;
		cout << "�̸�:" << data->getName() << endl;
		cout << "�������:" << data->getBirthdate() << endl;
		cout << "�ּ�:" << data->getAddress() << endl;
	}

	return linkedList;
}

LinkedList<Student<int>* >* printStudent(LinkedList<Student<int>* >* linkedList) {

	Node<Student<int> *>* pNode = linkedList->getFirst();

	while ( pNode ) {

		Student<int>* data = pNode->getData();

		cout << "��ȣ:" << data->getId() << endl;
		cout << "�̸�:" << data->getName() << endl;
		cout << "�������:" << data->getBirthdate() << endl;
		cout << "�ּ�:" << data->getAddress() << endl;


		pNode = pNode->getNext();
	}

	return linkedList;
}

int estegg1() {

	Node<int> node;
	Node<string> strNode;
	LinkedList<int> linkedlist;
	LinkedList<Student<int>* > linkedStudent;
	Student<int>* student = NULL;

	node.setData(1);
	strNode.setData("�ѱ�");

	linkedlist.push(1);
	int data = linkedlist.pop();

	cout << node.getData() << "," << strNode.getData() << endl;
	cout << "��ũ�帮��Ʈ:" << data << endl;

	student = new Student<int>();
	student->setId(0);
	student->setName("������");
	student->setBirthdate("1991-10-11");
	student->setAddress("OO������");

	linkedStudent.push(student);

	student = NULL;
	student = linkedStudent.pop();

	cout << "��ũ��Ŭ����(�л�)" << endl;
	cout << "��ȣ:" << student->getId() << endl;
	cout << "�̸�:" << student->getName() << endl;
	cout << "�������:" << student->getBirthdate() << endl;
	cout << "�ּ�:" << student->getAddress() << endl;

	return 0;
}

int title() {

	system("cls");
	cout << "------------------------------------------" << endl;
	cout << "       �ּҷ�(�л�) ������Ʈ              " << endl;
	cout << "------------------------------------------" << endl;
	cout << endl;
	cout << "            ��  ��: ������" << endl;
	cout << "            �̸���:rabbit.white@daum.net" << endl;
	cout << "            �ۼ�����: 2022-02-19" << endl;
	cout << "------------------------------------------" << endl;
	cout << "1. �Է�" << endl;
	cout << "2. ����" << endl;
	cout << "3. ���" << endl;
	cout << "0. ����" << endl;
	cout << "------------------------------------------" << endl;

	return 0;

}
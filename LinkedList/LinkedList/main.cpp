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
	/// 프로세스 갯수
	/// </summary>
	/// <param name="count"></param>
	for (int i = 1; i <= count; i++) {
		//cout << "func point type : count " << i << endl;

		func_app();

	}
}

int main() {

	thread thread1 = thread(func_run, 1);	// C 스타일 thread 생성
	thread1.join();

	return 0;

}

int func_app() {

	int menu = -1;
	LinkedList<Student<int>* > linkedStudent;
	Student<int>* student = NULL;

	while (menu) {

		title();			// 타이틀 출력
		cin >> menu;

		// 메뉴
		switch (menu)
		{
			// 1번
			case MENU_INPUT:
				student = new Student<int>();
				student->setId(1);
				student->setName("정도윤");
				student->setBirthdate("1991-10-11");
				student->setAddress("OO광역시");

				addStudent(&linkedStudent, student);
				break;

			// 2번
			case MENU_REMOVE:
				removeStudent(&linkedStudent);
				break;

			// 3번
			case MENU_OUTPUT:
				printStudent(&linkedStudent);
				break;

			// 0번
			case MENU_EXIT:
				break;

			default:
				cout << "잘못된 입력" << endl;
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
		cout << "번호:" << data->getId() << endl;
		cout << "이름:" << data->getName() << endl;
		cout << "생년월일:" << data->getBirthdate() << endl;
		cout << "주소:" << data->getAddress() << endl;
	}

	return linkedList;
}

LinkedList<Student<int>* >* printStudent(LinkedList<Student<int>* >* linkedList) {

	Node<Student<int> *>* pNode = linkedList->getFirst();

	while ( pNode ) {

		Student<int>* data = pNode->getData();

		cout << "번호:" << data->getId() << endl;
		cout << "이름:" << data->getName() << endl;
		cout << "생년월일:" << data->getBirthdate() << endl;
		cout << "주소:" << data->getAddress() << endl;


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
	strNode.setData("한글");

	linkedlist.push(1);
	int data = linkedlist.pop();

	cout << node.getData() << "," << strNode.getData() << endl;
	cout << "링크드리스트:" << data << endl;

	student = new Student<int>();
	student->setId(0);
	student->setName("정도윤");
	student->setBirthdate("1991-10-11");
	student->setAddress("OO광역시");

	linkedStudent.push(student);

	student = NULL;
	student = linkedStudent.pop();

	cout << "링크드클래스(학생)" << endl;
	cout << "번호:" << student->getId() << endl;
	cout << "이름:" << student->getName() << endl;
	cout << "생년월일:" << student->getBirthdate() << endl;
	cout << "주소:" << student->getAddress() << endl;

	return 0;
}

int title() {

	system("cls");
	cout << "------------------------------------------" << endl;
	cout << "       주소록(학생) 프로젝트              " << endl;
	cout << "------------------------------------------" << endl;
	cout << endl;
	cout << "            작  성: 정도윤" << endl;
	cout << "            이메일:rabbit.white@daum.net" << endl;
	cout << "            작성일자: 2022-02-19" << endl;
	cout << "------------------------------------------" << endl;
	cout << "1. 입력" << endl;
	cout << "2. 삭제" << endl;
	cout << "3. 출력" << endl;
	cout << "0. 종료" << endl;
	cout << "------------------------------------------" << endl;

	return 0;

}
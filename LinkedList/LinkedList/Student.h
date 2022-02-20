#pragma once
#ifndef _STUDENT_H_
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Student
{
private:
	int id;
	string name;
	string birthdate;
	string address;

public:
	Student();
	~Student();

	int getId();
	string getName();
	string getBirthdate();
	string getAddress();

	void setId(int id);
	void setName(string name);
	void setBirthdate(string birthdate);
	void setAddress(string address);

protected:


};

template <typename T>
Student<T>::Student()
{

}

template <typename T>
Student<T>::~Student()
{

}

template <typename T>
int Student<T>::getId()
{
	return this->id;
}

template <typename T>
string Student<T>::getName() {
	
	return this->name;
}

template <typename T>
string Student<T>::getBirthdate() {
	return this->birthdate;
}

template <typename T>
string Student<T>::getAddress() {
	return this->address;
}

template <typename T>
void Student<T>::setId(int id) {
	this->id = id;
}

template <typename T>
void Student<T>::setName(string name) {
	this->name = name;
}

template <typename T>
void Student<T>::setBirthdate(string birthdate) {
	this->birthdate = birthdate;
}

template <typename T>
void Student<T>::setAddress(string address) {
	this->address = address;
}

#endif // !_STUDENT_H_


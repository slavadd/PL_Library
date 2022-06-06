#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Student
{
private:
	string studentId;
	string studentName;
	string noTakenBooks;

	ifstream input1;
	ofstream output1;
public:
	Student(string ID, string NAME, string TAKENBOOKS);
	Student();

	string getId();
	string getName();
	string getTakenBooks();

	void setId(string id);
	void setName(string n);
	void setTakenBooks(string no);

	void add();
	void modify();
	void search();
	void seeStudents();
	void Delete();
};
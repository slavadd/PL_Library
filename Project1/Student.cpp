#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include"Student.h"
using namespace std;

Student::Student(string ID, string NAME, string TAKENBOOKS)
	:studentId(ID), studentName(NAME), noTakenBooks(TAKENBOOKS) {

}

Student::Student() {

}


string Student::getId() {
	return studentId;
}

string Student::getName() {
	return studentName;
}

string Student::getTakenBooks() {
	return noTakenBooks;
}

void Student::setId(string id) {
	if (!id.empty()) {
		studentId = id;
	};
	
}

void Student::setName(string n) {
	if (!n.empty()) {
		studentName = n;
	};
	
}

void Student::setTakenBooks(string no) {
	noTakenBooks = no;
}

void Student::add()
{
	cout << "\t\t\tVIRTUAL LIBRARY" << endl;
	cout << endl;
	string studentId, studentName, noTakenBooks;
	//string sid, name, dname, sem, nib;
	cout << "\nEnter description about the student you want to add!" << endl;
	cout << endl;
	cout << "Enter the student ID:\t";
	cin >> studentId;
	cout << endl;
	setId(studentId);

	cout << "Enter the name of the student:\t";
	cin >> studentName;
	cout << endl;
	setName(studentName);

	cout << "Enter the number of taken books to the name of this student:\t";
	cin >> noTakenBooks;
	cout << endl;
	setTakenBooks(noTakenBooks);

	ofstream output1;
	output1.open("student.txt", ios::app);
	if (!output1)
	{
		cout << "Student cannot be added in the record!" << endl;
	}
	else
	{
		output1 << "\n" << studentId << "\t\t" << studentName << "\t\t" << noTakenBooks <<"\n";
		cout << endl;
		output1.close();
		cout << "\nYou have successfully added a student in the record!" << endl;
	}
}
void Student::modify()
{
	cout << "\t\t\tVIRTUAL LIBRARY" << endl;
	cout << endl;
	string id, studentId, studentName, noTakenBooks;
	int n1 = 0, n2 = 0;
	ifstream input("student.txt");
	ofstream output("temp.txt");
	cout << "\nEnter  student ID that is going to be modified:\t";
	cin >> id;
	cout << endl;
	if (!input)
	{
		cout << "Input file failed to open or does not exist!\n";
	}
	else
	{
		while (input >> studentId >> studentName >> noTakenBooks)
		{
			n1++;
			if (id == studentId)
			{
				string studentId, studentName, noTakenBooks;
				cout << endl << "This record of a student id  exists!" << endl;
				cout << "\nEnter the description for student which is going to be modified!!" << endl;
				cout << endl;
				cout << "Enter the student ID:\t";
				cin >> studentId;
				cout << endl;

				cout << "Enter the name of the student:\t";
				cin >> studentName;
				cout << endl;

				cout << "Enter the number of taken books by this student:\t" << endl;
				cin >> noTakenBooks;
				cout << endl;


				output << "\n" << studentId << "\t\t" << studentName << "\t\t" << noTakenBooks << "\n";
				cout << endl;
				cout << "You have successfully added a student in the record after modifying!" << endl;
			}
			else
			{
				n2++;
				output << "\n" << studentId << "\t\t" << studentName << "\t\t" << noTakenBooks << "\n";
			}
		}
		if (n1 == n2)
		{
			cout << "\nThe given student ID record does not exist and cannot be modified!" << endl;
		}
		input.close();
		output.close();
		remove("student.txt");
		rename("temp.txt", "student.txt");
	}
}
void Student::search()
{
	cout << "\t\t\tVIRTUAL LIBRARY" << endl;
	cout << endl;
	string studentId1, studentName1, noTakenBooks1;
	int n1 = 0, n2 = 0;
	string x;
	ifstream input1;
	cout << "\nEnter the student id to find the record!" << endl;
	cout << endl;
	cout << "Enter the student ID:\t";
	cin >> x;
	cout << endl;
	input1.open("student.txt", ios::in);
	if (!input1)
	{
		cout << "File cannot be opened!" << endl;
	}
	else
	{
		

		while (input1 >> studentId1 >> studentName1 >> noTakenBooks1) //i tova
		{
			n1++;
			//input1 >> studentId1 >> studentName1 >> noTakenBooks1;
			if (studentId1 == x)
			{
				cout << "Student of entered Id is:" << endl;
				cout << "\n" << studentId1 << "\t\t" << studentName1 << "\t\t" << noTakenBooks1 << "\n";
			}
			else
			{
				n2++;
			}
		}
		if (n1 == n2)
		{
			cout << "\nRecord of entered student ID does not exist and cannot be searched!" << endl;
		}
		cout << endl; //tova e novo
	}
}
void Student::Delete()
{
	cout << "\t\t\tVIRTUAL LIBRARY" << endl;
	cout << endl;
	int i = 0;
	char studentId[30], studentName[30], noTakenBooks[30];
	int n1 = 0, n2 = 0;
	string fsid;
	cout << "Enter student ID which is going to be deleted: ";
	cin >> studentId;
	cout << endl;
	for (i = 0; studentId[i] != '\0'; i++);
	ifstream input("student.txt");
	if (!input)
	{
		cout << "Input file failed to open!\n";
	}
	else
	{
		ofstream output("temp.txt");
		while (input >> fsid >> studentName >> noTakenBooks)
		{
			n1++;
			if (studentId == fsid)
			{
				cout << "The entered ID of the student has been deleted!" << endl;
			}
			else
			{
				n2++;
				output << "\n" << fsid << "\t\t" << studentName << "\t\t" << noTakenBooks <<"\n";
			}

		}
		if (n1 == n2)
		{
			cout << "\nThe entered ID of the student does not exist in the records!" << endl;
			cout << endl;
		}
		input.close();
		output.close();
		remove("student.txt");
		rename("temp.txt", "student.txt");
	}
}

void Student::seeStudents()
{
	cout << "\t\t\tVIRTUAL LIBRARY" << endl;
	cout << endl;
	string studentId1, studentName1, noTakenBooks1;
	int n1 = 0, n2 = 0;
	ifstream input1;
	cout << "\nSee all of the students who have registration in the virtual library!" << endl;
	cout << endl;

	input1.open("student.txt", ios::in);
	if (!input1)
	{
		cout << "File cannot be opened!" << endl;
	}
	else
	{

		while (input1 >> studentId1 >> studentName1 >> noTakenBooks1) //i tova
		{
			n1++;
			n2++;
			
				cout << "Student record "<<n2 <<" is:" << endl;
				cout << "\n" << studentId1 << "\t\t" << studentName1 << "\t\t" << noTakenBooks1 << "\n";
				cout << endl; //tova e novo

		}
		
	}
}
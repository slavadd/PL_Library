#include<iostream>
#include<fstream>
#include<string>
#include <stdio.h>
#include"Returnbook.h"
using namespace std;

string return_book::getBookId() {
	return bookId;
}

string return_book::getType() {
	return typeOfItem;
}

string return_book::getAuthor() {
	return author;
}

string return_book::getTitle() {
	return title;
}

int return_book::getYear() {
	return year;
}


void return_book::setId(string id) {
	if (!id.empty()) {
		bookId = id;
	};

}

void return_book::setType(string t) {
	if (!t.empty()) {
		typeOfItem = t;
	};
}


void return_book::setAuthor(string a) {
	author = a;
}

void return_book::setTitle(string t) {
	title = t;
}

void return_book::setYear(int y) {
	if (y > 1900) {
		year = y;
	}
}

string return_book::getId() {
	return studentId;
}

string return_book::getName() {
	return studentName;
}

string return_book::getTakenBooks() {
	return noTakenBooks;
}


void return_book::setName(string n) {
	if (!n.empty()) {
		studentName = n;
	};

}

void return_book::setTakenBooks(string no) {
	noTakenBooks = no;
}


void return_book::ret_book()

{
	cout << "\t\t\tVIRTUAL LIBRARY" << endl;
	cout << endl;

	string rbid; //return book id
	string rsid; //return student id

	string bookId;
	string typeOfItem;
	string author;
	string title;
	int year;
	string studentId;
	string studentName;
	string noTakenBooks;

	ofstream output;
	ifstream input("issuancebook.txt", ios::in);
	cout << "Enter the item description that u want to return in the virtual library!";
	cout << endl;
	cout << "Enter the item ID:\t";
	cin >> rbid;
	cout << endl;

	cout << "Enter the student ID:\t";
	cin >> rsid;
	cout << endl;

	if (!input)
	{
		cout << "\nFile does not exist!";

	}
	else {
		ofstream output("temp.txt", ios::out);
		while (input >> bookId >> studentId >> studentName >> typeOfItem >> author >> title >> year)
		{
			n1++;
			if (rbid == bookId)
			{

				cout << "Succefully return of the item!";
				cout << endl;
				ofstream output1;
				output1.open("item.txt", ios::app);
				if (!output1)
				{
					cout << "This item ID does not exist!";
				}
				else {
					output1 << "\n" << bookId << "\t\t" << typeOfItem << "\t\t " << author << "\t\t" << title << "\t\t " << year << "\n";
					//output1 << bookId << "\t" << typeOfItem << "\t" << author << "\t" << title << "\t" << year << "\t" << '\n';
					cout << endl << endl << "\nThe item is updated" << endl;
					output1.close();
				}
				
			}
			if (rbid != bookId) {
				n2++;
				output << "\n" << bookId << "\t\t" << typeOfItem << "\t\t" << author << "\t\t" << title << "\t\t" << year << "\n" << endl;
			}
		}
		if (n1 == n2)
		{
			cout << "\nThis item cannot be returned because item ID record does not exist!" << endl;
		}
		input.close();
		output.close();
		remove("issuancebook.txt");
		rename("temp.txt", "issuancebook.txt");


	}



	//proba sys zapisa

	int s1 = 0, s2 = 0;
	ifstream inputS("student.txt");
	ofstream outputS("temp.txt");
	if (!inputS)
	{
		cout << "Input file failed to open or does not exist\n";
	}
	else
	{
			while (inputS >> studentId >> studentName >> noTakenBooks)
		{
			s1++;
			if (rsid == studentId)
			{
				noTakenBooks = "0";


				outputS << "\n" << studentId << "\t\t" << studentName << "\t\t" << noTakenBooks << "\n";
				cout << endl;
				cout << "You have successfully added a student in the record after returning the item!" << endl;
			}
			else
			{
				s2++;
				outputS << "\n" << studentId << "\t\t" << studentName << "\t\t" << noTakenBooks << "\n";
			}
		}
		if (s1 == s2)
		{
			cout << "\nThe given student ID record does not exist and cannot be modified !" << endl;
		}
		inputS.close();
		outputS.close();
		remove("student.txt");
		rename("temp.txt", "student.txt");
	}

}

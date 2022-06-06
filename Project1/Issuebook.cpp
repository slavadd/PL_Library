#include<iostream>
#include<fstream>
#include<string>
#include <stdio.h>
#include"Issuebook.h"
using namespace std;
int Idcheck, rcheck;

string Issuebook::getBookId() {
	return bookId;
}

string Issuebook::getType() {
	return typeOfItem;
}

string Issuebook::getAuthor() {
	return author;
}

string Issuebook::getTitle() {
	return title;
}

int Issuebook::getYear() {
	return year;
}



void Issuebook::setId(string id) {
	if (!id.empty()) {
		bookId = id;
	};

}

void Issuebook::setType(string t) {
	if (!t.empty()) {
		typeOfItem = t;
	};
}


void Issuebook::setAuthor(string a) {
	author = a;
}

void Issuebook::setTitle(string t) {
	title = t;
}

void Issuebook::setYear(int y) {
	if (y > 1900) {
		year = y;
	}
}

string Issuebook::getId() {
	return StudentId;
}

string Issuebook::getName() {
	return studentName;
}

string Issuebook::getTakenBooks() {
	return noTakenBooks;
}


void Issuebook::setName(string n) {
	if (!n.empty()) {
		studentName = n;
	};

}

void Issuebook::setTakenBooks(string no) {
	noTakenBooks = no;
}




void Issuebook::search()
{
	string bookId, typeOfItem, author,title;
	int year;
	string c;
	int n1 = 0, n2 = 0;
	ifstream input;
	cout << "Enter the item id of the item that is going to be to searched in the virtual library:" << endl;
	cout << endl;
	cout << "Enter the item ID:\t ";
	cin >> c;
	cout << endl;
	input.open("item.txt", ios::in);

	if (!input)
	{
		cout << "File cannot be opened!" << endl;
	}
	else
	{
		while (input >> bookId >> typeOfItem >> author >> title >> year)
		{
			n1++;
			if (bookId == c)
			{
				cout << "\nThat item ID exists in the virtual library!" << endl;
			}
			else {
				n2++;
			}
		}
		if (n1 == n2)
		{
			cout << "\nItem does not exist!" << endl;
		}
		cout << endl;
	}

	cout << endl;
}

void Issuebook::search2()        // For searching a student present in the class.
{
	string studentId1;
	string studentName1;
	string noTakenBooks1;
	int n1 = 0, n2 = 0;
	string x;
	ifstream input1;
	cout << "Enter the id of the student that is going to be seached in the records" << endl;
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
		while (input1 >> studentId1 >> studentName1 >> noTakenBooks1)
		{
			n1++;
			if (studentId1 == x)
			{
				cout << "\nThat student ID exists in the virtual library!" << endl;

			}
			else {
				n2++;
			}

		}
		if (n1 == n2)
		{
			cout << "\nStudent does not have a membership in the virtual library!!" << endl;
		}
		cout << endl;


	}

}

void Issuebook::issue()
{
	cout << "\t\t\tVIRTUAL LIBRARY" << endl;
	cout << endl;

	int n = 0, t = 0;
	int Uid; //item id for searching
	int Urno; //student id for searching
	int ID, Rno;
	string Bkname, Stdname, Aname, Iname, Dep, semster;
	
	int studentId1;
	string studentName1;
	int noTakenBooks1;

	string  typeOfItem1, author1, title1;
	int bookId1,year1;
	//validaty book

	cout << "Enter item ID for searching:\t";
	cin >> Uid;
	cout << endl;
	ifstream input1("item.txt");
	if (!input1) {
		cout << "Error in the file!";
	}
	else {
		while (input1 >> bookId1 >> typeOfItem1 >> author1 >> title1 >> year1) {
			if (Uid == bookId1) {
				n = 1;
				cout << "Found item" << endl << endl;
				//student
				cout << "Enter Student ID for searching:\t";
				cin >> Urno;
				cout << endl;
				t = 0;
				ifstream input2("student.txt");
				if (!input2) {
					cout << "Error in the file!";
				}
				else {
					while (input2 >> studentId1 >> studentName1 >> noTakenBooks1) {
						if (Urno == studentId1) {
							cout << "\nAvailable student" << endl << endl;
							t = 1;
							if (noTakenBooks1 == 0) {
								cout << "You can issue the item to this student." << endl << endl;
								int chk;
								cout << "Enter 1 to confirm book issuence:\t";
								cin >> chk;
								if (chk == 1) {
									ofstream issue("issuancebook.txt", ios::app);
									if (!issue) {
										cout << "Error in the issue file!";
									}
									else {
										issue <<"\n" << bookId1 << "\t\t" << studentId1 << "\t\t" << studentName1 << "\t\t" << typeOfItem1 << "\t\t" << author1 << "\t\t" << title1 << "\t\t" << year1 << "\n";
										//issue << bookId1 << "\t\t" << noTakenBooks1 << "\t\t" << typeOfItem1 << "\t\t" << author1 << "\t\t" << title1 << "\t\t" << year1 << "\n";
										cout << endl << endl << "Item issued";
										Idcheck = bookId1;//ID // book id
										rcheck = studentId1;
									}
									issue.close();

								}
							}
							else {
								cout << "You cannot issue the items since the student already has taken items" << endl;
							}
							break;
						}
					}
				}
				input2.close();
			}
		}
	}
	if (n != 1) {
		cout << "Item not found" << endl;
	}
	else if (t != 1) {
		cout << "Student Not found" << endl;
	}
	input1.close();
	//delete issued item
	ifstream indel("item.txt");
	if (!indel) {
		cout << "Error!";
	}
	else {
		ofstream outdel("temp.txt", ios::out);
		if (!outdel) {
			cout << "Error!";
		}
		else {
			while (indel >> bookId1 >> typeOfItem1 >> author1 >> title1 >> year1) {
				if (Idcheck == bookId1) {
					cout << endl << "Deleting! Item ID record from the item.txt file is deleted." << endl;
				}
				else {
					outdel << "\n" <<bookId1 << "\t\t" << typeOfItem1 << "\t\t" << author1 << "\t\t" << title1 << "\t\t" << year1<< "\n";
				}
			}
		}
		outdel.close();
	}
	indel.close();
	remove("item.txt");
	rename("temp.txt", "item.txt");
	
	//change student 
	ifstream indel1("student.txt");
	if (!indel1) {
		cout << "Error";
	}
	else {
		ofstream outdel1("temp.txt", ios::out);
		if (!outdel1)
		{
			cout << "Error!";
		}
		else
		{
			while (indel1 >> studentId1 >> studentName1 >> noTakenBooks1)
			{
				if (rcheck == studentId1)
				{

					cout << endl << "Refreshing! Student from student.txt file is updated.";
					outdel1 <<"\n" <<studentId1 << "\t\t" << studentName1 << "\t\t" << 1 << "\n";
				}
				else {
					outdel1 <<"\n" <<studentId1 << "\t\t" << studentName1 << "\t\t" << 0 << "\n";
				}
			}
		}
		outdel1.close();
	}
	indel1.close();
	remove("student.txt");
	rename("temp.txt", "student.txt");
}

void Issuebook::validity()
{
	cout << "\t\t\tVIRTUAL LIBRARY" << endl;
	cout << endl;
	string a, b, c, d, e;
	fstream in;
	in.open("item.txt", ios::in);
	if (!in)
	{
		cout << "File opening error!" << endl;
	}
	else
	{
		while (in >> a >> b >> c >> d >> e)
		{
			search();
			break;
		}
		cout << endl;
	}
	string f, g, h, i, j, sidf;
	fstream inp;
	inp.open("student.txt", ios::in);
	if (!inp)
	{
		cout << "File opening error!" << endl;
	}
	else
	{
		while (inp >> f >> g >> h)
		{
			search2();
			break;
		}
		cout << endl;
	}
}
void Issuebook::lim_check()
{
	cout << "\t\t\tVIRTUAL LIBRARY" << endl;
	cout << endl;
	ifstream input;
	string q;
	cout << "Enter the student ID to check if he has reached his limit of books" << endl;
	cout << endl;
	cout << "Enter student ID:\t";
	cin >> q;
	cout << endl;
	input.open("student.txt", ios::in);
	
	string studentId1;
	string studentName1;
	string noTakenBooks1;
	
	string bid, nop, bn, an, in;


	if (!input)
	{
		cout << "File cannot be opened!" << endl;
	}
	else
	{
		while (input >> studentId1 >> studentName1 >> noTakenBooks1)
		{

			if (noTakenBooks1 == "0" && studentId1 == q)
			{
				cout << "The student of ID " << studentId1 << " can get an item!" << endl;
			}
			if (noTakenBooks1 != "0" && studentId1 == q)
			{
				cout << "Sorry student of ID " << studentId1 << " cannot get item because he has reached his limit of items!" << endl;
			}
			cout << endl;
		}
	}
}

void Issuebook::seeFree()
{
	cout << "\t\t\tVIRTUAL LIBRARY" << endl;
	cout << endl;

	string bookId, typeOfItem, author, title;
	int year;
	int n1 = 0, n2 = 0;
	string c;

	ifstream input;
	cout << "See all available items in the virtual library:" << endl;
	cout << endl;
	
	input.open("item.txt", ios::in);

	if (!input)
	{
		cout << "File cannot be opened!!" << endl;
	}
	else
	{

		while (input >> bookId >> typeOfItem >> author >> title >> year)
		{
			n1++;
			n2++;
			
				cout << "\nRecord "<<n2<<" is: " << endl;
				cout << "\n" << bookId << "\t\t" << typeOfItem << "\t\t " << author << "\t\t" << title << "\t\t " << year << "\n";
				
		}
		
		cout << endl;
	}
}

void Issuebook::seeTaken()
{
	cout << "\t\t\tVIRTUAL LIBRARY" << endl;
	cout << endl;

	string bookId, typeOfItem, author, title;
	string studentId;
	string studentName;
	string noTakenBooks;
	int year;
	int n1 = 0, n2 = 0;
	string c;

	ifstream input;
	cout << "See all taken items in the virtual library:" << endl;
	cout << endl;
	
	input.open("issuancebook.txt", ios::in);

	if (!input)
	{
		cout << "File cannot be opened!!" << endl;
	}
	else
	{

		while (input >> bookId >> studentId >> studentName >> typeOfItem >> author >> title >> year)
		{
			n1++;
			n2++;
			
			cout << "\nRecord " << n2 << " is: " << endl;
			cout << "\n" << bookId << "\t\t" << typeOfItem << "\t\t " << author << "\t\t" << title << "\t\t " << year << "\n";
			
		}

		cout << endl;
	}
}
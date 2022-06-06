#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class return_book
{
private:
	string rbid; //return book id
	string rsid; //return student id
	int Idcheck, rcheck;

	string bookId;
	string typeOfItem;
	string author;
	string title;
	int year;

	string bid, n, nop, an, in, stdid;


	int np = 0, t = 0, Uid, Urno;
	int ID, Rno, noib;

	string studentId;
	string studentName;
	string noTakenBooks;


	int n1 = 0, n2 = 0;
	int s1 = 0, s2 = 0;
public:
	void ret_book();

	friend ostream& operator<<(ostream& output, const return_book& R) {
		output << "ID: " << R.bookId << " Type: " << R.typeOfItem << " Author: " << R.author << " Title: " << R.title << " Year: " << R.year << endl;
		return output;
	};


	string getBookId();
	string getType();
	string getAuthor();
	string getTitle();
	int getYear();

	void setId(string id);
	void setType(string t);
	void setAuthor(string a);
	void setTitle(string t);
	void setYear(int y);

	string getId();
	string getName();
	string getTakenBooks();


	void setName(string n);
	void setTakenBooks(string no);

};
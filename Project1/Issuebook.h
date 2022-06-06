#pragma once
#include<iostream>
#include<fstream>
using namespace std;


class Issuebook
{
private:

	string bookId;
	string typeOfItem;
	string author;
	string title;
	int year;

	string StudentId;
	string studentName;
	string noTakenBooks;

	int in = 0;


public:
	void search();
	void search2();
	void seeFree();
	void seeTaken();
	void issue();
	void validity();
	void lim_check();


	string getId();
	string getName();
	string getTakenBooks();

	void setId(string id);
	void setName(string n);
	void setTakenBooks(string no);

	string getBookId();
	string getType();
	string getAuthor();
	string getTitle();
	int getYear();

	void setType(string t);
	void setAuthor(string a);
	void setTitle(string t);
	void setYear(int y);

};
#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class book
{
private:
	string bookId;
	string typeOfItem;
	string author;
	string title;
	int year;

	ifstream input;
	ofstream output;

public:
	book(string ID, string TYPE, string AUTHOR, string TITLE, int YEAR);
	book();

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

	void create();
	void modify();
	void search();
	void Delete();
};
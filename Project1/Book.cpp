#include"book.h"
#include<fstream>
#include<iostream>
#include<string>
#include <stdio.h>
using namespace std;


	book::book(string ID, string TYPE, string AUTHOR, string TITLE, int YEAR)
		:bookId(ID), typeOfItem(TYPE), author(AUTHOR), title(TITLE), year(YEAR) {

	}
	book::book() {

	}

	string book::getBookId() {
		return bookId;
	}

	string book::getType() {
		return typeOfItem;
	}

	string book::getAuthor() {
		return author;
	}

	string book::getTitle() {
		return title;
	}

	int book::getYear() {
		return year;
	}


	void book::setId(string id) {
		if (!id.empty()) {
			bookId = id;
		};

	}

	void book::setType(string t) {
		if (!t.empty()) {
			typeOfItem = t;
		};
	}


	void book::setAuthor(string a) {
		author = a;
	}

	void book::setTitle(string t) {
		title = t;
	}

	void book::setYear(int y) {
		if (y > 1900) {
			year = y;
		}
	}

	void book::create()
	{

		cout << "\t\t\t VIRTUAL LIBRARY" << endl;
		cout << endl;
		string bookId, typeOfItem, author, title;
		int year;
		
		cout << "Enter description about the item you want to create!" << endl;
	
		cout << endl;

		cout << "Enter the item ID!:\t";
		cin >> bookId;
		cout << endl;
		setId(bookId);

		cout << "Enter type of the Item!:\t";
		cin >> typeOfItem;
		cout << endl;
		setType(typeOfItem);

		cout << "Enter the author of the item!:\t";
		cin >> author;
		cout << endl;
		setAuthor(author);

		cout << "Enter the title of the item !:\t";
		cin >> title;
		cout << endl;
		setTitle(title);


		cout << "Enter the year of the item!:\t";
		cin >> year;
		cout << endl;
		setYear(year);

		

			ofstream output;
		output.open("item.txt", ios::app);
		if (!output)
		{
			cout << "File cannot be opened!" << endl;
		}
		else
		{

			//output << "proba s get";
			//raboti 
			output << "\n" << getBookId() << "\t\t" << getType() << "\t\t " << getAuthor() << "\t\t" << getTitle() << "\t\t " << getYear() << "\n";
			//output << "proba bez get";
			//output << "\n" << bookId << "\t\t" << typeOfItem << "\t\t " << author << "\t\t" << title<< "\t\t " << year << "\n";
			cout << endl;
			output.close();
			cout << "\nYou have successfully created item in the virtual library!" << endl;
		}
	}

	void book::modify()
	{
		cout << "\t\t\tVIRTUAL LIBRARY" << endl;
		cout << endl;
		string modifyId, bookId, typeOfItem, author, title;
		int year;
		int n1 = 0, n2 = 0;
		ifstream input("item.txt");
		ofstream output("temp.txt");
		cout << "Enter ID of the item that is going to be modified:\t";
		cin >> modifyId;
		cout << endl;
		if (!input)
		{
			cout << "Input file failed to open or does not exist!\n";
		}
		else
		{
			while (input >> bookId >> typeOfItem >> author >> title >> year)
			{
				n1++;
				if (modifyId == bookId)
				{

					string bookId, typeOfItem, author, title;
					int year;
					cout << "Enter the attributes of the item which you want to modify from the existing record!" << endl;

					cout << "\nEnter the item ID!:\t";
					cin >> bookId;
					cout << endl;
					setId(bookId);

					cout << "Enter the item type!:\t";
					cin >> typeOfItem;
					cout << endl;
					setType(typeOfItem);

					cout << "Enter the author of the item!:\t";
					cin >> author;
					cout << endl;
					setAuthor(author);

					cout << "Enter the title of the item!:\t";
					cin >> title;
					cout << endl;
					setTitle(title);


					cout << "Enter the year of the item!:\t";
					cin >> year;
					cout << endl;
					setYear(year);

					
					output << "\n" << bookId << "\t\t" << typeOfItem << "\t\t " << author << "\t\t" << title << "\t\t " << year << "\n";
					cout << endl;
					cout << "You have successfully modified the item in the library!" << endl;
					cout << endl;
				}
				else
				{
					n2++;
					output << "\n" << bookId << "\t\t" << typeOfItem << "\t\t " << author << "\t\t" << title << "\t\t " << year << "\n";
				}
			}
			if (n1 == n2)
			{
				cout << "\nThe entered item Id does not exist and cannot be modified" << endl;
				cout << endl;
			}
			input.close();
			output.close();
			remove("item.txt");
			rename("temp.txt", "item.txt");

		}
	}

	void book::search()
	{
		cout << "\t\t\tVIRTUAL LIBRARY" << endl;
		cout << endl;

		
		string bookId, typeOfItem, author, title;
		int year;
		int n1 = 0, n2 = 0;
		string c;

		ifstream input;
		cout << "Enter the item ID that you want to search for in the virtual library:" << endl;
		cout << endl;
		cout << "Enter the item ID:\t";
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
					cout << "The record is: " << endl;
					cout << "\n" << bookId << "\t\t" << typeOfItem << "\t\t " << author << "\t\t" << title << "\t\t " << year << "\n";
				}
				else {
					n2++;
				}
			}
			if (n1 == n2)
			{
				cout << "\nThe entered item Id does not exist and cannot be searched" << endl;
				cout << endl;
			}
			cout << endl;
		}
	}

	void book::Delete()
	{
		cout << "\t\t\tVIRTUAL LIBRARY" << endl;
		cout << endl;
		int i = 0, n1 = 0, n2 = 0;
		char bookId[30], typeOfItem[30], author[30], title[30];
		int year;
		string eid;
		cout << "Enter item ID to delete:\t";
		cin >> bookId;
		cout << endl;
		for (i = 0; bookId[i] != '\0'; i++);
		ifstream input;
		ofstream output;
		input.open("item.txt");
		if (!input)
		{
			cout << "Input file does not exist!";
		}
		else
		{
			output.open("temp.txt");
			while (input >> eid >> typeOfItem >> author >> title >> year)
			{
				n1++;
				if (bookId == eid)
				{
					cout << "\nThe entered item ID record has been deleted!" << endl;

				}
				else
				{
					n2++;
					output << "\n" << eid << "\t\t" << typeOfItem << "\t\t" << author << "\t\t" << title << "\t\t" << year << "\n" << endl;
				}
			}
			if (n1 == n2)
			{
				cout << "The item ID is not found and this record cannot be deleted!" << endl;
			}


			input.close();
			output.close();
			remove("item.txt");
			rename("temp.txt", "item.txt");


		}
	}

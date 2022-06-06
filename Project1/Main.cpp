#include<iostream>
#include<fstream>
#include<conio.h>
#include<Windows.h>
#include"book.h";
#include"Student.h";
#include"Issuebook.h";
#include"Returnbook.h";
using namespace std;
int main()
{
	system("COLOR fD");
	cout << "\t\t\t***VIRTUAL LIBRARY***" << endl;
	cout << endl << endl;
	book c;
	Student s;
	Issuebook u;
	return_book r;
	string p = "";
	char ch;
	cout << "Enter the password to enter into the virtual library:" << endl << endl;
	ch = _getch();
	while (ch != 13)
	{
		p.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	cout << endl << endl;
	if(p=="0000")
	{
		cout << "\t\tWelcome!\nYou have entered correct password!\nPress any key to enter into the library!" << endl;
		cout << endl;
		system("pause");
		int cho;
		do
		{
			system("cls");
			system("COLOR fD");
			cout << "\t******VIRTUAL LIBRARY******" << endl;
			cout << "\n\t~~~~~MAIN MENU~~~~~\n" << endl;
			cout << "Enter your choice number from 0 to 15!" << endl;
			cout << endl;
			cout << "\t ITEM OPTIONS:\n" << endl;
			cout << "Press 0: Create an item record ===> " << endl;
			cout << endl;
			cout << "Press 1: Modify an item record ===> " << endl;
			cout << endl;
			cout << "Press 2: Search an item record ===> " << endl;
			cout << endl;
			cout << "Press 3: Delete an item record ===> " << endl;
			cout << endl;
			cout << "\t STUDENT OPTIONS:\n" << endl;
			cout << "Press 4: Add a student record ===>" << endl;
			cout << endl;
			cout << "Press 5: Modify a student record ===>" << endl;
			cout << endl;
			cout << "Press 6: Search a student record ===>" << endl;
			cout << endl;
			cout << "Press 7: Delete a student record ===>" << endl;
			cout << endl;
			cout << "\t ITEM AND STUDENT OPTIONS:\n" << endl;
			cout << "Press 8: Check availability of an item and student record ===>" << endl;
			cout << endl;
			cout << "Press 9: Check if student has reached his limit of books ===>" << endl;
			cout << endl;
			cout << "Press 10: Lend an item to a student ===>" << endl;
			cout << endl;
			cout << "Press 11: Return an item to the library ===>" << endl;
			cout << endl;
			cout << "\t SHOW ALL OPTIONS:\n" << endl;
			cout << "Press 12: Show all of the available items in the library ===>" << endl;
			cout << endl;
			cout << "Press 13: Show all of the taken items in the library ===>" << endl;
			cout << endl;
			cout << "Press 14: Show all of the students in the library ===>" << endl;
			cout << endl;

			cout << "Press 15 to exit to the main menu!" << endl;
			cout << endl;


			cin >> cho;
			system("cls");
			switch (cho)
			{
			case 0:
				c.create();
				break;
			case 1:
				c.modify();
				break;
			case 2:
				c.search();
				break;
			case 3:
				c.Delete();
				break;
			case 4:
				s.add();
				break;
			case 5:
				s.modify();
				break;
			case 6:
				s.search();
				break;
			case 7:
				s.Delete();
				break;
			case 8:
				u.validity();
				break;
			case 9:
				u.lim_check();
				break;
			case 10:
				u.issue();
				break;
			case 11:
				r.ret_book();
				break;
			case 12:
				u.seeFree();
				break;
			case 13:
				u.seeTaken();
				break;
			case 14:
				s.seeStudents();
				break;
			case 15:
				break;
			default:
				cout << "\nYou have entered number out of range!!" << endl;
			}
			cout << endl;
			system("Pause");
			system("cls");
		} while (cho >= 0 && cho <= 15);
	}
	if(p!="0000")
	{
		cout << "Sorry! You have enterd wrong password!" << endl;
	}
}
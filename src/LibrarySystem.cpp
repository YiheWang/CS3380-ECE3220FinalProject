//============================================================================
// Name        : LibrarySystem.cpp
// Author      : Yihe Wang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "windows.h"
using namespace std;

class Book{
	private:
		int id;
		string name;
		string author;
		string category;
		double price;//price of this book
		int sumNumber;// sum number of this book in library
		int nowNumber;//the number of book in library now
		int appointNumber;//how many people appoint this book
		int borrowTimes;//how many times this book was borrowed
		bool ifReadOnly;//identify this book is read only or can be borrowed
		string lastReturnTime;//last time this book return to library
		string lastBorrowTime;//last time this book was borrowed
		string library;//this book is in which library of University

		string getLocalTime();

	public:
		//fill constructors here

		void setReturnTime();
		void setBorrowTime();
		void addBookNum();//add book number
		void deleteBookNum();//delete book number
		//void getBookMessage();//get book information from file or database
		void printBookMessage();//print out the information of book

};

class LibrarySystem{
	protected:
		vector<Book> books;

};

class StudentSystem : public LibrarySystem{
	private:
		int pawPrint;//id in the university
		string password;
		string name;//student name
		int historyBorrowNum;//book borrow number totally in history record
		int holdNum;//how many book hold now
		int maxHoldNum;//the maximum number of books students can hold
		vector<int> bookId;//store the id of book student borrowed
		string lastBorrowTime;
	public:
		//fill constructors here


		void printMessage();//print out the message of student
		void printView();//create the scene of student view and print out the choices
		void borrowBook();//borrow a book
		void returnBook();//return a book
		void removeHistory();//delete borrow history
		void changePassword();//change the password of id
		void appointBook();//appoint a book if all were borrowed
};

class LibrarianSystem : public LibrarySystem{
	private:
		int pawPrint;
		string password;
		string name;
	public:
		//fill constructors here


		void addNewBook();//add new book
		void deleteBook();//delete book
		void updateBookInfo();//update the book information
};

int main() {
	//SetConsoleOutputCP(437);
	printf("%c\n",22);

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

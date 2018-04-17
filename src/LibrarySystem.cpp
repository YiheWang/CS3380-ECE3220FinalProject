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
		//string lastReturnTime;//last time this book return to library
		string lastBorrowTime;//last time this book was borrowed
		string library;//this book is in which library of University

		string getLocalTime();

	public:
		//fill constructors here
		Book(int,string,string,string,double,
				int,int,int,int,bool,string,string);
		~Book();
		//void setReturnTime();
		//void setBorrowTime();
		//void addBookNum();//add book number
		//void deleteBookNum();//delete book number
		//void getBookMessage();//get book information from file or database
		//void printBookMessage();//print out the information of book

};

Book::Book(int id, string name, string author, string category, double price,
		int sumNumber, int nowNumber, int appointNumber, int borrowTimes,
		bool ifReadOnly, string lastBorrowTime, string library){
	this->id = id;
	this->name = name;
	this->author = author;
	this->category = category;
	this->price = price;
	this->sumNumber = sumNumber;
	this->nowNumber = nowNumber;
	this->appointNumber = appointNumber;
	this->borrowTimes = borrowTimes;
	this->ifReadOnly = ifReadOnly;
	this->lastBorrowTime = lastBorrowTime;
	this->library = library;
}

class LibrarySystem{
	private:
		void readFile();//read the file store the book information
	protected:
		vector<Book> books;

		virtual void printMessage() = 0;//pure virtual function
		virtual void printView()=0;//pure virtual function
	public:
		LibrarySystem();
		virtual ~LibrarySystem();

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


		void printMessage();//print out the message of student,override function
		void printView();
		//create the scene of student view and print out the choices, override function
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


		void printMessage();//override function
		void printView();//override function
		void addNewBook();//add new book
		void deleteBook();//delete book
		void updateBookInfo();//update the book information
};

int main() {
	//SetConsoleOutputCP(437);
	printf("%c\n",22);

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    
    cout << " - "<< endl; 
	return 0;
}

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

string getLocalTime()
{
	string time;//fill this function later

	return time;
}

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
		string lastBorrowTime;//last time this book was borrowed
		string library;//this book is in which library of University

	public:
		//fill constructors here
		Book(int,string,string,string,double,
				int,int,int,int,bool,string,string);
		~Book();
		//fill all the getter and setter
		//
		//
		//
		//
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

Book::~Book()
{
	//do nothing
}

class Student{
	private:
		string pawPrint;//id in the university
		string password;
		string name;//student name
		int historyBorrowNum;//book borrow number totally in history record
		string lastBorrowTime;//last time borrow book
		int holdNum;//how many book hold now
		vector<int> bookId;//store the id of book student borrowed
	public:
		Student(int,string,string,int,string,int,vector<int>);
		~Student();
		string getPawPrint(){return pawPrint;}
		void setPawPrint(string pawPrint){this->pawPrint = pawPrint;}
		string getPassword(){return password;}
		void setPassWord(string password){this->password = password;}
		//fill all the getter and setter
		//
		//
		//
};

Student::Student(int pawPrint,string password,string name,
		int historyBorrowNum,string lastBorrowTime,int holdNum,vector<int> bookId)
{
	this->pawPrint = pawPrint;
	this->password = password;
	this->name = name;
	this->historyBorrowNum = historyBorrowNum;
	this->lastBorrowTime = lastBorrowTime;
	this->holdNum = holdNum;
	this->bookId = bookId;
}

Student::~Student()
{
	bookId.clear();
}

class StudentList{
	private:
		vector<Student> list;

		void readFile();
	public:
		StudentList();
		~StudentList();
};

StudentList::StudentList()
{
	readFile();
}

StudentList::~StudentList()
{
	list.clear();
}

void StudentList::readFile()
{
	string fileName = "BookInfo.txt";
	ifstream in;
	in.open(fileName);
	if(!in.is_open()){
		cerr<<"File open failed!"<<endl;
	}

	char line[1024];
	while(!in.eof()){
		in.getline(line,sizeof(line),'\n');
		stringstream word(line);
		string pawPrint;
		word>>pawPrint;
		string password;
		word>>password;
		string name;
		word>>name;
		int historyBorrowNum;
		word>>historyBorrowNum;
		string lastBorrowTime;
		word>>lastBorrowTime;
		int holdNum;
		word>>holdNum;
		vector<int> bookId;
		for(int i = holdNum; holdNum > 0;--i){
			int temp;
			word>>temp;
			bookId.push_back(temp);
		}

		Student student(pawPrint,password,name,historyBorrowNum,
				lastBorrowTime,holdNum,bookId);
		list.push_back(student);
	}//read the file until end and put it in object Book
}

class LibrarySystem{
	private:
		void readFile();//read the file store the book information
	protected:
		vector<Book> bookList;

		virtual void printMessage() = 0;//pure virtual function
		virtual void printView() = 0;//pure virtual function
	public:
		LibrarySystem();
		virtual ~LibrarySystem();

};

LibrarySystem::LibrarySystem()
{
	readFile();//read book information from file and store them in vector books
}

LibrarySystem::~LibrarySystem()
{
	bookList.clear();//free the memory
}

void LibrarySystem::readFile()
{
	string fileName = "BookInfo.txt";
	ifstream in;
	in.open(fileName);
	if(!in.is_open()){
		cerr<<"File open failed!"<<endl;
	}

	char line[1024];
	while(!in.eof()){
		in.getline(line,sizeof(line),'\n');
		stringstream word(line);
		int id;
		word>>id;
		string name;
		word>>name;
		string author;
		word>>author;
		string category;
		word>>category;
		double price;
		word>>price;
		int sumNumber;
		word>>sumNumber;
		int nowNumber;
		word>>nowNumber;
		int appointNumber;
		word>>appointNumber;
		int borrowTimes;
		word>>borrowTimes;
		bool ifReadOnly;
		word>>ifReadOnly;
		string lastBorrowTime;
		word>>lastBorrowTime;
		string library;
		word>>library;//read information word by word

		Book book(id,name,author,category,price,sumNumber,nowNumber,
				appointNumber,borrowTimes,ifReadOnly,lastBorrowTime,library);
		bookList.push_back(book);//
	}//read the file until end and put it in object Book
}

class StudentSystem : public LibrarySystem{
	private:
		StudentList *studentList;
	public:
		//fill constructors here
		StudentSystem(StudentList*);
		~StudentSystem();
		void printMessage();//print out the message of student,override function
		void printView();
		//create the scene of student view and print out the choices, override function
		void borrowBook();//borrow a book
		void returnBook();//return a book
		void removeHistory();//delete borrow history
		void changePassword();//change the password of id
		void appointBook();//appoint a book if all were borrowed
};

StudentSystem::StudentSystem(StudentList* studentList)
{
	this->studentList = studentList;
}

StudentSystem::~StudentSystem()
{
	free(studentList);
}

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

StudentList* checkStudentIdentity(StudentList* studentList,string pawPrint,string password)
{
	int i = 0;
	while(studentList != NULL){
		if(studentList->list[i].pawPrint == pawPrint){
			if(studentList->list[i].password == password){
				return studentList;
			}//check if the paw print and password match
		}
		++i;
	}
	return NULL;
}//change to binary search later

int main() {
	StudentList studentList;
	int identityChoice;
	string pawPrint;
	string password;

	cout<<"1)Student log in enter 1 "<<endl;
	cout<<"2)Librarian log in enter 2"<<endl;
	cin>>identityChoice;

	if(identityChoice ==1 ){
		cout<<"Please enter your pawprint:";
		cin>>pawPrint;
		cout<<"Please enter your password:";
		cin>>password;
		if(checkStudentIdentity(&studentList,pawPrint,password) == NULL){
			cout<<"Your User ID and/or Password are invalid."<<endl;
		}
		else{
			cout<<"Welcome to library! What you want to do?"<<endl;
			//fill different options here
			//
			//
			//
		}
	}

	return 0;
}

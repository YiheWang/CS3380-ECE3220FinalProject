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
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <iterator>

using namespace std;
/*
ostream& formatDateTime(ostream& out, const tm& t, const char* fmt) {
    const time_put<char>& dateWriter = use_facet<time_put<char> >(out.getloc());
    int n = strlen(fmt);
    if (dateWriter.put(out, out, ' ', &t, fmt, fmt + n).failed()) {
        throw runtime_error("failure to format date time");
    }
    return out;
}
string dateTimeToString(const tm& t, const char* format) {
    stringstream s;
    formatDateTime(s, t, format);
    return s.str();
}

tm now() {
    time_t now = time(0);
    return *localtime(&now);
}

string getLocalTime(){
    
    string    s = dateTimeToString(now(), "%Y-%m-%d-%H:%M%p");
    return s;
}*/

string getLocalTime(){
	return "2018-4-23-10:23AM";
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
		//int appointNumber;//how many people appoint this book
		int borrowTimes;//how many times this book was borrowed
		bool ifReadOnly;//identify this book is read only or can be borrowed
		string lastBorrowTime;//last time this book was borrowed
		string library;//this book is in which library of University

	public:
		//fill constructors here
		Book();
		Book(int,string,string,string,double,
				int,int,int,bool,string,string);
		~Book();
		void printBookInfo();//print out book information
		int getId(){return id;}
		string getName(){return name;}
		string getAuthor(){return author;}
		string getCategory(){return category;}
		double getPrice(){return price;}
		int getSumNumber(){return sumNumber;}
		int getNowNumber(){return nowNumber;}
		//int getAppointNumber(){return appointNumber;}
		int getBorrowTimes(){return borrowTimes;}
		bool getIfReadOnly(){return ifReadOnly;}
		string getLastBorrowTime(){return lastBorrowTime;}
		string getLibrary(){return library;}
		void setNowNumber(int nowNumber){this->nowNumber = nowNumber;}
		//void setAppointNumber(int appointNumber){this->appointNumber = appointNumber;}
		void setLastBorrowTime(string lastBorrowTime){this->lastBorrowTime = lastBorrowTime;}
		//fill all the getter and setter
		//
		//
		//
		//
};

Book::Book()
{
	//do nothing
}

Book::Book(int id, string name, string author, string category, double price,
		int sumNumber, int nowNumber, int borrowTimes,
		bool ifReadOnly, string lastBorrowTime, string library){
	this->id = id;
	this->name = name;
	this->author = author;
	this->category = category;
	this->price = price;
	this->sumNumber = sumNumber;
	this->nowNumber = nowNumber;
	//this->appointNumber = appointNumber;
	this->borrowTimes = borrowTimes;
	this->ifReadOnly = ifReadOnly;
	this->lastBorrowTime = lastBorrowTime;
	this->library = library;
}

Book::~Book()
{
	//do nothing
}

void Book::printBookInfo()
{
    cout<<"id"<<id<<"name"<<name<<"author"<<author<<"category"<<category<<"price"<<price<<"sumNumber"<<sumNumber<<"nowNumber"<<nowNumber<<"borrowTimes"<<borrowTimes
    <<"ifReadOnly"<<ifReadOnly<<"lastBorrowTime"<<lastBorrowTime<<"library"<<library<<endl;
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
		Student();
		Student(string,string,string,int,string,int,vector<int>);
		~Student();
		string getPawPrint(){return pawPrint;}
		string getPassword(){return password;}
		string getName(){return name;}
		int getHistoryBorrowNum(){return historyBorrowNum;}
		string getLastBorrowTime(){return lastBorrowTime;}
		int getHoldNum(){return holdNum;}
		vector<int> getBookId(){return bookId;}
		void setPassWord(string password){this->password = password;}
		void setHistoryBorrowNum(int historyBorrowNum){this->historyBorrowNum = historyBorrowNum;}
		void setLastBorrowTime(string lastBorrowTime){this->lastBorrowTime = lastBorrowTime;}
		void setHoldNum(int holdNum){this->holdNum = holdNum;}
		void setBookId(vector<int> bookId){this->bookId = bookId;}
		//return or borrow book
		//
		//
		//

};

Student::Student()
{
	//do nothing
}

Student::Student(string pawPrint,string password,string name,int historyBorrowNum,string lastBorrowTime,int holdNum,vector<int> bookId)
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

class Librarian{
	private:
		string pawPrint;
		string password;
		string name;
	public:
		Librarian(string,string,string);
		~Librarian();
		string getPawPrint(){return pawPrint;}
		string getPassword(){return password;}
		string getName(){return name;}
		void setPawPrint(string pawPrint){this->pawPrint = pawPrint;}
		void setPassword(string password){this->password = password;}
		void setName(string name){this->name =name;}
};

Librarian::Librarian(string pawPrint,string password,string name)
{
	this->pawPrint = pawPrint;
	this->password = password;
	this->name = name;
}

Librarian::~Librarian()
{
	//do nothing
}

class StudentList{
	private:
		void readFile();
	public:
		vector<Student> list;
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
	string fileName = "StudentInfo.txt";
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

class LibrarianList{
	private:
		void readFile();
	public:
		vector<Librarian> list;
		LibrarianList();
		~LibrarianList();
};

LibrarianList::LibrarianList()
{
	readFile();
}

LibrarianList::~LibrarianList()
{
	list.clear();
}

void LibrarianList::readFile()
{
	string fileName = "LibrarianInfo.txt";
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

		Librarian librarian(pawPrint,password,name);
		list.push_back(librarian);
	}//read the file until end and put it in object Book
}

class LibrarySystem{
	private:
		void readFile();//read the file store the book information
	protected:
		vector<Book> bookList;

		virtual void printMessage() = 0;//pure virtual function
		virtual void printView() = 0;//pure virtual function
		virtual void updateFile() = 0;//update changed information into file
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
		int borrowTimes;
		word>>borrowTimes;
		bool ifReadOnly;
		word>>ifReadOnly;
		string lastBorrowTime;
		word>>lastBorrowTime;
		string library;
		word>>library;//read information word by word

		Book book(id,name,author,category,price,sumNumber,nowNumber,
				borrowTimes,ifReadOnly,lastBorrowTime,library);
		bookList.push_back(book);//
	}//read the file until end and put it in object Book
}

class StudentSystem : public LibrarySystem{
	private:
		StudentList *studentList;
		Student student;
		int indexInList;

		void searchBook();
		void borrowBook(int);//borrow a book
		void returnBook();//return a book
		void removeHistory();//delete borrow history
		void changePassword();//change the password of id
		void removeBook(vector<int> bookId, int index);//will be called in return book
	public:
		//fill constructors here
		StudentSystem(StudentList*,Student,int);
		~StudentSystem();
		void printMessage();//print out the message of student,override function
		void printView();//call private class method to show different choices
		//create the scene of student view and print out the choices, override function
		void updateFile();
};

StudentSystem::StudentSystem(StudentList* studentList, Student student, int indexInList)
{
	this->studentList = studentList;
	this->student = student;
	this->indexInList = indexInList;
}

StudentSystem::~StudentSystem()
{
	updateFile();//update all information(student, book)
	free(studentList);
}

void StudentSystem::searchBook()
{
	int searchType;
	Book book;
	cout<<"Search by id enter 1: ";
	cout<<"Search by name enter 2: ";
	cout<<"Search by category enter 3: ";
	cin>>searchType;
	if(searchType>3||searchType<1){
		cout<<"Search failed!"<<endl;
		return;
	}
	else{
		switch(searchType){
			case 1:{
				//search by id
				int id;
				cout<<"Please enter the book id";
				cin>>id;
				for(int i = 0; i < (int)bookList.size(); ++i){
						if(bookList[i].getId() == id){
						bookList[i].printBookInfo();
						borrowBook(i);
						}
				}//search by name
				break;
			}
			case 2:{
				string tempBookName;
				cout<<"Please enter the name as following format. "
						"Capitalize each single word and use '-' to"
						"connect each word like: Harry-Potter "<<endl;
				cout<<"Please enter the name of this book";
				cin>>tempBookName;
				for(int i = 0; i < (int)bookList.size(); ++i){
					if(bookList[i].getName() == tempBookName){
						bookList[i].printBookInfo();
						borrowBook(i);
					}
				}//search by name
				break;
			}
			case 3:{
				string category;
				int tempId;
				cout<<"Please enter the category of this book";
				cin>>category;
				for(int i = 0; i < (int)bookList.size(); ++i){
					if(bookList[i].getCategory() == category){
						bookList[i].printBookInfo();
					}
				}//print out all the match book
				cout<<"Which one you want to borrow? Please enter the book id:";
				cin>>tempId;
				borrowBook(tempId);
				break;
			}
		}
	}
}

void StudentSystem::returnBook()
{
	int tempId;
	vector<int> tempBookId;
	tempBookId = student.getBookId();
	cout<<"Here are the books you borrowed"<<endl;
	for(int i = 0; i < (int)tempBookId.size(); ++i){
		for(int j = 0; j < (int)bookList.size(); ++j){
			if(bookList[j].getId() == tempBookId[i]){
				bookList[j].printBookInfo();
			}
		}
	}
	cout<<"Which book you want to return? Please enter the book id";
	cin>>tempId;
	for(int k = 0; k < (int)bookList.size(); ++k){
		if(bookList[k].getId() == tempId){
			removeBook(student.getBookId(),k);
			//bookList[k].printBookInfo();
		}
	}
	cout<<"Return successfully!"<<endl;
}

void StudentSystem::removeBook(vector<int> bookId, int index)
{
	//int count = bookId.size() - index;
	for(int i = index; i < (int)bookId.size(); ++i){

	}
}

void StudentSystem::borrowBook(int id)
{
	int choice;
	int nowNumber = bookList[id].getNowNumber();
	if(nowNumber){
		cout<<"Do you want to borrow "<<bookList[id].getName()<<"? Yes:1, No:0";
		cin>>choice;
			if(choice == 1){
				student.getBookId().push_back(id);
				student.setHistoryBorrowNum(student.getHistoryBorrowNum() + 1);
				student.setLastBorrowTime(getLocalTime());
				bookList[id].setLastBorrowTime(getLocalTime());//update borrow time
				bookList[id].setNowNumber(--nowNumber);//update book number now
			}//borrow this book
			else{
				return;
			}
	}
	else{
		cout<<"All "<<bookList[id].getName()<<" were borrowed,"
				"you can connect librarian for further information"<<endl;
	}//All books were borrowed
}

void StudentSystem::updateFile()
{
	studentList->list[indexInList] = student;//update student information
	//update all student information
	ofstream out;
	//rewrite the file studentInfo with new student data
	//remember to upload the id
	//
	//
	//rewrite  the file bookInfo with new book data
	//remember to unload the id
	//
	//
}

void StudentSystem::printMessage()
{
	cout<<"This is your current status"<<endl;
	cout<<"Name: "<<student.getName()<<endl;
	cout<<"Total times you borrowed book"<<student.getHistoryBorrowNum()<<endl;
	cout<<"Last time borrowed book: "<<student.getLastBorrowTime()<<endl;
	cout<<"Number of books you hold: "<<student.getHoldNum()<<endl;
	cout<<"Here is name of books you keep: ";
	vector<int> bookId = student.getBookId();
	for(int i = 0; i<student.getHoldNum(); ++i){
		cout<<bookList[bookId[i]].getName()<<" ";
	}
	cout<<endl;
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

int checkStudentIdentity(StudentList* studentList,string pawPrint,string password)
{
	int i = 0;
	while(studentList != NULL){
		if(studentList->list[i].getPawPrint() == pawPrint){
			if(studentList->list[i].getPassword() == password){
				return i;
			}//check if the paw print and password match
		}
		++i;
	}
	return -1;
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
		int index = checkStudentIdentity(&studentList,pawPrint,password);
		if(index < 0){
			cout<<"Your User ID and/or Password are invalid."<<endl;
		}
		else{
			StudentSystem studentSystem(&studentList,studentList.list[index],index);
			cout<<"Welcome to library! What you want to do?"<<endl;

		}
	}

	return 0;
}

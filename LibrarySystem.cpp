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
		string lastBorrowTime;//last time this book was borrowed
		string library;//this book is in which library of University

	public:
		//fill constructors here
		Book();
		Book(int,string,string,string,double,
				int,int,int,string,string);
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
		string getLastBorrowTime(){return lastBorrowTime;}
		string getLibrary(){return library;}
		void setNowNumber(int nowNumber){this->nowNumber = nowNumber;}
		//void setAppointNumber(int appointNumber){this->appointNumber = appointNumber;}
		void setLastBorrowTime(string lastBorrowTime){this->lastBorrowTime = lastBorrowTime;}
        void operator+(const Book &book1);
    
    
		//fill all the getter and setter
		//
		//
		//
		//
};


//Book operator+( Book &book1,  Book &book2)
//{
//    Book sum;
//    sum.getPrice() = book1.getPrice() + book2.getPrice();
//    return sum;
//}


void Book::operator+(const Book &book1)
{
    this->price += book1.price;
}


Book::Book()
{
	//do nothing
}

Book::Book(int id, string name, string author, string category, double price,
		int sumNumber, int nowNumber, int borrowTimes,
		string lastBorrowTime, string library){
	this->id = id;
	this->name = name;
	this->author = author;
	this->category = category;
	this->price = price;
	this->sumNumber = sumNumber;
	this->nowNumber = nowNumber;
	//this->appointNumber = appointNumber;
	this->borrowTimes = borrowTimes;
	this->lastBorrowTime = lastBorrowTime;
	this->library = library;
}

Book::~Book()
{
	//do nothing
}

void Book::printBookInfo()
{
    cout<<"id:"<<id<<endl;
    cout<<" name:"<<name<<endl;
    cout<<" author:"<<author<<endl;
    cout<<" category:"<<category<<endl;
    cout<<" price:"<<price<<endl;
    cout<<" sumNumber:"<<sumNumber<<endl;
    cout<<" nowNumber:"<<nowNumber<<endl;
    cout<<" borrowTimes:"<<borrowTimes<<endl;
    cout<<" lastBorrowTime:"<<lastBorrowTime<<endl;
    cout<<" library:"<<library<<endl;
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
		void printStudentInfo();
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

void Student::printStudentInfo()
{
	cout<<"Student pawPrint: "<<pawPrint<<endl;
	cout<<"Student name: "<<name<<endl;
	cout<<"History borrow number: "<<historyBorrowNum<<endl;
	cout<<"Last time borrow: "<<lastBorrowTime<<endl;
	cout<<"Holding book number: "<<holdNum<<endl;
	cout<<"Borrowed books id: ";
	for(int i = 0; i < holdNum; ++i){
		cout<<bookId[i]<<" ";
	}
	cout<<endl<<endl;
}

class Librarian{
	private:
		string pawPrint;
		string password;
		string name;
	public:
		Librarian();
		Librarian(string,string,string);
		~Librarian();
		string getPawPrint(){return pawPrint;}
		string getPassword(){return password;}
		string getName(){return name;}
		void setPawPrint(string pawPrint){this->pawPrint = pawPrint;}
		void setPassword(string password){this->password = password;}
		void setName(string name){this->name =name;}
};

Librarian::Librarian()
{
	//do nothing
}

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
		throw 0;
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
		for(int i = 0; i < holdNum; ++i){
			int temp;
			word>>temp;
			bookId.push_back(temp);
		}


		Student student(pawPrint,password,name,historyBorrowNum,
				lastBorrowTime,holdNum,bookId);
		list.push_back(student);
		//student.printStudentInfo();
	}//read the file until end and put it in object Book
	in.close();
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
		throw 0;
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
	in.close();
}

class LibrarySystem{
	private:
		void readFile();//read the file store the book information
	protected:
		vector<Book> bookList;
	public:
		LibrarySystem();
		virtual ~LibrarySystem();
		virtual void printView() = 0;//pure virtual function
		virtual void printMessage() = 0;//pure virtual function
		virtual void updateFile() = 0;//update changed information into file
		virtual void dynamicBinding() = 0;

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
		throw 0;
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
		string lastBorrowTime;
		word>>lastBorrowTime;
		string library;
		word>>library;//read information word by word

		Book book(id,name,author,category,price,sumNumber,nowNumber,
				borrowTimes,lastBorrowTime,library);
		bookList.push_back(book);//
	}//read the file until end and put it in object Book
	in.close();
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
		void removeBook(vector<int> &, int);//will be called in return book
	public:
		//fill constructors here
		StudentSystem(StudentList*,Student,int);
		~StudentSystem();
		void printMessage();//print out the message of student,override function
		void printView();//call private class method to show different choices
		//create the scene of student view and print out the choices, override function
		void updateFile();
		void dynamicBinding();
};

StudentSystem::StudentSystem(StudentList* studentList, Student student, int indexInList)
{
	this->studentList = studentList;
	this->student = student;
	this->indexInList = indexInList;
}

StudentSystem::~StudentSystem()
{
	free(studentList);
}

void StudentSystem::dynamicBinding()
{
	cout<<"This is a dynamic binding!"<<endl<<endl;
}

void StudentSystem::printView()
{
	int choice;
	printMessage();
	do{
		cout<<"1)Search for books, enter 1:"<<endl;
		cout<<"2)Borrow books,enter 2:"<<endl;
		cout<<"3)Return books enter 3:"<<endl;
		cout<<"4)See my status enter 4:"<<endl;
		cout<<"5)Log out enter 5:"<<endl;
		cout<<"What you want to do now? Please enter the choice to select:";
		cin>>choice;
		if(choice == 1){
			searchBook();
		}//search and borrow books
		else if(choice == 2){
			int id;
			cout<<"Please enter the book id:";
			cin>>id;
			borrowBook(id);
		}//borrow books
		else if(choice == 3){
			returnBook();
		}//return books
		else if(choice == 4){
			printMessage();
		}
		else if(choice == 5){
			updateFile();//update all information(student, book)
			throw 'H';
			//break;
		}//log out
		else {
			cout<<"Wrong input! Please enter again:";
			cin>>choice;
		}
	}while(1);
}

void StudentSystem::searchBook()
{
	int searchType;
	Book book;
	cout<<"Search by id enter 1: "<<endl;
	cout<<"Search by name enter 2: "<<endl;
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
				cout<<"Please enter the book id:";
				cin>>id;
				for(int i = 0; i < (int)bookList.size(); ++i){
						if(bookList[i].getId() == id){
						bookList[i].printBookInfo();
						borrowBook(id);
						}
				}//search by name
				break;
			}
			case 2:{
				string tempBookName;
				cout<<"Please enter the name as following format. "
						"Capitalize each single word and use '-' to"
						"connect each word like: Harry-Potter "<<endl;
				cout<<"Please enter the name of this book:";
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
				cout<<"Please enter the category of this book:";
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
	vector<int> tempBookId = student.getBookId();
	cout<<"Here are the books you borrowed"<<endl<<endl;
	for(int i = 0; i < (int)tempBookId.size(); ++i){
		for(int j = 0; j < (int)bookList.size(); ++j){
			if(bookList[j].getId() == tempBookId[i]){
				cout<<"Book1"<<endl;
				bookList[j].printBookInfo();
				cout<<endl;
			}//print out the books you borrowed
		}
	}

	bool flag = false;//check if this book is in our borrowed list
	cout<<"Which book you want to return? Please enter the book id:";
	cin>>tempId;
	for(int k = 0; k < (int)tempBookId.size(); ++k){
		if(tempBookId[k] == tempId){
			flag = true;
			removeBook(tempBookId,k);
			student.setBookId(tempBookId);
			student.setHoldNum(student.getHoldNum() - 1);
			for(int j = 0; j < (int)bookList.size(); ++j){
					if(bookList[j].getId() == tempBookId[k]){
					bookList[j].setNowNumber(bookList[j].getNowNumber() + 1);
				}
			}
			//printMessage();
			//bookList[k].printBookInfo();
		}
	}
	if(flag){
		cout<<"Return successfully!"<<endl;
	}
	else{
		cout<<"This book is not the books you borrowed!"<<endl;
	}
}

void StudentSystem::removeBook(vector<int> &bookId, int index)
{
	//int count = bookId.size() - index;
	for(int i = index; i < (int)bookId.size(); ++i){
		bookId[i] = bookId[i+1];
	}
	bookId.pop_back();
}

void StudentSystem::borrowBook(int id)
{
	int choice;
	int nowNumber = bookList[id].getNowNumber();
	if(nowNumber){
		cout<<"Do you want to borrow "<<bookList[id].getName()<<"? Yes:1, No:0:";
		cin>>choice;
			if(choice == 1){
				vector<int> temp = student.getBookId();
				//student.getBookId().push_back(id);
				temp.push_back(id);
				cout<<"new id is:"<<temp[3]<<endl;
				student.setBookId(temp);
				student.setHistoryBorrowNum(student.getHistoryBorrowNum() + 1);
				student.setHoldNum(student.getHoldNum() + 1);
				//student.setLastBorrowTime(getLocalTime());
				//bookList[id].setLastBorrowTime(getLocalTime());//update borrow time
				bookList[id].setNowNumber(--nowNumber);//update book number now
				cout<<"Borrow successfully!"<<endl;
				printMessage();
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
	//update student information
	//update all student information
	//rewrite the file studentInfo with new student data
	//remember to upload the id
	//
	//
	//rewrite  the file bookInfo with new book data
	//remember to unload the id
	//
	//
    studentList->list[indexInList] = student;
    
    string fileName1 = "StudentInfo.txt";

    ofstream outFS1;
    outFS1.open(fileName1,ios::trunc);
    if(!outFS1.is_open()){
        cout<<" Can not open File "<<fileName1<<"."<<endl;
    }
    int i;
    for(i = 0; i < (int)studentList->list.size(); ++i){
        outFS1<<studentList->list[i].getPawPrint()<<" ";
        outFS1<<studentList->list[i].getPassword()<<" ";
        outFS1<<studentList->list[i].getName()<<" ";
        outFS1<<studentList->list[i].getHistoryBorrowNum()<<" ";
        outFS1<<studentList->list[i].getLastBorrowTime()<<" ";
        outFS1<<studentList->list[i].getHoldNum()<<" ";//rewrite all the information in order
        vector<int> tempId = studentList->list[i].getBookId();
        for(int j = 0;  j < (int)tempId.size(); ++j){
            outFS1<<tempId[j]<<" ";
        }//rewrite all the borrowed books in order
        if(i != (int)studentList->list.size() -1){
        	outFS1<<endl;
        }
    }
    outFS1.close();


    ofstream outFS2;
    string fileName2 = "BookInfo.txt";
    outFS2.open(fileName2,ios::trunc);
    //delete all the stuffs in file first
    //then rewrite all the stuffs in the file
    int j;
    for(j = 0; j < (int)bookList.size(); ++j){
        outFS2<<bookList[j].getId()<<" ";
        outFS2<<bookList[j].getName()<<" ";
        outFS2<<bookList[j].getAuthor()<<" ";
        outFS2<<bookList[j].getCategory()<<" ";
        outFS2<<bookList[j].getPrice()<<" ";
        outFS2<<bookList[j].getSumNumber()<<" ";
        outFS2<<bookList[j].getNowNumber()<<" ";
        outFS2<<bookList[j].getBorrowTimes()<<" ";
        outFS2<<bookList[j].getLastBorrowTime()<<" ";
        outFS2<<bookList[j].getLibrary()<<" ";
        if(j != (int)bookList.size() -1){
        	outFS2<<endl;
        }
    }
    outFS2.close();
}

void StudentSystem::printMessage()
{
	cout<<"This is your current status"<<endl;
	cout<<"Name: "<<student.getName()<<endl;
	cout<<"Total times you borrowed book: "<<student.getHistoryBorrowNum()<<endl;
	cout<<"Last time borrowed book: "<<student.getLastBorrowTime()<<endl;
	cout<<"Number of books you hold: "<<student.getHoldNum()<<endl;
	cout<<"Here is name of books you keep: ";
	vector<int> bookId = student.getBookId();
	for(int i = 0; i<student.getHoldNum(); ++i){
		for(int j = 0; j <(int)bookList.size(); ++j){
			if(bookList[j].getId() == bookId[i]){
				cout<<bookList[j].getName()<<" ";
			}
		}

	}
	cout<<endl;
}

class LibrarianSystem : public LibrarySystem{
	private:
		LibrarianList *librarianList;
		Librarian librarian;
		int indexInList;

		void addNewBook();//add new book
		void deleteBook();//delete book
		void updateFile();//update the book information
	public:
		//fill constructors here
		LibrarianSystem(LibrarianList*,Librarian,int);
		~LibrarianSystem();

		void printMessage();//override function
		void printView();//override function
		void dynamicBinding();

};

LibrarianSystem::LibrarianSystem(LibrarianList* librarianList, Librarian librarian, int indexInList)
{
	this->librarianList = librarianList;
	this->librarian = librarian;
	this->indexInList = indexInList;
}

LibrarianSystem::~LibrarianSystem()
{
	free(librarianList);
}

void LibrarianSystem::dynamicBinding()
{
	cout<<"This is a dynamic binding!"<<endl<<endl;
}

void LibrarianSystem::printView()
{
	int choice;
	printMessage();
	do{
		cout<<"1)Add new book, enter 1:"<<endl;
		cout<<"2)Delete book,enter 2:"<<endl;
		cout<<"3)Log out enter 3:"<<endl;
		cout<<"What you want to do now? Please enter the choice to select:";
		cin>>choice;
		if(choice == 1){
			addNewBook();
		}//search and borrow books
		else if(choice == 2){
			deleteBook();
		}//borrow books
		else if(choice == 3){
			updateFile();//update all information(librarian, book)
			throw 'H';
		}//return books
		else {
			cout<<"Wrong input! Please enter again:";
			cin>>choice;
		}
	}while(1);
}

void LibrarianSystem::addNewBook()
{
	int choice;

	int id;
	string name;
	string author;
	string category;
	double price;
	int sumNumber;
	int nowNumber;
	int borrowTimes;
	string lastBorrowTime;
	string library;
	cout<<"Please enter the new book information:"<<endl;
	cout<<"id:";
	cin>>id;
	cout<<"name:";
	cin>>name;
	cout<<"author:";
	cin>>author;
	cout<<"category:";
	cin>>category;
	cout<<"price:";
	cin>>price;
	cout<<"sumNumber:";
	cin>>sumNumber;
	cout<<"nowNumber:";
	cin>>nowNumber;
	cout<<"borrowTimes:";
	cin>>borrowTimes;
	cout<<"lastBorrowTime:";
	cin>>lastBorrowTime;
	cout<<"library:";
	cin>>library;
	cout<<endl;
	Book book(id,name,author,category,price,sumNumber,nowNumber,
							borrowTimes,lastBorrowTime,library);
	book.printBookInfo();
	cout<<"Add this book? Yes:1, No:0 :";
	cin>>choice;
	if(choice == 1){
		bookList.push_back(book);
		cout<<"Add successfully!"<<endl;
	}
	else if(choice == 0){
		return;
	}
}

void LibrarianSystem::deleteBook()
{

}

void LibrarianSystem::updateFile()
{
	librarianList->list[indexInList] = librarian;

	string fileName1 = "LibrarianInfo.txt";

	ofstream outFS1;
	outFS1.open(fileName1,ios::trunc);
	if(!outFS1.is_open()){
	    cout<<" Can not open File "<<fileName1<<"."<<endl;
	}
		int i;
	    for(i = 0; i < (int)librarianList->list.size(); ++i){
	        outFS1<<librarianList->list[i].getPawPrint()<<" ";
	        outFS1<<librarianList->list[i].getPassword()<<" ";
	        outFS1<<librarianList->list[i].getName()<<" ";
	        if(i != (int)librarianList->list.size() -1){
	             outFS1<<endl;
	        }
	    }
	    outFS1.close();


	    ofstream outFS2;
	    string fileName2 = "BookInfo.txt";
	    outFS2.open(fileName2,ios::trunc);
	    //delete all the stuffs in file first
	    //then rewrite all the stuffs in the file

	    int j;
	    for(j = 0; j < (int)bookList.size(); ++j){
	        outFS2<<bookList[j].getId()<<" ";
	        outFS2<<bookList[j].getName()<<" ";
	        outFS2<<bookList[j].getAuthor()<<" ";
	        outFS2<<bookList[j].getCategory()<<" ";
	        outFS2<<bookList[j].getPrice()<<" ";
	        outFS2<<bookList[j].getSumNumber()<<" ";
	        outFS2<<bookList[j].getNowNumber()<<" ";
	        outFS2<<bookList[j].getBorrowTimes()<<" ";
	        outFS2<<bookList[j].getLastBorrowTime()<<" ";
	        outFS2<<bookList[j].getLibrary()<<" ";
	        if(j != (int)bookList.size() -1){
	              outFS2<<endl;
	        }
	    }
	    outFS2.close();
}

void LibrarianSystem::printMessage()
{

}

int checkIdentity(StudentList &studentList,string pawPrint,string password)
{
	int size = studentList.list.size();
	for(int i = 0; i < size; ++i){
		if(studentList.list[i].getPawPrint() == pawPrint){
			if(studentList.list[i].getPassword() == password){
				return i;
			}//check if the paw print and password match
		}
	}
	return -1;
}//change to binary search later

int checkIdentity(LibrarianList &librarianList,string pawPrint,string password)
{
	int size = librarianList.list.size();
		for(int i = 0; i < size; ++i){
			if(librarianList.list[i].getPawPrint() == pawPrint){
				if(librarianList.list[i].getPassword() == password){
					return i;
				}//check if the paw print and password match
			}
		}
	return -1;
}

int main() {
	StudentList studentList;
	LibrarianList librarianList;
	LibrarySystem *librarySystem = (LibrarySystem *)malloc(sizeof(LibrarySystem));
	int identityChoice;
	string pawPrint;
	string password;


	cout<<"Welcome to MU library system!"<<endl;
	cout<<"1)Student log in enter 1:"<<endl;
	cout<<"2)Librarian log in enter 2:";
	cin>>identityChoice;

	cout<<"Please enter your pawprint:";
	cin>>pawPrint;
	cout<<"Please enter your password:";
	cin>>password;

	if(identityChoice == 1 ){
		int index = checkIdentity(studentList,pawPrint,password);
		if(index < 0){
			cout<<"Your User ID and/or Password are invalid."<<endl;
			return 0;
		}

		try{
		StudentSystem studentSystem(&studentList,studentList.list[index],index);
		cout<<"Welcome to library! What you want to do?"<<endl;
		librarySystem = &studentSystem;
		librarySystem->dynamicBinding();
		studentSystem.printView();
		}catch(int){
			cout<<"File open falied!"<<endl;
		}catch(char){
			cout<<"Log out successfully!"<<endl;
		}catch(...){
			cout<<"general exception"<<endl;
		}

	}
	else if(identityChoice == 2){
		int index = checkIdentity(librarianList,pawPrint,password);
		if(index < 0){
			cout<<"Your User ID and/or Password are invalid."<<endl;
			return 0;
		}

		try{
		LibrarianSystem librarianSystem(&librarianList,librarianList.list[index],index);
		cout<<"Welcome to library! What you want to do?"<<endl;
		librarySystem = &librarianSystem;
		librarySystem->dynamicBinding();
		librarianSystem.printMessage();
		librarianSystem.printView();
		}catch(int){
			cout<<"File open falied!"<<endl;
		}catch(char){
			cout<<"Log out successfully!"<<endl;
		}catch(...){
			cout<<"general exception"<<endl;
		}

	}

	cout<<"Have a nice day!"<<endl;

	return 0;
}

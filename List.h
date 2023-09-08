#pragma once

#include<fstream>
#include"Abonent.h"

#define tab "\t"
#define DELIMITER cout << "\n/////////////////////////////////////////////////////////////////////////\n"

//#define DEBUG
//#define Check_Push_Pop
#define Check_Insert_Delete
//#define Check_Constructors

using namespace std;

template<typename T> class List;

template<typename T>
class Element
{
	T Data;

	Element<T>* pNext;
	Element<T>* pPrev;

public:
	Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);

	~Element();

	friend class List<T>;
};

template<typename T>
class List
{
	Element<T>* Head;
	Element<T>* Tail;
	int size;

public:

	List();

	~List();

	int List<T>::GetSize() const;

	List(const List& other);

	List(List&& other);

	//////////////////////////////////// OPERATORS ////////////////////////////////////

	List& operator= (const List& other);
	List& operator= (List&& other);
	List operator+ (const List& other);
	T& List<T>::operator[](int index);

	///////////////////////////////////// METHODS /////////////////////////////////////

	void push_front(T Data);
	void push_back(T Data);

	void pop_front();
	void pop_back();

	void Insert(int index, T Data);
	void Delete(int index);

	void Print();
	void Print_reverse();

	void Save();
	void Load(char* name);

	friend class String;
	friend class Abonent;
};
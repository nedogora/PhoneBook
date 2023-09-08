#pragma once
#include<iostream>
#include<windows.h>


using namespace std;

//#define DEBUG

class String
{
	char* Str;
	int size;

public:
	String(int size = 80);//Прототип метода
	String(char* String);
	String(const String& other);
	String(String&& other);

	~String();

	////////////////////////////////////  Get/Set  /////////////////////////////////////

	char* GetStr();
	int GetS() const;

	/////////////////////////////////// 	OPERATORS	////////////////////////////////////

	String& operator=(const String& other);
	String operator+(const String& other);
	String& operator=(String&& other);

	////////////////////////////////////////////////////////////////////////////////////

	int Strlen(char Str[]);
	void Print();
	String& Truncate();
	char& operator *();

	bool operator==(/*const*/ String& other);
	bool operator !=(const String& other);

	friend ostream& operator<<(ostream& os, const String& obj);
	friend istream& operator>>(istream& is, String& obj);
	//friend ofstream& operator<<(ofstream& ofs, const String obj);
	//friend ifstream& operator>>(ifstream& ifs, String& obj);
	friend class Abonent;
};
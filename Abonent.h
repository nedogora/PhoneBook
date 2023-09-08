#pragma once

#include<fstream>
#include"String.h"

//#define DEBUG
#define tab "\t"

class Abonent
{
	String surname;
	String name;
	String phone;

public:
	Abonent();
	explicit Abonent(String surname, String name, String phone);
	~Abonent();

	Abonent& operator=(const Abonent& other);

	String GetSurname();
	String GetName() const;
	String GetPhone() const;

	friend ostream& operator<<(ostream& os, const Abonent& obj);
	friend istream& operator>>(istream& is, Abonent& obj);
	friend ofstream& operator<<(ofstream& ofs, const Abonent& obj);
	//friend ifstream& operator>>(ifstream& ifs, Abonent& obj);
};

//ostream& operator<<(ostream& os, const Abonent& obj);
//istream& operator>>(istream& is, Abonent& obj);
//ofstream& operator<<(ofstream& ofs, const Abonent& obj);
//ifstream& operator>>(ifstream& ifs, Abonent& obj);
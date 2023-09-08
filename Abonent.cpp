#include "List.h"
#include "String.h"
#include "Abonent.h"

Abonent::Abonent()
{
	/*this->surname = String{};
	this->name = String{};
	this->phone = String{};*/
	this->surname;
	this->name;
	this->phone;
}

Abonent::Abonent(String surname, String name, String phone) :surname(surname), name(name), phone(phone)
{
	/*this->surname = surname;
	this->name = name;
	this->phone = phone;*/

#ifdef DEBUG
	cout << "AConstructor:" << tab << this << endl;
#endif // DEBUG
}
Abonent::~Abonent()
{
#ifdef DEBUG
	cout << "ADestructor:" << tab << this << endl;
#endif
}

Abonent& Abonent::operator=(const Abonent& other)
{
	this->surname = other.surname;
	this->name = other.name;
	this->phone = other.phone;
	
	return *this;
}

String Abonent::GetSurname()
{
	return this->surname;
}
String Abonent::GetName() const
{
	return this->name;
}
String Abonent::GetPhone() const
{
	return this->phone;
}

ostream& operator<<(ostream& os, const Abonent& obj)
{
	os << obj.surname << tab;
	os << obj.name << tab;
	os << obj.phone;

	return os;
}


istream& operator>>(istream& is, Abonent& obj)
{
	is >> obj.surname;
	is >> obj.name;
	is >> obj.phone;

	return is;
}

ofstream& operator<<(ofstream& ofs, const Abonent& obj)
{
	ofs << obj.surname << tab;
	ofs << obj.name << tab;
	ofs << obj.phone << endl;

	return ofs;
}

//ifstream& operator>>(ifstream& ifs, Abonent& obj)
//{
//	ifs.getline(obj.surname, obj.surname.GetS(), '\t');
//	ifs.getline(obj.name, obj.name.GetS(), '\t');
//	ifs.getline(obj.phone, obj.phone.GetS(), '\n');
//	return ifs;
//}
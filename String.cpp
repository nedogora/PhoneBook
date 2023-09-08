#include "String.h"
#include "List.h"
#include "Abonent.h"
//#include "Abonent.cpp"

String::String(int size) //Реализация метода
{
	this->size = size;
	Str = new char[size]{};

#ifdef DEBUG
	cout << "SSizeConstructor:" << tab << this << endl;
#endif // DEBUG

}

String::String(char* String)
{
	size = Strlen(String);
	//cout << size;
	this->Str = new char[size + 1]{};
	for (int i = 0; i < size; i++) Str[i] = String[i];

#ifdef DEBUG
	cout << "SConstructor:" << tab << this << endl;
#endif
}

String::String(const String& other)
{
	this->size = other.size;
	this->Str = new char[size + 1]{};
	for (int i = 0; i < size; i++) this->Str[i] = other.Str[i];

#ifdef DEBUG
	cout << "SCopyConstructor:" << tab << this << endl;
#endif // DEBUG

}

String::String(String&& other)
{
	this->size = other.size;
	this->Str = other.Str;
	other.Str = nullptr;

#ifdef DEBUG
	cout << "SMoveConstructor:" << tab << this << endl;
#endif
}

String::~String()
{
	delete[] Str;

#ifdef DEBUG
	cout << "SDestructor:" << tab << this << endl;
#endif // DEBUG

}

/////////////////////////////////////////////////////////////////////

char* String::GetStr()
{
	return this->Str;
}
int  String::GetS() const
{
	return this->size;
}

/////////////////////////////////////////////////////////////////////

String& String::operator=(const String& other)
{
	this->size = other.size;
	delete[] Str;
	Str = new char[size + 1]{};
	for (int i = 0; i < size; i++) this->Str[i] = other.Str[i];

#ifdef DEBUG
	cout << "SCopyAssignment:" << tab << this << endl;
#endif
	return *this;
}

String String::operator+(const String& other)
{
	String Temp;
	Temp.size = this->size + other.size + 1;
	for (int i = 0; i < this->size; i++) Temp.Str[i] = this->Str[i];
	for (int i = this->size; i < this->size + other.size; i++) Temp.Str[i] = other.Str[i - this->size];
	return Temp;
}

String& String::operator=(String&& other)
{
	delete[] Str;
	this->size = other.size;
	this->Str = other.Str;
	other.Str = nullptr;

#ifdef DEBUG
	cout << "SMoveAssignment:" << tab << this << endl;
#endif // DEBUG

	return *this;
}
/////////////////////////////////////////////////////////////////////

int String::Strlen(char Str[])
{
	int size = 0;
	for (; Str[size]; size++);
	return size;
}

void String::Print()
{
	cout << Str << endl;
}

String& String::Truncate()
{
	//
	//	/*this->size = this->Strlen(this->GetStr()) + 1;
	//	this->Str = GetStr();
	//	return *this;*/
	//
	//	this->size = this->Strlen(this->GetStr()) + 1;
	//	for (int i = 0; i < this->size; i++)
	//	this->Str[i] = this->GetStr()[i];
	//	return *this;
	//
	//	//String Temp;
	//	//Temp.size = this->Strlen(this->GetStr())+1;
	//	//for (int i = 0; i < Temp.size; i++) Temp.Str[i] = this->Str[i];
	//	////delete this->Str;
	//	//return Temp;
	//
	//	///*this->size = Temp.size;
	//	//this->Str = Temp.Str;*/
	//
	//	///*delete Temp;
	//	//return *this;*/
	this->size = Strlen(this->Str);
	char* Truncated = new char[size + 1]{};
	for (int i = 0; i < size; i++)Truncated[i] = Str[i];
	delete[] this->Str;
	this->Str = Truncated;
	return *this;
}

char& String::operator *()
{
	return *this->Str;
}

bool String::operator==(/*const*/ String& other)
{
	this->Truncate();
	other.Truncate();
	if (this->size != other.size)return false;
	for (int i = 0; i < this->Strlen(Str); i++) if (this->Str[i] != other.Str[i]) return false;
	return true;
}

bool String::operator!=(const String& other)
{
	for (int i = 0; i < this->size; i++) if (this->Str[i] != other.Str[i]) return true;
	return false;
}

/////////////////////////////////////////////////////////////////////

//		cin/cout

ostream& operator<<(ostream& os, const String& obj)
{

	//for (int i = 0; i < obj.size; i++) cout << obj.Str[i];
	os << obj.Str;
	//cout << endl;

	return os;
}

istream& operator>>(istream& is, String& obj)
{
	SetConsoleCP(1251);
	is >> obj.Str;
	SetConsoleCP(866);
	return is;
}

//ofstream& operator<<(ofstream& ofs, const String obj)
//{
//	ofs.open("DataBase.txt");
//	//for (int i = 0; i < obj.size; i++) cout << obj.Str[i];
//	ofs << obj.Str;
//	//cout << endl;
//
//	return ofs;
//}

//ifstream& operator>>(ifstream& ifs, String& obj)
//{
//	SetConsoleCP(1251);
//	ifs >> obj.Str;
//	SetConsoleCP(866);
//	return ifs;
//}
#include<iostream>
#include<conio.h>
#include<fstream>

#include "String.h"
#include "List.h"
#include "List.cpp"
#include "Abonent.h"

using namespace std;

#define tab "\t"

void PrintMenu(char* Menu[], int position);
template <typename T>
void Print(List<T> li);
template <typename T>
void Add_Contact(List<T>& li);
template <typename T>
void Print_List(List<T> li, int position);
template <typename T>
void Del_Contact(List<T>& li);
template <typename T>
void SaveToBase(List<T>& li);
template <typename T>
void LoadFromBase(List<T>& li);
template <typename T>
void Print_Search(List<T> li, int position);
template <typename T>
void Search(List<T> li);
template <typename T>
void Edit(List<T>& li);

void main()
{
	setlocale(LC_ALL, "Rus");

	int position = 0;
	char key;
	List<Abonent> Phonebook;
	Phonebook.push_back(Abonent("Иванов", "Иван", "0532667788"));
	Phonebook.push_back(Abonent("Дурко", "Василий", "05321112233"));
	/*Phonebook.Load();
	system("PAUSE");*/
	char* Menu[]
	{
		" 1. Вывод  на экран   ",
			" 2. Добавить абонента ",
			" 3. Удалить абонента  ",
			" 4. Найти абонента    ",
			" 5. Изменить абонента ",
			" 6. Сохранить в базу  ",
			" 7. Загрузить из базы "
	};

	do
	{
		PrintMenu(Menu, position);
		key = _getch();
		if (key == 27) return;
		switch (key)
		{
		case 72:
		case 'w':if (position != 0) position--; break;
		case 80:
		case 's':if (position != 6) position++; break;
		default: break;
		}
		if (key == 13)
		{
			switch (position)
			{
			case 0: Print(Phonebook); break;
			case 1: Add_Contact(Phonebook); break;
			case 2: Del_Contact(Phonebook); break;
			case 3: Search(Phonebook); break;
			case 4: Edit(Phonebook); break;
			case 5: SaveToBase(Phonebook); break;
			case 6: LoadFromBase(Phonebook); break;
			}
		}
	} while (true);
}

void PrintMenu(char** Menu, int position)
{
	system("CLS");
	cout << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << tab << tab << tab << tab;
		if (i == position) cout << '[';
		else cout << " ";

		cout << Menu[i];

		if (i == position) cout << ']';
		cout << endl;
	}
	cout << endl;
}

template<typename T>
void Print(List<T> li)
{
	system("CLS");
	li.Print();

	cout << endl;
	cout << "Для выхода в главное меню нажмите любую клавишу.";
	if (_getch()) return;
}

template<typename T>
void Add_Contact(List<T>& li)
{
	system("CLS");

	String name, surname, phone;
	cout << "Введите фамилию:" << tab; cin >> surname;
	cout << "Введите имя:" << tab; cin >> name;
	cout << "Введите номер телефона:" << tab; cin >> phone;
	for (int i = 0; i < phone.Strlen(phone.GetStr()) + 1; i++)
	{
		if (phone.GetStr()[i]>'0'&& phone.GetStr()[i]<'9')
		{
			Abonent New(surname, name, phone);
			li.push_back(New);
			break;
		}
		else return;
	}
}

template <typename T>
void Print_List(List<T> li, int position)
{
	system("CLS");
	cout << endl;
	for (int i = 0; i < li.GetSize(); i++)
	{
		cout << tab << tab << tab << tab;
		if (i == position) cout << '[';
		else cout << " ";

		cout << li[i];

		if (i == position) cout << ']';
		cout << endl;
	}

	cout << endl;
	cout << "Для выхода в главное меню нажмите Esc.";
}

template <typename T>
void Del_Contact(List<T>& li)
{
	//system("CLS");
	int position = 0;

	char key;
	do
	{
		Print_List(li, position);
		key = _getch();
		if (key == 27) return;
		switch (key)
		{
		case 72:
		case 'w':if (position != 0) position--; break;
		case 80:
		case 's':if (position != li.GetSize() - 1) position++; break;
		default: break;
		}
		if (key == 13) li.Delete(position);

	} while (true);

}

template <typename T>
void SaveToBase(List<T>& li)
{
	li.Save();

	cout << "Для выхода в главное меню нажмите любую клавишу.";
	if (_getch()) return;
}

template <typename T>
void LoadFromBase(List<T>& li)
{
	system("CLS");
	const int n = 256;
	char name[n] = {};
	cout << "Введите название файла:" << tab; cin >> name;
	li.Load(name);
}

void Print_Search(char** SearchMenu, int position)
{
	system("CLS");
	cout << "По какому полю искать:" << endl;
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << tab << tab << tab << tab;
		if (i == position) cout << '[';
		else cout << " ";

		cout << SearchMenu[i];

		if (i == position) cout << ']';
		cout << endl;
	}

	cout << endl;
	cout << "Для выхода в главное меню нажмите Esc.";
}

template <typename T>
void Search(List<T> li)
{
	system("CLS");
	char* SearchMenu[]
	{
		" 1. Фамилия       ",
			" 2. Имя           ",
			" 3. Номер телефона"
	};

	int position = 0;

	char key;
	do
	{
		Print_Search(SearchMenu, position);
		key = _getch();
		if (key == 27) return;
		switch (key)
		{
		case 72:
		case 'w':if (position != 0) position--; break;
		case 80:
		case 's':if (position != 2) position++; break;
		default: break;
		}
		if (key == 13)
		{
			switch (position)
			{
			case 0:
			{
					  system("CLS");
					  String sur;
					  cout << "Введите фамилию абонента:" << tab; cin >> sur;

					  for (int i = 0; i < li.GetSize(); i++)
					  {
						  //sur.Truncate();
						  if (sur == li[i].GetSurname())
						  {
							  cout << li[i].GetSurname() << tab;
							  cout << li[i].GetName() << tab;
							  cout << li[i].GetPhone() << endl;
							  continue;
						  }
						  /*else
						  {
						  cout << endl;
						  cout << "Такого абонента не существует." << endl;
						  cout << endl;
						  break;
						  }*/
					  }
					  cout << "Для выхода в главное меню нажмите любую клавишу.";
					  if (_getch()) return;
					  //break;
			}
			case 1:
			{
					  system("CLS");
					  String name;
					  cout << "Введите имя абонента:" << tab; cin >> name;

					  //name.Truncate();
					  for (int i = 0; i < li.GetSize(); i++)
					  {
						  if (name == li[i].GetName())
						  {
							  cout << li[i].GetSurname() << tab;
							  cout << li[i].GetName() << tab;
							  cout << li[i].GetPhone() << endl;
							  continue;
						  }
						  /*else
						  {
						  cout << endl;
						  cout << "Такого абонента не существует." << endl;
						  cout << endl;
						  break;
						  }*/
					  }
					  cout << "Для выхода в главное меню нажмите любую клавишу.";
					  if (_getch()) return;
					  //break;
			}
			case 2:
			{
					  system("CLS");
					  String phone;
					  cout << "Введите номер телефона абонента:" << tab; cin >> phone;

					  //phone.Truncate();
					  for (int i = 0; i < li.GetSize(); i++)
					  {
						  if (phone == li[i].GetPhone())
						  {
							  cout << li[i].GetSurname() << tab;
							  cout << li[i].GetName() << tab;
							  cout << li[i].GetPhone() << endl;
							  continue;
						  }
						  /*else
						  {
						  cout << endl;
						  cout << "Такого абонента не существует." << endl;
						  cout << endl;
						  break;
						  }*/
					  }
					  cout << "Для выхода в главное меню нажмите любую клавишу.";
					  if (_getch()) return;
					  //break;
			}
			}
		}
	} while (true);

	//sur.Truncate();

	cout << endl;
	cout << "Для выхода в главное меню нажмите Esc.";

	//system("CLS");
	//String sur;
	//cout << "Введите фамилию абонента:" << tab; cin >> sur;

	//for (int i = 0; i < li.GetSize(); i++)
	//{
	//	if (sur == li[i].GetSurname())
	//	{
	//		cout << li[i].GetSurname() << tab;
	//		cout << li[i].GetName() << tab;
	//		cout << li[i].GetPhone() << endl;
	//		continue;

	//	}
	//	/*else
	//	{
	//		cout << endl;
	//		cout << "Такого абонента не существует." << endl;
	//		cout << endl;
	//		break;
	//	}*/
	//}
	//cout << "Для выхода в главное меню нажмите любую клавишу.";
	//if (_getch()) return;
}

template <typename T>
void Edit(List<T>& li)
{
	system("CLS");

	int position = 0;

	char key;
	do
	{
		Print_List(li, position);
		key = _getch();
		if (key == 27) return;
		switch (key)
		{
		case 72:
		case 'w':if (position != 0) position--; break;
		case 80:
		case 's':if (position != li.GetSize() - 1) position++; break;
		default: break;
		}
		if (key == 13) break;
	} while (true);

	system("CLS");
	String name, surname, phone;
	cout << "Введите фамилию:" << tab; cin >> surname;
	cout << "Введите имя:" << tab; cin >> name;
	cout << "Введите номер телефона:" << tab; cin >> phone;

	Abonent Temp(surname, name, phone);
	li[position] = Temp;
}
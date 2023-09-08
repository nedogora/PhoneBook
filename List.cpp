#include "String.h"
#include "List.h"

template<typename T>
Element<T>::Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr)
{
	this->Data = Data;
	this->pNext = pNext;
	this->pPrev = pPrev;

#ifdef DEBUG
	cout << "EConstructor:" << tab << this << endl;
#endif // DEBUG

}

template<typename T>
Element<T>::~Element()
{
#ifdef DEBUG
	cout << "EDestructor:" << tab << this << endl;
#endif
}

template<typename T>
List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;

#ifdef DEBUG
	cout << "LConstructor:" << tab << this << endl;
#endif // DEBUG

}

template<typename T>
List<T>::~List()
{
	while (Head)pop_front();

#ifdef DEBUG
	cout << "LDestructor:" << tab << this << endl;
#endif
}

template<typename T>
int List<T>::GetSize() const
{
	return this->size;
}

template<typename T>
List<T>::List(const List& other)
{
	this->Head = this->Tail = nullptr;
	this->size = 0;
	Element<T>* Temp = other.Head;

	while (Temp)
	{
		this->push_back(Temp->Data);
		Temp = Temp->pNext;
	}

#ifdef DEBUG
	cout << "LCopyConstructor:" << tab << this << endl;
#endif // DEBUG

}

template<typename T>
List<T>::List(List&& other)
{
	this->size = other.size;
	this->Head = other.Head;
	this->Tail = other.Tail;
	other.Head = other.Tail = nullptr;
	other.size = nullptr;

#ifdef DEBUG
	cout << "LMoveConstructor:" << tab << this << endl;
#endif // DEBUG

}

template<typename T>
List<T>& List<T>::operator= (const List& other)
{
	while (this->Head != nullptr) this->pop_front();

	Element<T>* Temp = other.Head;
	while (Temp)
	{
		push_back(Temp->Data);
		Temp = Temp->pNext;
	}

#ifdef DEBUG
	cout << "LCopyAssignment:" << tab << this << endl;
#endif // DEBUG


	return *this;
}

template<typename T>
List<T>& List<T>::operator=(List&& other)
{
	while (this->Head != nullptr) this->pop_front();
	this->size = other.size;
	this->Head = other.Head;
	this->Tail = other.Tail;
	other.Head = other.Tail = nullptr;
	other.size = nullptr;

#ifdef DEBUG
	cout << "LMoveAssignment:" << tab << this << endl;
#endif // DEBUG

	return *this;
}

template<typename T>
List<T> List<T>::operator+(const List& other)
{
	List<T> Result = *this;
	Element<T>* Temp = other.Head;
	while (Temp != nullptr)
	{
		Result.push_back(Temp->Data);
		Temp = Temp->pNext;
	}
	Result.size = this->size + other.size;

	return Result;
}

template<typename T>
T& List<T>::operator[](int index)
{
	Element<T>* Temp;

	if (index <= size / 2)
	{
		Temp = Head;
		for (int i = 0; i < index; i++) Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - index - 1; i++) Temp = Temp->pPrev;
	}

	return Temp->Data;
}

template<typename T>
void List<T>::push_front(T Data)
{
	Element<T>* New = new Element<T>(Data);

	if (Head == nullptr || Tail == nullptr) Head = Tail = New;
	else
	{
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;
	}

	size++;
}

template<typename T>
void List<T>::push_back(T Data)
{
	Element<T>* New = new Element<T>(Data);

	if (Head == nullptr || Tail == nullptr) Head = Tail = New;
	else
	{
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;
	}
	size++;
}

template<typename T>
void List<T>::pop_front()
{
	if (Head->pNext == nullptr)
	{
		delete Head;
		Head = Tail = nullptr;
	}
	else
	{
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
	}
	size--;
}

template<typename T>
void List<T>::pop_back()
{
	if (Tail->pPrev == nullptr)
	{
		delete Tail;
		Head = Tail = nullptr;
	}
	else
	{
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
	}

	size--;
}

template<typename T>
void List<T>::Insert(int index, T Data)
{
	if (index > size)
	{
		cout << "ERROR:Выход за пределы списка!" << endl;
		return;
	}
	//Element<T>* New = new Element<T>(Data);
	Element<T>* Temp;
	if (index <= size / 2)
	{
		Temp = Head;

		if (index == 0)
		{
			push_front(Data);
			return;
		}
		else
		{
			for (int i = 0; i < index; i++) Temp = Temp->pNext;
			size++;
		}
	}
	else
	{
		Temp = Tail;

		if (index != size)
		{
			for (int i = 0; i < size - index; i++) Temp = Temp->pPrev;
			size++;
		}
		else push_back(Data);
	}
	/*New->pNext = Temp->pNext;
	Temp->pNext->pPrev = New;
	Temp->pNext = New;
	New->pPrev = Temp;*/

	Temp->pPrev = Temp->pPrev->pNext = new Element<T>(Data, Temp, Temp->pPrev);
}

template<typename T>
void List<T>::Delete(int index)
{

	if (index >= size || index < 0)
	{
		cout << "ERROR: Выход за пределы списка!" << endl;
		return;
	}
	if (index == 0)
	{
		pop_front();
		return;
	}
	if (index == size - 1)
	{
		pop_back();
		return;
	}

	Element<T>* Temp;
	if (index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;
	}

	Temp->pPrev->pNext = Temp->pNext;
	Temp->pNext->pPrev = Temp->pPrev;
	delete Temp;
	size--;
}


template<typename T>
void List<T>::Print()
{
	Element<T>* Temp = this->Head;

	for (; Temp; Temp = Temp->pNext) cout /*<< Temp << tab*/ << Temp->Data << /*tab << Temp->pNext <<*/ endl;
	// << this->size << endl;
}

template<typename T>
void List<T>::Print_reverse()
{
	Element<T>* Temp = this->Tail;
	for (; Temp; Temp = Temp->pPrev) cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << this->size << endl;
}

template<typename T>
void List<T>::Save()
{
	ofstream fout("Base.txt");
	Element<T>* Temp = Head;
	while (Temp != nullptr)
	{
		fout << Temp->Data;// << "\n";
		Temp = Temp->pNext;
	}
	fout.close();
}

template<typename T>
void List<T>::Load(char* name)
{
	//ifstream fin(name);
	//const int n = 256;
	//char Buffer[n] = {};
	//while (!fin.eof())
	//{
	//	fin.getline(Buffer, n, '\t');
	//	cout << Buffer << endl;
	//}
	//fin.close();

	ifstream fin("Base.txt");
	Abonent A;
	const int n = 256;
	char Buffer[n] = {};
	//system("DIR");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> A;
			this->push_back(A);
			//system("PAUSE");
			//fin.getline(Buffer, n, '\t');
			//cout << Buffer << endl;
		}
	}
	else cout << "Error: No such file!" << endl;
	fin.close();
}
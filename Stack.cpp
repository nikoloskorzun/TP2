#include "Stack.h"
#include <iostream>


using namespace std;

/* КОНСТРУКТОРЫ */
Stack::Stack() : size(0), top(0) {}

Stack::Stack(int size_st)//конструктор с параметром, задает размер и инициализирует элемент
{
	for (int i = 0; i < size_st; i++)
	{
		this->push(rand() % 21);
	}
}

Stack::~Stack()
{
	if ((top == 0) || (size == 0))
	{
		delete top; //удаляем вершину
		size = 0; //размер нулевой
	}
	else
	{
		while (top->next != 0) //пока не дойдем до нулевого указателя
		{
			Unit* temp = top; //временная переменная юнита, присваиваем ей значение вершины
			top = temp->next; //теперь вершина указывает на следующий за ней элемент,
			delete temp; //а временную - удаляеям
		}
		delete top; //удаляем вершину
		size = 0; //размер нулевой
	}
}

Stack::Stack(const Stack& Stack_copy) : size(Stack_copy.size)
{
	int* buff = new int[Stack_copy.size]; //вводим буферный массив, в котором будем хранить наши числа нового стека
	Unit* el_stack = Stack_copy.top; //новая переменная-вершина будущего стека

	for (int i = 0; i <= Stack_copy.size - 1; i++)
	{	//пока счетчик не дойдет до конца стека
		buff[i] = el_stack->data; //заносим в массив значения из стека
		el_stack = el_stack->next; //ставим указатель на следующий элемент стека
	}

	for (int i = 0; i < Stack_copy.size; i++)
		this->push(buff[i]); //вносим в новый стек значения из массива

	delete[] buff; //удаляем буфер
}

/* МЕТОДЫ КЛАССА СТЕКА */

void Stack::push(int value)
{
	Unit* new_unit = new Unit; //инициализируем новый юнит стека и выделяем под него память
	new_unit->next = top; //теперь новый юнит стал вершиной
	top = new_unit; //и вершина указывает на новый юнит
	top->data = value; //вносим значение в вершину
	size++;
}

int Stack::pop()
{
	if (!this)
	{
		cout << "stack empty!" << endl;
	}

	Unit* temp = top; //временная переменная-вершина 
	int deldata = 0; //место под удаленный элемент

	deldata = top->data; //присваиваем значение удаляемого элемента
	top = top->next; //вершина теперь тот юнит, который был под вершиной
	delete temp; //удаляем переменную-вершину
	size--;
	return deldata; //вернули удаленный элемент
}

void Stack::print()
{
	if (size == 0)
	{
		cout << "stack empty!" << endl;
	}
	else
	{
		Unit* temp = top;
		while (temp->next != nullptr)
		{
			cout << temp->data << " <-- ";
			temp = temp->next;
		}

		cout << temp->data << endl;
	}
}

Unit* Stack::get_top()
{
	return top;
}

int Stack::get_size() const
{
	return size;
}

int Stack::set_size(int& value)
{
	return  (size = value);
}

bool Stack::operator! () const
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}



bool Stack::operator==(Stack& other)
{
	if (other.get_size() != this->get_size())
		return false;
	
	Unit* curr1 = other.get_top();
	Unit* curr2 = this->get_top();
	while (curr1)
	{	

		if (curr1->data != curr2->data)
			return false;
		curr1 = curr1->next;
		curr2 = curr2->next;

	}
	return true;
}


bool Stack::operator!=(Stack& other)
{
	return !(*this == other);

}
bool Stack::operator>(Stack& other)
{
	if (this->get_size() > other.get_size())
		return true;
	if (this->get_size() < other.get_size())
		return false;

	Unit* curr1 = this->get_top();
	Unit* curr2 = other.get_top();
	
	while (curr1)
	{

		if (curr1->data > curr2->data)
			return true;
		if (curr1->data < curr2->data)
			return false;
		curr1 = curr1->next;
		curr2 = curr2->next;

	}
	return false;

}

bool Stack::operator<(Stack& other)
{
	if (this->get_size() < other.get_size())
		return true;
	if (this->get_size() > other.get_size())
		return false;

	Unit* curr1 = this->get_top();
	Unit* curr2 = other.get_top();

	while (curr1)
	{

		if (curr1->data < curr2->data)
			return true;
		if (curr1->data > curr2->data)
			return false;
		curr1 = curr1->next;
		curr2 = curr2->next;

	}
	return false;

}

bool Stack::operator>=(Stack& other)
{
	return !(*this < other);
}
bool Stack::operator<=(Stack& other)
{
	return !(*this > other);
}
Stack* Stack::operator()(int n)
{
	Stack* res = new Stack;
	if (this->get_size() < n)
		return res;


	Unit* curr = this->get_top();
	int i = 0;
	while (i < n-1)
	{

		curr = curr->next;
		i++;

	}

	int* arr = new int[this->get_size() - n + 1];

		i = 0;

		while (curr)
		{
			arr[i] = curr->data;
			curr = curr->next;
			i++;
		}

		for (i = this->get_size() - n ; i >= 0; i--)
			res->push(arr[i]);
	delete[] arr;
	return res;
}

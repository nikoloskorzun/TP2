#pragma once

typedef struct Unit
{
	int data;
	Unit* next;
} Unit; //������� �����

//Unit* top; //������� ����� 

class Stack
{
private:
	Unit* top = 0; //��������� �� ��������� ������� ����� - ������������������ �������
	int size = 0; //������ �����
public:
	//������������
	Stack();
	explicit Stack(int size_st); //����� ����������� � ����������� (������ ������ �����)
	~Stack(); //����������
	Stack(const Stack& Stack_copy); //����������� �����������
	

	//������� �����
	void push(int value); //���������� �������� � ����
	int pop(); //���������� �������
	void print(); //����� ����� �� �����

	//������� � �������
	Unit* get_top(); //����� ������� �����
	int set_size(int& value); //��������� �������� � ����
	int get_size() const; //����� ������ �����

	//������������� ���������
	bool operator! () const; //�������� �� �������

	bool operator==(Stack& other);

	bool operator!=(Stack& other);

	bool operator>(Stack& other);

	bool operator<(Stack& other);

	bool operator>=(Stack& other);

	bool operator<=(Stack& other);



	Stack* operator()( int n);





};

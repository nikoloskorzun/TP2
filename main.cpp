#include "Coord.h"
#include "Stack.h"
#include <iostream>
#include <time.h>


using namespace std;

int main()
{
	
	int c;
	srand(time(NULL));

	Coord a;
	Coord b;
	double d=0;
	int flag1 = 1;
	int flag2 = 1;
	int flag3 = 1;
	int st_choice = 0;

	while (flag1)
	{
		flag2 = 1;
		while (flag2)
		{
			char choice = ' ';
			double number = 0;


			cout << "\n\n\nTASK1:" << endl;
			cout << "1 - b = a++" << endl;
			cout << "2 - b = a--" << endl;
			cout << "3 - d = ++a" << endl;
			cout << "4 - d = --a" << endl;
			cout << "5 - print" << endl;
			cout << "6 - setters" << endl;
			cout << "7 - getters" << endl;
			cout << "0 - go to task 2" << endl;
			
			cout << ">>> ";
			cin >> c;
			system("cls");
			switch (c)
			{
			case 1:
				b = a++;
				break;
			case 2:
				b = a--;
				break;
			case 3:
				d = ++a;
				break;
			case 4:
				d = --a;
				break;
			case 5:
				cout << "d = " << d << endl;
				cout << "a = ";
				a.print();
				cout << "b = ";
				b.print();
				break;
			case 6:
				cout << "x or y or z" << endl;
				cout << ">>> ";

				cin >> choice;
				cout << "number?" << endl;
				cout << ">>> ";
				switch (choice)
				{
				case 'x':
					a.set_x(number);
					break;
				case 'y':
					a.set_y(number);
					break;
				case 'z':
					a.set_z(number);
					break;
				default:
					cout << "NOPE!\n";
					break;
				}
				break;
			case 7:
				cout << "x or y or z" << endl;
				cout << ">>> ";


				cin >> choice;

				switch (choice)
				{
				case 'x':
					cout << a.get_x() << endl;
					break;
				case 'y':
					cout << a.get_y() << endl;
					break;
				case 'z':
					cout << a.get_z() << endl;
					break;
				default:
					cout << "NOPE!\n";
					break;
				}
				break;
			case 0:
				flag2 = 0;
				break;
		

			default:
				cout << "NOPE!\n";
				break;
			}

		}


		int n1=0, n2=0;
		cout << "\n\n\nTASK2:" << endl;
		while (n1 <= 0 || n2 <= 0)
		{ 
		cout << "init Stacks:" << endl;
		cout << ">>> ";
		cin >> n1 >> n2;
		}
		Stack s1(n1);
		Stack s2(n2);
		Stack* s3 = NULL;
		Stack* s4 = NULL;
		flag3 = 1;
		while (flag3)
		{
			
			int n;

			cout << "\n\n\nTASK2:" << endl;
			cout << "1 - a == b" << endl;
			cout << "2 - a != b" << endl;
			cout << "3 - a >= b" << endl;
			cout << "4 - a <= b" << endl;
			cout << "5 - a > b" << endl;
			cout << "6 - a < b" << endl;
			cout << "7 - c = a(n) d=b(n)" << endl;
;
			cout << "8 - print" << endl;
			cout << "9 - stack functions" << endl;

			cout << "0 - go to task 1" << endl;
			cout << "-1 - exit" << endl;
			cout << ">>> ";
			cin >> c;
			system("cls");
			switch(c)
			{
			case 1:
				cout << (s1 == s2) << endl;
				break;
			case 2:
				cout << (s1 != s2) << endl;
				break;
			case 3:
				cout << (s1 >= s2) << endl;
				break;
			case 4:
				cout << (s1 <= s2) << endl;
				break;
			case 5:
				cout << (s1 > s2) << endl;
				break;
			case 6:
				cout << (s1 < s2) << endl;
				break;
			
			case 7:
				cout << "input n" << endl;
				cin >> n;

				if (s3)
					delete s3;
				if (s4)
					delete s4;

				s3 = s1(n);
				s4 = s2(n);
				break;
			case 8:
				cout << "a = ";
				
				s1.print();
				cout << "b = ";
				s2.print();
				cout << "c = ";
				if(s3)
					s3->print();
				else
					cout << "stack empty!" << endl;
				cout << "d = ";
				if (s4)
					s4->print();
				else
					cout << "stack empty!" << endl;

				break;

			case 9:

				cout << "stack 1 or 2\n\n";
				
				while(st_choice !=1 && st_choice != 2)
					cin >> st_choice;
				if(st_choice == 1)
				{ 
				int flag4 = 1;
				int ch = 3;
				int value;
				while (flag4)
				{

					cout << "??????" << endl;
					cout << "1 - push" << endl;
					cout << "2 - pop" << endl;
					cout << "3 - print" << endl;
					cout << "4 - exit\n";
					cin >> ch;
					switch (ch)
					{
					case 1:
						system("cls");
						cout << "input value: " << endl;
						cin >> value;
						s1.push(value);
						break;
					case 2: //2 - Удаление элемента из стека
						if (!s1)
						{
							cout << "Stack empty\n " << endl;
							break;
						}
						else
						{
							system("cls");
							value = s1.pop();
							cout << "el : " << value << endl;
						}
						break;
					case 3: //3 - Вывод стека на экран
						if (!s1)
						{
							cout << "Stack empty\n" << endl;
							break;
						}
						else
						{
							system("cls");
							s1.print();
							cout << "\n";
						}
						break;

					case 4:

						flag4 = 0;

						break;

					}


				}

				}
				if (st_choice == 2)
				{
					int flag4 = 1;
					int ch = 3;
					int value;
					while (flag4)
					{

						cout << "??????" << endl;
						cout << "1 - push" << endl;
						cout << "2 - pop" << endl;
						cout << "3 - print" << endl;
						cout << "4 - exit\n";
						cin >> ch;
						switch (ch)
						{
						case 1:
							system("cls");
							cout << "input value: " << endl;
							cin >> value;
							s2.push(value);
							break;
						case 2: //2 - Удаление элемента из стека
							if (!s2)
							{
								cout << "Stack empty\n " << endl;
								break;
							}
							else
							{
								system("cls");
								value = s2.pop();
								cout << "el : " << value << endl;
							}
							break;
						case 3: //3 - Вывод стека на экран
							if (!s2)
							{
								cout << "Stack empty\n" << endl;
								break;
							}
							else
							{
								system("cls");
								s2.print();
								cout << "\n";
							}
							break;

						case 4:

							flag4 = 0;

							break;

						}


					}

				}
				break;
			case 0:
				flag3 = 0;
				break;

			case -1:
				flag1 = 0;
				flag2 = 0;
				flag3 = 0;
				break;

			default:
				cout << "NOPE!\n";
				break;
			}

		}

		if (s3)
			delete s3;
		if (s4)
			delete s4;
		
	}
	



	system("cls");

	
	return 0;
}

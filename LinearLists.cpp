/***************************************************************************************
*Project Name : LinearLists                                                            *
*File Name    : LinearLists.cpp                                                        *
*Language     : CPP,MSVS ver 2015 and above                                            *
*Programmers : Ратников Роман Олегович,группа:М3О-210Б-20                              *
*Modified By  :                                                                        *
*Created      : 20/11/2021                                                             *
*Last Revision: 21/11/2021                                                             *
*Comment      :Линейные списки       	                                               *
***************************************************************************************/

#define N 20          // Изначальный размер списка
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;


// Функция создания списка
void Create_List(const int& count);

// Функция печати списка
void Print_List();

// Функция удаления списка
void Delete_List();

// Функция поиска максимума
void Get_Max();

// Функция добавления элемента
void Insert_Data(float value, int location);

// Функция удаления хвоста
void Delete_Tail();

// Элемент списка
struct list
{
	double data;       // Данные
	list* next;       // Указатель на следующий элемент
	list* prev;       // Указатель на предыдущий элемент
};

list* head = NULL;    // Указатель на начало списка
list* tail = NULL;    // Указатель на конец списка

int Count = N;        // Количество элементов в списке



int main()
{
	setlocale(LC_ALL, "Rus");
	
	float value;     // Значение вводимого элемента
	int location;    // Расположение в списке

	int number = 1;   //Для первого вывода
	while (number)
	{

	 cout << "\t\tМеню: " << endl;
	 cout << " 0) Выйти из программы" << endl;
	 cout << " 1) Создать список" << endl;
	 cout << " 2) Вывести список" << endl;
	 cout << " 3) Удалить список" << endl;
	 cout << " 4) Найти максимум" << endl;
	 cout << " 5) Добавить элемент" << endl;
	 cout << " 6) Удалить хвост" << endl;
	 cout << "\n\n Введите номер команды :";
	 cin >> number;

	 switch (number)
	 {
		case 0:
		{
		 cout << "\n Завершение программы " << endl;
		 Delete_List(); //Удаление списка
		 return 0;
		}
		case 1:
		{
		 Create_List(N);
		 break;
		}
		case 2:
		{
		 Print_List();
		 break;
		}
		case 3:
		{
		 Delete_List();
		 break;
		}
		case 4:
		{
			Get_Max();
			break;
		}
		case 5:
		{
			if (head == NULL)
			{
				cout << " Список не создан" << endl;
				break;
			}
			
			cout << " Введите значение элемента: ";
			cin >> value;
			cout << "\n Введите расположение нового элемента от 0 до " << Count - 1<<": ";
			cin >> location;
			Insert_Data(value,location);
			break;
		}
		case 6:
		{
			Delete_Tail();
			break;
		}
		default:
		{
		 cout << "\n Введите значение ещё раз :" << endl;
		 break;
		}
	 }
	  system("pause");
      system("cls");
	}
	

	
}


void Create_List(const int& count)
{
	if (head != NULL)
	{
		cout << "  Спиcок уже создан" << endl;
		return;
	}
	srand(time(0));
	for (int i = 0;i < count;++i)
	{
		
		list* temp=new list;      // Новый элемент


			if (i == 0)
			{
				head = temp;       // Начало - голова

			}
			else
			{
				
			    tail->next = temp;  //Связь с предыдущим элементом


			}
			temp->prev = tail;     // Связь с предыдущим элементом
			tail = temp;		   // Текущий элемент - хвост
			temp->next = NULL;	   // Следующего элемента пока что нет

			setprecision(1);
			temp->data = rand() % 20 + double(rand() % 9+1) / 10;  // Заполнение данных
			
		
		
	}
	cout << "  \n Список создан" << endl;
	 Count = N;
}


void Print_List()
{
	if (head == NULL)
	{
		cout << " Список не создан" << endl;
		return ;
	}
	list* actual = head;
	
	int i = 0;
	while(actual!=NULL)       // Пока не достигнем конца списка
	{
		cout << " " << i << "\t" << actual->data << endl;
		actual = actual->next;
		i++;
	}
}

void Delete_List()
{
	if (head == NULL)
	{
		cout << " \n Память свободна" << endl;
		return;
	}
	
	while (head!=NULL)   // Удаление головы, пока список не пуст
	{
		list* actual=head;     // Актуальный элемент - голова
		head = actual->next;   // Следующий элемент - голова
		actual->prev = NULL;
		actual->next = NULL;
		delete actual;

	}
	
	head = NULL;
	tail = NULL;
	
	cout << " Список удалён " << endl;
	
	
	 Count = 0;
}


void Get_Max()
{
	if (head == NULL)
	{
		cout << " \nСписок не создан " << endl;
		return;
	}
	
	list* actual = head;
	double max;
	

    max = actual->data;    // Первый элемент - максимум
	actual = actual->next;
	while (actual != NULL)
	{
		if (max < actual->data)
		{
			max = actual->data;
		}
		
		actual = actual->next;
	}

	cout << " Максимальный элемент: " << max << endl;
	cout << "\n Его расположение в списке: ";
	int index = 0;
	actual = head;
	while (actual != NULL)   // Проходим по всему списку
	{
		if (max == actual->data)
		{
			cout << index << " ";
		}
		actual = actual->next;
		index++;
	}
	cout << endl;
}

void Insert_Data(float value, int location)
{
	if (0 > location or location > Count - 1)
	{
		cout << " Неправильно введено расположение " << endl;
		return;
	}

	list* actual = head;
	int i = 0;
	while (i != location)       // Переходим на месторасположение
	{
		i++;
		actual = actual->next;
	}
        list* temp = new list;
		temp->prev = actual->prev;    //Меняем связи с предыдущим эл.
        

	if (i != 0 )
	{
		
		actual->prev->next = temp;    //Меняем связи с предыдущим эл.
		
		
	}
	else
	{
		head = temp;
	}
        actual->prev = temp;           // Соединяем с актуальным
        temp->next = actual;
		temp->data = value;            // Записываем значение
	
	cout << " Элемент добавлен" << endl;
	Count++;
}

void Delete_Tail()
{
	if (head == NULL)
	{
		cout << " \nСписок не создан " << endl;
		return;
	}
	list* actual = tail;      //Начинаем с хвоста
	tail = actual->prev;      // Меняем хвост на пред
	
	if (Count == 1)
	{
		head = NULL;
	}
	else
	{
		
		tail->next = NULL;  // Рвём связи с последним эл.
	}
	delete actual;

	Count--;
	cout << " \n Хвост удалён " << endl;
}
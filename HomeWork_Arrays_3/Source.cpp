#include<iostream>
#include<ctime>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//#define TASK_1
#define TASK_2

void main()
{
	setlocale(LC_ALL, "Russian");
		
	srand(time(NULL));
	const int n = 10;
	int arr[n];

	int minRand = 0, maxRand = 11;

#ifdef TASK_2
	
	// Заполнение массива случайными числами:
		
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}

	// Вывод исходного массива на экран:

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

	// Сортировка массива от min. до max.:

	int buffer = 0;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				buffer = arr[j];
				arr[j] = arr[i];
				arr[i] = buffer;
			}
		}
	}

	cout << endl;

	// Вывод отсортированного массива на экран:

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl << endl;

	// Поиск повторяющихся чисел:	

	int double_number = 11;

	cout << "Повторяющиеся числа: " << endl << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{

			if (arr[i] == arr[j] && arr[i] != double_number)
			{
				cout << arr[i] << tab;
				double_number = arr[i];
			}

		}

	}

	// Подсчёт повторяющихся чисел:

	cout << endl << endl;
	cout << "Количество повторений: " << endl << endl;

	int count_double = 1;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			count_double += 1;
		}
		else if (count_double > 1)
		{
			cout << count_double << tab;
			count_double = 1;
		}
	}
#endif // TASK_2

#ifdef TASK_1
	
	int candidate;
		
	for (int i = 0; i < n; )
	{
		candidate = rand() % (maxRand - minRand) + minRand;

		for (int j = 0; j < i; j++)
		{
			if (arr[j] == candidate)
			{
				candidate = rand() % (maxRand - minRand) + minRand;
				j = -1;
			}
		}
		if (arr[i] != candidate)
		{
			arr[i] = candidate;
			i++;
		}
	}

	// Вывод массива из УНИКАЛЬНЫХ чисел на экран:

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
#endif // TASK_1

}
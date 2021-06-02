/* Задание 14 вариант
Создать файл, содержащий описание заданного количества треугольников. 
Каждый элемент файла - запись с полями A, B, C, описывающими вершины треугольников. 
Каждое из полей A, B, C в свою очередь запись, содержащая координаты X, Y вершины. 
При создании файла координаты вершин получать от датчика случайных чисел RANDOM в диапазоне от 0 до 10.0. 
После создания файла программа по запросу пользователя должна:
	- распечатать информацию, содержащуюся в файле;
	- вычислить площадь и периметр треугольника по его номеру в файле.
*/

/* Список для реализации +/- (алгоритм выполнения программы)
+1) Юзер вводит количество треугольников.
+2) Создаются новые объекты класса? структуры? списка? С полями — вершинами.
+3) Рандомятся координаты вершин (метод в конструкторе).
+4) В файл эту байду, но понятно, чтобы потом можно было по номеру треугольник опознать. Табличкой? Как-то же можно было.
+5) Предложить Юзеру что делать:
+5.1) Распечатать то, что в файле:
	А (4.0 ; -7.8)
	B (0.6 ; 5.1)
	C (-3.0 ; -11.0).
+5.2.1) Юзер вводит номер треугольника.
+5.2.1) Вычисляются и выводятся его площадь и периметр.
*/

#include <iostream>
#include <fstream> // Общий файловый поток с возможностями как ofstream, так и ifstream, которые позволяют ему создавать, читать и записывать информацию в файлы
#include <cstdlib> // Содержит srand() и rand()
#include <ctime> // Содержит time()
#include <math.h> // Содержит sqrt() и pow()

using namespace std;

void fileOutput(string, int); // Прототип функции вывода из файла
int triSelect(int); // Прототип функции выбора треугольника

class triangle {
public:
	class apex {
	public:
		apex() { // Конструктор по умолчанию для класса apex
			x = rand() % 11; // Задание значение для x в диапазоне от 0 до 10 включительно
			y = rand() % 11; // Задание значение для y в диапазоне от 0 до 10 включительно
		}
		int x;
		int y;
	};

	triangle() {} // Конструктор по умолчанию для класса triangle

	void printApex() {
		cout << "A: (" << A.x << " ; " << A.y << ")" << endl;
		cout << "B: (" << B.x << " ; " << B.y << ")" << endl;
		cout << "C: (" << C.x << " ; " << C.y << ")" << endl;
	}

	float area() {
		float S = 0.5 * ((B.x-A.x) * (C.y-A.y) - (C.x-A.x) * (B.y-A.y));
		if (S < 0) {
			S *= -1;
		}
		return S;
	}

	int perimeter() {
		float P;
		float AB = sqrt(pow((B.x-A.x), 2) + pow((B.y-A.y), 2));
		float BC = sqrt(pow((C.x-B.x), 2) + pow((C.y-B.y), 2));
		float AC = sqrt(pow((C.x-A.x), 2) + pow((C.y-A.y), 2));

		if (AB < 0) {
			AB *= -1;
		}
		if (BC < 0) {
			BC *= -1;
		}
		if (AC < 0) {
			AC *= -1;
		}

		P = AB + BC + AC;

		return P;
	}

	apex A;
	apex B;
	apex C;
};

int main()
{
	int triAmt; // Количество треугольников, определяемое пользователем
	string path = "output.txt"; // Путь к файлу с выводом
	int userChoise = 0; // Выбор пользователя по ходу программы
	int exit = 0; // Флаг выхода из пользовательского выбора
	int triChoise = -1; // Номер выбранного для вычислений треугольника

	// Запрос размеров массива у пользователя
	cout << endl << "Please input the amount of triangles: ";
	cout << "\n>> ";
	cin >> triAmt;
	while (triAmt <= 0) {
		cout << "Please enter positive values: ";
		cout << "\n>> ";
		cin >> triAmt;
	}
	cout << endl;

	// Создание массива треугольников triArray
	triangle* triArray = new triangle[triAmt];
	srand(time(NULL)); // srand() получает в виде параметра текущее системное время, которое при каждом запускe программы будет разным
	for (int i = 0; i < triAmt; i++) {
		triArray[i] = triangle();
	}

	// Запись вершин в файл
	ofstream MyFile;
	MyFile.open(path, ofstream::trunc); // Открытие файла с удалением содержимого, если оно имелось
	if (MyFile.is_open()) {
		for (int i = 0; i < triAmt; i++) {
			MyFile.write((char*)&triArray[i], sizeof(triangle));
		}
	}
	else {
		cout << "Something went wrong.";
	}
	MyFile.close();

	// Выбор пользователем желаемого действия: вывод на экран содержимого файла или вычисление площади и периметра одного из треугольников
	do {
		cout << "\nPlease choose from the following:\n\t1 - Print the information from the file.\n\t2 - Calculate the area and perimeter of a triangle.\n\t3 - Exit.";
		do {
			cout << "\n>> ";
			cin >> userChoise;
			if (userChoise != 1 && userChoise != 2 && userChoise != 3) {
				cout << "Invalid answer. Please try again.";
				userChoise = 0;
			}
		} while (userChoise == 0);

		switch (userChoise)
		{
		case 1:
			fileOutput(path, triAmt); // Вызов функции вывода из файла
			break;
		case 2:
			triChoise = triSelect(triAmt); // Вызов функции выбора треугольника
			cout << "Area: " << triArray[triChoise].area() << endl; // Нахождение площади выбранного треугольника
			cout << "Perimeter: " << triArray[triChoise].perimeter() << endl; // Нахождение периметра выбранного треугольника
		case 3:
			exit = 1;
			break;
		default:
			cout << "Unexpected error." << endl;
			exit = 1;
			break;
		}
	} while (exit == 0); // Если флаг не равен 0, то выход из цикла 

	// Освобождение памяти из-под массива triArray
	delete[]triArray;

	return 0;
}

// Функция вывода из файла
void fileOutput(string path, int triAmt) {
	ifstream fin;
	fin.open(path);
	if (fin.is_open()) {
		triangle tmp;
		for (int i = 0; i < triAmt && fin.read((char*)&tmp, sizeof(triangle)); i++) {
			cout << "Triangle " << i << ":" << endl;
			tmp.printApex();
			cout << endl;
		}
	}
	else {
		cout << "Something went wrong.";
	}
	fin.close();
}

// Функция выбора треугольника
int triSelect(int triAmt) {
	int triNumber = 0;
	// Выбор пользователем одного из треугольников
	cout << "\nPlease enter the number of a triangle.\n";
	do {
		cout << "\n>> ";
		cin >> triNumber;
		if (triNumber >= triAmt || triNumber < 0) {
			cout << "Invalid answer. Please try again.";
			triNumber = -1;
		}
	} while (triNumber == -1);
	return triNumber;
}
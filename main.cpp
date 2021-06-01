/* 
Создать файл, содержащий описание заданного количества треугольников. 
Каждый элемент файла - запись с полями A, B, C, описывающими вершины треугольников. 
Каждое из полей A, B, C в свою очередь запись, содержащая координаты X, Y вершины. 
При создании файла координаты вершин получать от датчика случайных чисел RANDOM в диапазоне от 0 до 10.0. 
После создания файла программа по запросу пользователя должна:
	- распечатать информацию, содержащуюся в файле;
	- вычислить площадь и периметр треугольника по его номеру в файле.
*/

/*
+1) Юзер вводит количество треугольников.
+2) Создаются новые объекты класса? структуры? списка? С полями — вершинами.
+3) Рандомятся координаты вершин (метод в конструкторе).
-4) В файл эту байду, но понятно, чтобы потом можно было по номеру треугольник опознать. Табличкой? Как-то же можно было.
-5) Предложить Юзеру что делать:
-5.1) Распечатать то, что в файле:
	А (4.0 ; -7.8)
	B (0.6 ; 5.1)
	C (-3.0 ; -11.0).
-5.2.1) Юзер вводит номер треугольника.
-5.2.1) Вычисляются и выводятся его площадь и периметр.
*/

#include <iostream>
#include <fstream> // Общий файловый поток с возможностями как ofstream, так и ifstream, которые позволяют ему создавать, читать и записывать информацию в файлы
#include <cstdlib> // Содержит srand() и rand()
#include <ctime> // Содержит time()

using namespace std;


class triangle {
public:
	class apex {
	public:
		apex() { // Конструктор по умолчанию для класса apex
			x = rand() % 11; // Задание значение для x в диапазоне от 0 до 10 включительно
			y = rand() % 11; // Задание значение для y в диапазоне от 0 до 10 включительно
		}
		int x;
		int	y;
	};

	triangle() {} // Конструктор по умолчанию для класса triangle

	void printApex() {
		cout << "A: " << A.x << " " << A.y << endl;
		cout << "B: " << B.x << " " << B.y << endl;
		cout << "C: " << C.x << " " << C.y << endl;
	}

	apex A;
	apex B;
	apex C;
};


int main()
{
	int endFlag = 1; // Флаг, который останавливает приложение
	// Глобальный цикл, который предотвращает завершение программы без желания пользователя
	do {
		int triAmt; // Количество треугольников, определяемое пользователем

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
			triArray[i].printApex();
			//cout << endl << "triArray[" << i << "].A.x " << array[i].A.x << endl << endl;
		}
		


	

		/*
		// Запись исходного массива в файл
		ofstream MyFile;
		MyFile.open("test.txt", ios::trunc); // Открытие файла с удалением содержимого, если оно имелось
		if (MyFile.is_open()) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < K; j++) {
					MyFile << array[i][j] << " \t";
				}
				MyFile << endl;
			}
			MyFile << endl << endl;
		}
		else {
			cout << "Something went wrong";
		}
		MyFile.close();


		

		// Вывод максимального элемента в каждой диагонали, параллельной главной, на экран и запись в файл
		if (N != 1 && K != 1) {
			cout << endl;
			MyFile.open("test.txt", std::ios::app); // std::ios::app - это значение "добавления" в открытом режиме. Новые данные будут записаны в конец файла
			if (MyFile.is_open()) {
				for (int k = 1; k < DIO; k++) {
					cout << k << ": " << max[k] << "\n";
					MyFile << k << ": " << max[k] << "\n";
				}
				MyFile << endl << endl;
			}
			else {
				cout << "Something went wrong";
			}
			MyFile.close();
		}
		else { // Если массив состоит только из одного элемента, то нет никаких диагоналей, кроме гравной
			cout << endl << "There are no diagonals parallel to the main.";
		}

		*/


		// Освобождение памяти из-под массива triArray
		delete[]triArray;

		// Предложение пользователю повторно запустить программу или выйти
		cout << "\n\nPlease choose from the following:\n\t1 - Run program again.\n\t2 - Exit.\n";
		do {
			cout << "\n>> ";
			cin >> endFlag;
			if (endFlag != 1 && endFlag != 2) {
				cout << "Incorrect answer. Please try again.";
				endFlag = 0;
			}
		} while (endFlag == 0);
		switch (endFlag) {
		case 1: endFlag = 1; break;
		case 2: endFlag = 0; break;
		default: cout << "Incorrect answer. The program will be closed."; endFlag = 0; break;
		}

	} while (endFlag); // Если флаг равен 0, то выход из цикла 
	return 0;
}
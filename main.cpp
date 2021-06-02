/* ������� 14 �������
������� ����, ���������� �������� ��������� ���������� �������������. 
������ ������� ����� - ������ � ������ A, B, C, ������������ ������� �������������. 
������ �� ����� A, B, C � ���� ������� ������, ���������� ���������� X, Y �������. 
��� �������� ����� ���������� ������ �������� �� ������� ��������� ����� RANDOM � ��������� �� 0 �� 10.0. 
����� �������� ����� ��������� �� ������� ������������ ������:
	- ����������� ����������, ������������ � �����;
	- ��������� ������� � �������� ������������ �� ��� ������ � �����.
*/

/* ������ ��� ���������� +/- (�������� ���������� ���������)
+1) ���� ������ ���������� �������������.
+2) ��������� ����� ������� ������? ���������? ������? � ������ � ���������.
+3) ���������� ���������� ������ (����� � ������������).
+4) � ���� ��� �����, �� �������, ����� ����� ����� ���� �� ������ ����������� ��������. ���������? ���-�� �� ����� ����.
+5) ���������� ����� ��� ������:
+5.1) ����������� ��, ��� � �����:
	� (4.0 ; -7.8)
	B (0.6 ; 5.1)
	C (-3.0 ; -11.0).
+5.2.1) ���� ������ ����� ������������.
+5.2.1) ����������� � ��������� ��� ������� � ��������.
*/

#include <iostream>
#include <fstream> // ����� �������� ����� � ������������� ��� ofstream, ��� � ifstream, ������� ��������� ��� ���������, ������ � ���������� ���������� � �����
#include <cstdlib> // �������� srand() � rand()
#include <ctime> // �������� time()
#include <math.h> // �������� sqrt() � pow()

using namespace std;

void fileOutput(string, int); // �������� ������� ������ �� �����
int triSelect(int); // �������� ������� ������ ������������

class triangle {
public:
	class apex {
	public:
		apex() { // ����������� �� ��������� ��� ������ apex
			x = rand() % 11; // ������� �������� ��� x � ��������� �� 0 �� 10 ������������
			y = rand() % 11; // ������� �������� ��� y � ��������� �� 0 �� 10 ������������
		}
		int x;
		int y;
	};

	triangle() {} // ����������� �� ��������� ��� ������ triangle

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
	int triAmt; // ���������� �������������, ������������ �������������
	string path = "output.txt"; // ���� � ����� � �������
	int userChoise = 0; // ����� ������������ �� ���� ���������
	int exit = 0; // ���� ������ �� ����������������� ������
	int triChoise = -1; // ����� ���������� ��� ���������� ������������

	// ������ �������� ������� � ������������
	cout << endl << "Please input the amount of triangles: ";
	cout << "\n>> ";
	cin >> triAmt;
	while (triAmt <= 0) {
		cout << "Please enter positive values: ";
		cout << "\n>> ";
		cin >> triAmt;
	}
	cout << endl;

	// �������� ������� ������������� triArray
	triangle* triArray = new triangle[triAmt];
	srand(time(NULL)); // srand() �������� � ���� ��������� ������� ��������� �����, ������� ��� ������ ������e ��������� ����� ������
	for (int i = 0; i < triAmt; i++) {
		triArray[i] = triangle();
	}

	// ������ ������ � ����
	ofstream MyFile;
	MyFile.open(path, ofstream::trunc); // �������� ����� � ��������� �����������, ���� ��� �������
	if (MyFile.is_open()) {
		for (int i = 0; i < triAmt; i++) {
			MyFile.write((char*)&triArray[i], sizeof(triangle));
		}
	}
	else {
		cout << "Something went wrong.";
	}
	MyFile.close();

	// ����� ������������� ��������� ��������: ����� �� ����� ����������� ����� ��� ���������� ������� � ��������� ������ �� �������������
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
			fileOutput(path, triAmt); // ����� ������� ������ �� �����
			break;
		case 2:
			triChoise = triSelect(triAmt); // ����� ������� ������ ������������
			cout << "Area: " << triArray[triChoise].area() << endl; // ���������� ������� ���������� ������������
			cout << "Perimeter: " << triArray[triChoise].perimeter() << endl; // ���������� ��������� ���������� ������������
		case 3:
			exit = 1;
			break;
		default:
			cout << "Unexpected error." << endl;
			exit = 1;
			break;
		}
	} while (exit == 0); // ���� ���� �� ����� 0, �� ����� �� ����� 

	// ������������ ������ ��-��� ������� triArray
	delete[]triArray;

	return 0;
}

// ������� ������ �� �����
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

// ������� ������ ������������
int triSelect(int triAmt) {
	int triNumber = 0;
	// ����� ������������� ������ �� �������������
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
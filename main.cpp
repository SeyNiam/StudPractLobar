/* 
������� ����, ���������� �������� ��������� ���������� �������������. 
������ ������� ����� - ������ � ������ A, B, C, ������������ ������� �������������. 
������ �� ����� A, B, C � ���� ������� ������, ���������� ���������� X, Y �������. 
��� �������� ����� ���������� ������ �������� �� ������� ��������� ����� RANDOM � ��������� �� 0 �� 10.0. 
����� �������� ����� ��������� �� ������� ������������ ������:
	- ����������� ����������, ������������ � �����;
	- ��������� ������� � �������� ������������ �� ��� ������ � �����.
*/

/*
+1) ���� ������ ���������� �������������.
+2) ��������� ����� ������� ������? ���������? ������? � ������ � ���������.
+3) ���������� ���������� ������ (����� � ������������).
+4) � ���� ��� �����, �� �������, ����� ����� ����� ���� �� ������ ����������� ��������. ���������? ���-�� �� ����� ����.
-5) ���������� ����� ��� ������:
+5.1) ����������� ��, ��� � �����:
	� (4.0 ; -7.8)
	B (0.6 ; 5.1)
	C (-3.0 ; -11.0).
-5.2.1) ���� ������ ����� ������������.
-5.2.1) ����������� � ��������� ��� ������� � ��������.
*/

#include <iostream>
#include <fstream> // ����� �������� ����� � ������������� ��� ofstream, ��� � ifstream, ������� ��������� ��� ���������, ������ � ���������� ���������� � �����
#include <cstdlib> // �������� srand() � rand()
#include <ctime> // �������� time()

using namespace std;

void fileOutput(string, int); // �������� ������� ������ �� �����
void calculate(); // �������� ������� ���������� ������� � ��������� ������������ �� ��� ������ � �����

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

	apex A;
	apex B;
	apex C;
};

int main()
{
	int endFlag = 1; // ����, ������� ������������� ����������
	// ���������� ����, ������� ������������� ���������� ��������� ��� ������� ������������
	do {
		int triAmt; // ���������� �������������, ������������ �������������
		string path = "output.txt"; // ���� � ����� � �������
		int userChoise = 0; // ����� ������������ �� ���� ���������
		int exit = 0; // ���� ������ �� ����������������� ������

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
			triArray[i].printApex();
			cout << endl;
		}

		// ������ ������ � ����
		ofstream MyFile;
		//MyFile.open(path, ios::trunc); // �������� ����� � ��������� �����������, ���� ��� �������
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
		cout << "\n\nPlease choose from the following:\n\t1 - Print the information from the file.\n\t2 - Calculate the area and perimeter of a triangle.\n\t3 - Exit.";
		do {
			cout << "\n>> ";
			cin >> userChoise;
			if (userChoise != 1 && userChoise != 2 && userChoise != 3) {
				cout << "Invalid answer. Please try again.";
				userChoise = 0;
			}
		} while (userChoise == 0);
		cout << endl;

		switch (userChoise)
		{
		case 1: 
			fileOutput(path, triAmt); 
			break;
		case 2: 
			calculate();
		case 3: 
			exit = 1;
			break;
		default:
			cout << "Unexpected error.";
			break;
		}
			
		
		//while(exit == 0)
		
		

		

		
		/*
		// ����� ������������� �������� � ������ ���������, ������������ �������, �� ����� � ������ � ����
		if (N != 1 && K != 1) {
			cout << endl;
			MyFile.open("test.txt", std::ios::app); // std::ios::app - ��� �������� "����������" � �������� ������. ����� ������ ����� �������� � ����� �����
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
		else { // ���� ������ ������� ������ �� ������ ��������, �� ��� ������� ����������, ����� �������
			cout << endl << "There are no diagonals parallel to the main.";
		}

		*/


		// ������������ ������ ��-��� ������� triArray
		delete[]triArray;

		// ����������� ������������ �������� ��������� ��������� ��� �����
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

	} while (endFlag); // ���� ���� ����� 0, �� ����� �� ����� 
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

void calculate() {
	int triNumber = 0;
	// ����� ������������� ������ �� �������������
	cout << "\n\nPlease enter the number of a triangle.\n";
	do {
		cout << "\n>> ";
		cin >> triNumber;
		if (triNumber != 1 && triNumber != 2 && triNumber != 3) {
			cout << "Invalid answer. Please try again.";
			triNumber = 0;
		}
	} while (triNumber == 0);
}
#include<string>
#include<iostream>
#include<stdlib.h>
#include <sstream>
#include<conio.h>
#include<vector>
#include<Windows.h>

std::string  convertToBinary(std::string input_string) {
	std::stringstream ss(input_string);
	std::vector<UINT64> numbers;
	UINT64 num;
	while (ss >> num) numbers.push_back(num);
	int len = sizeof(UINT64) * 8 * numbers.size() ;
	char * result = new char[len+1];
	int index = len - 1;
	for (UINT64 num : numbers) {
		result[index--] = ' ';
		for (int i = 0; i < sizeof(UINT64) * 8; i++) {
			result[index--] = (num >> i & 1) == 0 ? '0' : '1';
		}
	}
	result[len-1] = '\0';
	ss = std::stringstream(result);
	std::vector<std::string> splitData;
	std::string temp;
	while (ss >> temp) {
		char * optimal = strstr((char *)temp.c_str(), "1");
		splitData.push_back((optimal == NULL ? "0\0" : optimal));
	}

	std::string output_string;
	for (int i = splitData.size() - 1; i >= 0; i--)
		output_string = output_string + splitData[i] +  + " ";
	return  output_string;
}

void main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	std::string input_string;
	char ch;
	do {
		system("cls");
		std::cout << "Number to Binary Converter" << std::endl;
		std::cout << "program by atthawut" << std::endl;
		std::cout << "you can input multiple number by space" << std::endl;
		std::cout << std::endl << "write your text : ";
		std::getline(std::cin, input_string);
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << std::endl << "Result = " << convertToBinary(input_string) << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << std::endl << "press space bar for write new text . . ." << std::endl;
		std::cout << "press esc for exit . . ." << std::endl;
		do
			ch = getch();
		while (ch != 32 && ch != 27);
	} while (ch != 27);
}
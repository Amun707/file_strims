#include <iostream>
#include<string>
#include <fstream>//�������� �����

//������ ���������� FSTREAM
//fstream ������ ������, ������ ������ �� ����� �� �����
//ifstream ������ ������
//ofstream ������ ������


int main() {
	system("chcp 1251>nul");
	int n, m;
	std::string path = "file.txt";

	//����� ������ ������ ofstream
	std::ofstream out;//�������� ������� ��� ������ � ����
	out.open(path, std::ios::app);//�������� ����� ��� ������

	//������ ������ ofstream ��� �������� � ������ �� ��������� ������� ���� � ������ ��� ����������.
	//  ����� �� ��������� ������ ������� ���������� ����� � ������ ��������
	//append - ��������, ���������

	if (out.is_open()) {//�������� �������� �����
		std::cout << "���� ������ ��� ������.\n";
		std::cout << "������� ������ -> ";
		std::string str;
		std::getline(std::cin, str);
		out << str<<'\n';//����� ������ � ����
	}
	else {
		std::cout << "������ �������� �����.\n";
		//��������� ������� ������ ��� �������� ����� ��� ������
		//1. ������������ ���� � �����
		//2. ��� ������� � �����
		//3. ���� ������ ������ �������� ��� ����������
	}


	out.close();
	

	//����� ������ ����� IFSTREAM
	std::ifstream in;
	in.open(path);

	if (in.is_open()) {
		std::cout << "���� ������. ���������� �����:\n";

		//������������ ����������
		//char sym;
		//while (in.get(sym))
		//	std::cout << sym;
		//std::cout << std::endl;

		//��������� ����������
		//std::string word;
		//while (!in.eof()) {//eof - ����� �����
		//	in >> word;
		//	std::cout << word<<' ';
		//}
		//std::cout << std::endl;

		//���������� ����������
		std::string str;
		while (std::getline(in, str))
			std::cout << str << '\n';
		std::cout << std::endl;

	}
	else {
		std::cout << "������ ������ �����!\n";
		//��������� ������� ������ ��� �������� ����� ��� ������
		//1. ������������ ���� � �����
		//2. ��� ������� � �����
		//3. ����� �� ����������
	}

	in.close();

	//�������� �����
	//remove(path.c_str()); - ��������
	if (remove(path.c_str()) == 0) {
		std::cout << "���� ������.\n";
	}
	else
		std::cout << "������ �������� �����!\n";



	return 0;
}
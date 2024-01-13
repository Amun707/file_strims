#include <iostream>
#include<string>
#include <fstream>//файловый поток

//КЛАССЫ БИБЛИОТЕКИ FSTREAM
//fstream запись данных, чтение данных из этого же файла
//ifstream чтение данных
//ofstream запись данных


int main() {
	system("chcp 1251>nul");
	int n, m;
	std::string path = "file.txt";

	//Класс потока вывода ofstream
	std::ofstream out;//создание объекта для вывода в файл
	out.open(path, std::ios::app);//открытие файла для записи

	//объект класса ofstream при открытии в режиме по умолчанию создает файл в случае его отсутствия.
	//  Также по умолчанию объект стирает содержимое файла в момент открытия
	//append - добавить, дополнить

	if (out.is_open()) {//проверка открытия файла
		std::cout << "Файл открыт для записи.\n";
		std::cout << "Введите строку -> ";
		std::string str;
		std::getline(std::cin, str);
		out << str<<'\n';//вывод строки в файл
	}
	else {
		std::cout << "Ошибка открытия файла.\n";
		//возможные причины ошибок при открытии файла для записи
		//1. некорректный путь к файлу
		//2. нет доступа к файлу
		//3. Файл открыт другим объектом или программой
	}


	out.close();
	

	//КЛАСС ПОТОКА ВВОДА IFSTREAM
	std::ifstream in;
	in.open(path);

	if (in.is_open()) {
		std::cout << "Файл открыт. Содержимое файла:\n";

		//посимвольное считывание
		//char sym;
		//while (in.get(sym))
		//	std::cout << sym;
		//std::cout << std::endl;

		//пословное считывание
		//std::string word;
		//while (!in.eof()) {//eof - конец файла
		//	in >> word;
		//	std::cout << word<<' ';
		//}
		//std::cout << std::endl;

		//Построчное считывание
		std::string str;
		while (std::getline(in, str))
			std::cout << str << '\n';
		std::cout << std::endl;

	}
	else {
		std::cout << "Ошибка чтения файла!\n";
		//возможные причины ошибок при открытии файла для чтения
		//1. некорректный путь к файлу
		//2. нет доступа к файлу
		//3. Файла не существует
	}

	in.close();

	//удаление файла
	//remove(path.c_str()); - неудобно
	if (remove(path.c_str()) == 0) {
		std::cout << "Файл удален.\n";
	}
	else
		std::cout << "Ошибка удаления файла!\n";



	return 0;
}
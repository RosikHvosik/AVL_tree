#include "Data_struct.h"
#include <String>
#include <sstream>
#include <tuple>
#include <stdexcept>


std::tuple<std::string, std::string, std::string> parseFullName(const std::string& line){
	//istringstream позволяет работать со строкой как если бы это был поток данных(например файл)
	std::istringstream iss(line);
	std::string surname, name, patronymic;
	//если не получается вывести 3 слова
	if(!(iss >> surname >> name >> patronymic)){
		throw std::runtime_error("Ошибка разбора строки: " + line);
	}

	return {surname, name, patronymic};
}
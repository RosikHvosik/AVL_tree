#include "list.h"
#include <iostream>

int main() {
        List list;

        // Заполняем список из файла
        list.fillFromFile("data.txt");

        std::cout << "Список ФИО из файла:" << std::endl;
        list.print(); // Выводим содержимое списка
    return 0;
}

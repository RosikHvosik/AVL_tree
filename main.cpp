#include "List.h"
#include "AVL.h"

int main() {
    try {
        List list;
        list.fillFromFile("data.txt");

        std::cout << "Список из файла:" << std::endl;
        list.print();

        AVLTree tree;

        Node* current = list.getHead();
        while (current) {
            tree.insert(current->surname, current->name, current->patronymic);
            current = current->next;
        }

        std::cout << "\nДанные в AVL-дереве:" << std::endl;
        tree.print();

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

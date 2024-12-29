#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "PASRSING.h" // Предполагается, что функция parseFullName реализована

struct Node {
    std::string surname;
    std::string name;
    std::string patronymic;
    Node* next;

    Node(std::string surname, std::string name, std::string patronymic) {
        this->surname = surname;
        this->name = name;
        this->patronymic = patronymic;
        this->next = nullptr;
    }
};

class List {
public:
    Node* head;

public:
    List() : head(nullptr) {}

    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr; // Обнуляем указатель головы
    }

    void add(const std::string& surname, const std::string& name, const std::string& patronymic) {
        Node* newNode = new Node(surname, name, patronymic);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void fillFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Ошибка открытия файла: " + filename);
        }

        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue; // Пропускаем пустые строки
            auto [surname, name, patronymic] = parseFullName(line); // Разбираем строку на ФИО
            add(surname, name, patronymic); // Добавляем в список
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->surname << " " << current->name << " " << current->patronymic << std::endl;
            current = current->next;
        }
    }

    Node* pop() {
        if (head == nullptr) return nullptr;
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        return temp;
    }
    Node* getHead() const {
    return head;
}

};

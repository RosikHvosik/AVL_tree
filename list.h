#include <String>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "PASRSING.h"

struct Node{
	std::string surname;
	std::string name;
	std::string patronymic;
	Node*next;


	Node( std::string surname,  std::string name,  std::string patronymic){
		surname = surname;
		name = name;
		patronymic = patronymic;

	}

};


class List{
	public:
	Node* head;

public:
	List(){
		head = nullptr;
	}

	~List(){
		Node* current = head;
		do{
			current = head->next;
			delete head;
			head = current;
		}while(current!= nullptr);
	}

	void add(std::string& surname, std:: string& name, std::string& patronymic){
		Node* newNode = new Node(surname, name, patronymic);
		if(head = nullptr){
			head = newNode;
		}else{
			Node* current = head;
			while(current->next != nullptr){
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

	void print(){
		Node* current = head;
		while(current!=nullptr){
			std::cout<< current->name << " " << current->surname << " " << current->patronymic;
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
};

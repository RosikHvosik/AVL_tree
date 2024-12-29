#include <string>
#include <iostream>
#include <algorithm>


struct FIO{
	std::string surname;
  std::string name;
  std::string patronymic;
	FIO (std::string& surname, std::string& name, std::string& patronymic): surname(surname), name(name), patronymic(patronymic) {}

	bool operator > (const FIO& other) const {
		if (surname != other.surname){
			return surname >other.surname;
		}
		if (name != other.name){
			return name > other.name;
		}
		return patronymic > other.patronymic;
	}

	bool operator < (const FIO& other) const {
		if (surname != other.surname){
			return surname < other.surname;
		}
		if (name != other.name){
			return name < other.name;
		}
		return patronymic < other.patronymic;
	}

	bool operator == (const FIO& other) const {
		return (surname == other.surname && name == other.name && patronymic == other.patronymic);
	}

	bool operator<=(const FIO& other) const {
    return *this < other || *this == other;
    }

  bool operator>=(const FIO& other) const {
    return *this > other || *this == other;
    }

};


struct TreeNode {
		FIO key;
    int count;
		int bal;
    TreeNode* left;
    TreeNode* right;

		 TreeNode(const FIO& fio, int count, int bal, TreeNode* left, TreeNode* right) : key(fio), count(1), bal(0), left(nullptr), right(nullptr){}
};
//is_high параметр который будет отвечать за увеличилось дерево или нет 

class AVL_tree{
	TreeNode* root;
	AVL_tree() : root(nullptr){}
	void search(FIO fio, TreeNode*& p, bool& h) {

	}
}; 
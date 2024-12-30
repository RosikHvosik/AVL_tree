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
	void insert(FIO fio, TreeNode*& p, bool h) {
		TreeNode* p1 = new TreeNode(fio, 1, 0, nullptr, nullptr);
		TreeNode* p2 = new TreeNode(fio, 1, 0, nullptr, nullptr);
		if (p == nullptr){
			p = new TreeNode(fio, 1, 0, nullptr, nullptr);
			h = true;
		}
		else if(p->key > fio){
			insert (fio, p->left, h);
			if (h){
				if(p->bal == 1){
					p->bal = 0;
					h= false;
				}
				else if (p->bal == 0){
					p->bal = -1;
				}
				//значит баланс в вершине -1
				else{
					//может быть тут ошибка тюк я уже предопределил fio для p1
					p1 = p->left;
					if (p1->bal == -1){//LL rotation
						p->left = p1->right;
						p1->right = p;
						p->bal = 0;
						p = p1;
					}
					else{//LR rotation
						p2 = p1->right;
						p1->right = p2->left;
						p2->left = p1;
						p->left = p2->right;
						p2->right = p;
						if(p2->bal == -1){p->bal = 1;}
						else{p->bal = 0;}
						if (p2->bal == 1){p1->bal = -1;}
						else{p1->bal = 0;}
						p = p2;
					}
					p->bal = 0;
					h = false;
				}
			}
		}
		else if(p->key < fio){
			insert (fio, p->right, h);
			if (h){
				if (p->bal == -1) {p->bal=0; h=false;}
				else if(p->bal == 0){p->bal = 1;}
				else {
					p1= p->right;
					if (p1->bal == 1){//RR rotation
						p->right = p1->left;
						p1->left = p;
						p->bal = 0;
						p = p1;
					}
					else{//RL rotation
						p2 = p1->left;
						p1->left = p2->right;
						p2->right = p1;
						p->right = p2->left;
						p2->left = p;
						if (p2->bal == 1){p->bal = -1;}
						else{p->bal = 0;}
						if(p2->bal == -1){p1->bal = 1;}
						else{p1->bal = 0;}
						p = p2;
					}
					p->bal =0;
					h= false;
				}
			}
			else p->count++;
		}
	}
}; 
#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include <iostream>
#include <algorithm>

struct TreeNode {
    std::string surname;
    std::string name;
    std::string patronymic;
    int height;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const std::string& surname, const std::string& name, const std::string& patronymic)
        : surname(surname), name(name), patronymic(patronymic), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    TreeNode* root;

    // Получение высоты узла
    int getHeight(TreeNode* node) const {
        return node ? node->height : 0;
    }

    // Вычисление коэффициента баланса
    int getBalance(TreeNode* node) const {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // Правая ротация
    TreeNode* rotateRight(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        // Выполняем вращение
        x->right = y;
        y->left = T2;

        // Обновляем высоты
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // Левая ротация
    TreeNode* rotateLeft(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        // Выполняем вращение
        y->left = x;
        x->right = T2;

        // Обновляем высоты
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // Вставка в дерево с балансировкой
    TreeNode* insert(TreeNode* node, const std::string& surname, const std::string& name, const std::string& patronymic) {
        if (!node)
            return new TreeNode(surname, name, patronymic);

        // Сравнение фамилии, имени, отчества
        if (surname < node->surname || (surname == node->surname && name < node->name) || 
            (surname == node->surname && name == node->name && patronymic < node->patronymic)) {
            node->left = insert(node->left, surname, name, patronymic);
        } else if (surname > node->surname || (surname == node->surname && name > node->name) || 
                   (surname == node->surname && name == node->name && patronymic > node->patronymic)) {
            node->right = insert(node->right, surname, name, patronymic);
        } else {
            std::cerr << "Дубликат записи: " << surname << " " << name << " " << patronymic << std::endl;
            return node;
        }

        // Обновляем высоту узла
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        // Балансировка узла
        int balance = getBalance(node);

        // Левое левое нарушение
        if (balance > 1 && surname < node->left->surname)
            return rotateRight(node);

        // Правое правое нарушение
        if (balance < -1 && surname > node->right->surname)
            return rotateLeft(node);

        // Левое правое нарушение
        if (balance > 1 && surname > node->left->surname) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Правое левое нарушение
        if (balance < -1 && surname < node->right->surname) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    // Обход дерева (in-order)
void inOrder(TreeNode* node) const {
    if (node) {
        // 1. Сначала правое поддерево
        inOrder(node->right);

        // 2. Затем текущий узел
        std::cout << node->surname << " " << node->name << " " << node->patronymic << std::endl;

        // 3. Затем левое поддерево
        inOrder(node->left);
    }
}

    // Очистка дерева
    void clear(TreeNode* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    AVLTree() : root(nullptr) {}

    ~AVLTree() {
        clear(root);
    }

    void insert(const std::string& surname, const std::string& name, const std::string& patronymic) {
        root = insert(root, surname, name, patronymic);
    }

    // Печать элементов в новом порядке
    void print() const {
        inOrder(root);
    }
};

#endif // AVLTREE_H

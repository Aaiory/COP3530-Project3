#ifndef FINAL_PROJECT_2_RBTREE_H
#define FINAL_PROJECT_2_RBTREE_H

#include <utility>
#include "Food.h"

class RBTree {
private:
    struct Node {
        Food data;
        bool isRed;
        Node* left;
        Node* right;
        Node* parent;

        explicit Node(Food food) : data(std::move(food)), isRed(true), left(nullptr), right(nullptr), parent(nullptr) {}
        ~Node() { delete left; delete right; }
    };

    Node* root;

    void leftRotate(Node* x);
    void rightRotate(Node* x);
    void insertFixup(Node* z);
    void transplant(Node* u, Node* v);
    void deleteFixup(Node* x);
    void deleteNode(Node *z);
    static Node* minimum(Node* x);
    static Node* maximum(Node* x);
    Node* findNode(Node* x, const std::string& category);
    static Node *searchHelper(const std::string &category, Node *x);

public:
    RBTree() : root(nullptr) {}
    ~RBTree() { delete root; }
    void insert(Food food);
    void remove(const std::string& category);
    Food* search(const std::string& category);
};

#endif //FINAL_PROJECT_2_RBTREE_H

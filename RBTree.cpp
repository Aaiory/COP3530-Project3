#include "RBTree.h"

#include <utility>

void RBTree::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RBTree::rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    if (y->right != nullptr) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void RBTree::insert(Food food) {
    Node* z = new Node(std::move(food));
    Node* y = nullptr;
    Node* x = root;
    while (x != nullptr) {
        y = x;
        if (z->data.getCategory() < x->data.getCategory()) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == nullptr) {
        root = z;
    } else if (z->data.getCategory() < y->data.getCategory()) {
        y->left = z;
    } else {
        y->right = z;
    }
    insertFixup(z);
}

void RBTree::insertFixup(Node* z) {
    while (z->parent != nullptr && z->parent->isRed) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y != nullptr && y->isRed) {
                z->parent->isRed = false;
                y->isRed = false;
                z->parent->isRed = true;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->isRed = false;
                z->parent->parent->isRed = true;
                rightRotate(z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left;
            if (y != nullptr && y->isRed) {
                z->parent->isRed = false;
                y->isRed = false;
                z->parent->parent->isRed = true;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->isRed = false;
                z->parent->parent->isRed = true;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->isRed = false;
}

void RBTree::deleteNode(Node* z) {
    Node* x;
    Node* y = z;
    bool yOriginalColor = y->isRed;
    if (z->left == nullptr) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == nullptr) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = minimum(z->right);
        yOriginalColor = y->isRed;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->isRed = z->isRed;
    }
    if (!yOriginalColor) {
        deleteFixup(x);
    }
    delete z;
}

void RBTree::deleteFixup(Node* x) {
    while (x != root && !x->isRed) {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->isRed) {
                w->isRed = false;
                x->parent->isRed = true;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if (!w->left->isRed && !w->right->isRed) {
                w->isRed = true;
                x = x->parent;
            } else {
                if (!w->right->isRed) {
                    w->left->isRed = false;
                    w->isRed = true;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->isRed = x->parent->isRed;
                x->parent->isRed = false;
                w->right->isRed = false;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            Node* w = x->parent->left;
            if (w->isRed) {
                w->isRed = false;
                x->parent->isRed = true;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if (!w->right->isRed && !w->left->isRed) {
                w->isRed = true;
                x = x->parent;
            } else {
                if (!w->left->isRed) {
                    w->right->isRed = false;
                    w->isRed = true;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->isRed = x->parent->isRed;
                x->parent->isRed = false;
                w->left->isRed = false;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->isRed = false;
}

void RBTree::transplant(Node* u, Node* v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != nullptr) {
        v->parent = u->parent;
    }
}

RBTree::Node *RBTree::minimum(RBTree::Node *x) {
    while (x->left != nullptr) {
        x = x->left;
    }
    return x;
}

RBTree::Node *RBTree::maximum(Node* x) {
    while (x->right != nullptr) {
        x = x->right;
    }
    return x;
}

RBTree::Node *RBTree::findNode(Node* x, const std::string& category) {
    if (x == nullptr) {
        return nullptr;
    }
    if (category == x->data.getCategory()) {
        return x;
    } else if (category < x->data.getCategory()) {
        return findNode(x->left, category);
    } else {
        return findNode(x->right, category);
    }
}

std::vector<Food> RBTree::search(const std::string& category) {
    std::vector<Food> results;
    searchHelper(category, root, results);
    return results;
}

void RBTree::searchHelper(const std::string& category, Node* x, std::vector<Food>& results) {
    if (x == nullptr) {
        return;
    }
    if (category < x->data.getCategory()) {
        searchHelper(category, x->left, results);
    } else if (category > x->data.getCategory()) {
        searchHelper(category, x->right, results);
    } else {
        // We found a node with the matching category key, so add its food item to the results vector
        results.push_back(x->data);
        // Recursively search the left and right subtrees for additional matching nodes
        searchHelper(category, x->left, results);
        searchHelper(category, x->right, results);
    }
}


void RBTree::uniqueKeysHelper(RBTree::Node *x, std::set<std::string> &keys) {
    if (x == nullptr) {
        return;
    }
    uniqueKeysHelper(x->left, keys);
    keys.insert(x->data.getCategory());
    uniqueKeysHelper(x->right, keys);
}

std::set<std::string> RBTree::uniqueKeys() {
    std::set<std::string> keys;
    uniqueKeysHelper(root, keys);
    return keys;
}
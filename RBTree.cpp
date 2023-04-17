#include "RBTree.h"

#include <utility>

void RBTree::leftRotate(Node* nodeToRotate) {
    // Get the right child of nodeToRotate.
    Node* rightChild = nodeToRotate->right;

    // Set nodeToRotate's right child to rightChild 's left child.
    nodeToRotate->right = rightChild ->left;
    if (rightChild ->left != nullptr) {
        // Set rightChild 's left child's parent to nodeToRotate.
        rightChild ->left->parent = nodeToRotate;
    }

    // Set rightChild 's parent to nodeToRotate's parent.
    rightChild ->parent = nodeToRotate->parent;

    // If nodeToRotate's parent is nullptr, then rightChild  is the new root.
    if (nodeToRotate->parent == nullptr) {
        root = rightChild ;
    } else {
        // If nodeToRotate is nodeToRotate's parent's left child, then set nodeToRotate's parent's left child to rightChild .
        if (nodeToRotate == nodeToRotate->parent->left) {
            nodeToRotate->parent->left = rightChild ;
        } else {
            // Otherwise, set nodeToRotate's parent's right child to rightChild .
            nodeToRotate->parent->right = rightChild ;
        }
    }

    // Set rightChild 's left child to nodeToRotate.
    rightChild ->left = nodeToRotate;

    // Set nodeToRotate's parent to rightChild .
    nodeToRotate->parent = rightChild ;
}

void RBTree::rightRotate(Node* nodeToRotate) {
    // Get the left child of nodeToRotate.
    Node* leftChild = nodeToRotate->left;

    // Set nodeToRotate's left child to leftChild's right child.
    nodeToRotate->left = leftChild->right;
    if (leftChild->right != nullptr) {
        // Set leftChild's right child's parent to nodeToRotate.
        leftChild->right->parent = nodeToRotate;
    }

    // Set leftChild's parent to nodeToRotate's parent.
    leftChild->parent = nodeToRotate->parent;

    // If nodeToRotate's parent is nullptr, then leftChild is the new root.
    if (nodeToRotate->parent == nullptr) {
        root = leftChild;
    } else {
        // If nodeToRotate is nodeToRotate's parent's right child, then set nodeToRotate's parent's right child to leftChild.
        if (nodeToRotate == nodeToRotate->parent->right) {
            nodeToRotate->parent->right = leftChild;
        } else {
            // Otherwise, set nodeToRotate's parent's left child to leftChild.
            nodeToRotate->parent->left = leftChild;
        }
    }

    // Set leftChild's right child to nodeToRotate.
    leftChild->right = nodeToRotate;

    // Set nodeToRotate's parent to leftChild.
    nodeToRotate->parent = leftChild;
}

void RBTree::insert(Food food) {
    // Create a new node for the food.
    Node* newNode = new Node(std::move(food));

    // Initialize the parent and grandparent of the new node.
    Node* parentNode = nullptr;
    Node* currentNode = root;

    // Iterate over the tree, looking for the place to insert the new node.
    while (currentNode != nullptr) {
        parentNode = currentNode;
        if (newNode->data.getCategory() < currentNode->data.getCategory()) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }

    // Set the parent and grandparent of the new node.
    newNode->parent = parentNode;
    if (parentNode == nullptr) {
        root = newNode;
    } else if (newNode->data.getCategory() < parentNode->data.getCategory()) {
        parentNode->left = newNode;
    } else {
        parentNode->right = newNode;
    }

    // Fix the red-black properties of the tree.
    insertFixup(newNode);
}

void RBTree::insertFixup(Node* newNode) {
    // While the new node's parent is red, fix the red-black properties of the tree.
    while (newNode->parent != nullptr && newNode->parent->isRed) {
        // If the new node's parent is the left child of its grandparent,
        if (newNode->parent == newNode->parent->parent->left) {
            // Get the uncle of the new node.
            Node* uncle = newNode->parent->parent->right;

            // If the uncle is red,
            if (uncle  != nullptr && uncle ->isRed) {
                // Set the parent and grandparent of the new node to black.
                newNode->parent->isRed = false;
                uncle ->isRed = false;
                newNode->parent->parent->isRed = true;
                newNode = newNode->parent->parent;
            } else {
                // If the new node is the right child of its parent,
                if (newNode == newNode->parent->right) {
                    // Rotate the new node's parent left.
                    newNode = newNode->parent;
                    leftRotate(newNode);
                }

                // Set the parent and grandparent of the new node to black.
                newNode->parent->isRed = false;
                newNode->parent->parent->isRed = true;
                rightRotate(newNode->parent->parent);
            }
        } else {
            // If the new node's parent is the right child of its grandparent,
            Node* uncle  = newNode->parent->parent->left;

            // If the uncle is red,
            if (uncle  != nullptr && uncle ->isRed) {
                // Set the parent and grandparent of the new node to black.
                newNode->parent->isRed = false;
                uncle ->isRed = false;
                newNode->parent->parent->isRed = true;
                newNode = newNode->parent->parent;
            } else {
                // If the new node is the left child of its parent,
                if (newNode == newNode->parent->left) {
                    // Rotate the new node's parent right.
                    newNode = newNode->parent;
                    rightRotate(newNode);
                }

                // Set the parent and grandparent of the new node to black.
                newNode->parent->isRed = false;
                newNode->parent->parent->isRed = true;
                leftRotate(newNode->parent->parent);
            }
        }
    }

    // Set the root of the tree to black.
    root->isRed = false;
}

RBTree::Node* RBTree::findNode(Node* currentNode, const std::string& category) {
    // If the current node is nullptr, return nullptr.
    if (currentNode == nullptr) {
        return nullptr;
    }

    // If the category is equal to the category of the current node, return the current node.
    if (category == currentNode->data.getCategory()) {
        return currentNode;
    }

    // If the category is less than the category of the current node, recursively call findNode on the left child of the current node.
    if (category < currentNode->data.getCategory()) {
        return findNode(currentNode->left, category);
    }

    // Otherwise, recursively call findNode on the right child of the current node.
    return findNode(currentNode->right, category);
}

std::vector<Food> RBTree::search(const std::string& category) {
    // Create a vector to store the results.
    std::vector<Food> results;

    // Recursively search the tree for nodes with the given category.
    searchHelper(category, root, results);

    // Return the results.
    return results;
}

void RBTree::searchHelper(const std::string& category, Node* currentNode, std::vector<Food>& results) {
    // If the current node is nullptr, return.
    if (currentNode == nullptr) {
        return;
    }

    // If the category is less than the category of the current node, recursively search the left child of the current node.
    if (category < currentNode->data.getCategory()) {
        searchHelper(category, currentNode->left, results);
    }

        // If the category is greater than the category of the current node, recursively search the right child of the current node.
    else if (category > currentNode->data.getCategory()) {
        searchHelper(category, currentNode->right, results);
    }

        // If the category is equal to the category of the current node, add the current node to the results vector.
    else {
        results.push_back(currentNode->data);
        // Recursively search the left and right subtrees for additional matching nodes.
        searchHelper(category, currentNode->left, results);
        searchHelper(category, currentNode->right, results);
    }
}

void RBTree::uniqueKeysHelper(RBTree::Node* currentNode, std::set<std::string>& keys) {
    // If the current node is nullptr, return.
    if (currentNode == nullptr) {
        return;
    }

    // Recursively call uniqueKeysHelper on the left child of the current node.
    uniqueKeysHelper(currentNode->left, keys);

    // Insert the category of the current node into the keys set.
    keys.insert(currentNode->data.getCategory());

    // Recursively call uniqueKeysHelper on the right child of the current node.
    uniqueKeysHelper(currentNode->right, keys);
}

std::set<std::string> RBTree::uniqueKeys() {
    // Create a set to store the unique keys.
    std::set<std::string> keys;

    // Recursively call uniqueKeysHelper to add the categories of all the nodes in the tree to the set.
    uniqueKeysHelper(root, keys);

    // Return the set of unique keys.
    return keys;
}
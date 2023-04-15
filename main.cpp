#include <iostream>
#include <string>
#include <vector>
#include "Food.h"
#include "RBTree.h"

int main() {
    std::string fileName = "food.csv"; // File name
    std::vector<Food> foods = loadFromFile(fileName); // vector to hold all Food instances

    RBTree tree;

    for (const auto& food : foods) {
        tree.insert(food);
    }

    // Test search function
    std::cout << "Search results:" << std::endl;
    std::cout << "Milk: " << tree.search("Milk")->getDescription() << std::endl;
    std::cout << "Yogurt: " << tree.search("Yogurt")->getDescription() << std::endl;
    std::cout << "Pudding: " << tree.search("Pudding")->getDescription() << std::endl;

    return 0;
}


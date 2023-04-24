#include <iostream>
#include <string>
#include <vector>
#include "Food.h"
#include "RBTree.h"
#include "HMap.h"

int main() {
    std::string fileName = "food.csv"; // File name
    std::vector<Food> foods = loadFromFile(fileName); // vector to hold all Food instances

    RBTree tree;
    FoodMap map(10, 0.5);

    for (const auto& food : foods) {
        tree.insert(food);
        map.insertFood(food);
    }

    // Test search function (RBT)
    std::cout << "Search results (RB Tree):" << std::endl;
    std::cout << "Milk: " << tree.search("Milk").size() << std::endl;
    std::cout << "Yogurt: " << tree.search("Yogurt").size() << std::endl;
    std::cout << "Pudding: " << tree.search("Pudding").size() << std::endl;

    // Test search function (HMap)
    std::cout << "Search results (HMap):" << std::endl;
    std::cout << "Milk: " << map.search("Milk").size() << std::endl;
    std::cout << "Yogurt: " << map.search("Yogurt").size() << std::endl;
    std::cout << "Pudding: " << map.search("Pudding").size() << std::endl;

    std::cout << "Milk according to Protein :";
    std::vector<Food> s = map.search("Milk", "protein");
    for(Food f : s)
    {
        std::cout << f.getProtein() << " ";
    }

    /*
    std::vector<std::string> headers = loadHeadersFromFile("food.csv");
    for(auto header : headers){
        std::cout << header << " ";
    }
    std::cout << "\nHeader Count: " << headers.size() << std::endl;*/
    return 0;
}


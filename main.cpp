#include <iostream>
#include <string>
#include <vector>
#include "Food.h"
#include "RBTree.h"
#include "HMap.h"
#include "FoodFinder.h"

int main() {
    FoodFinder foodFinder("food.csv");

    // Test search function (RBT)
    std::cout << "Search results (RB Tree):" << std::endl;
    std::cout << "Milk: " << foodFinder.searchTree("Milk").size() << std::endl;
    std::cout << "Yogurt: " << foodFinder.searchTree("Yogurt").size() << std::endl;
    std::cout << "Pudding: " << foodFinder.searchTree("Pudding").size() << std::endl;

    // Test search function (HMap)
    std::cout << "Search results (HMap):" << std::endl;
    std::cout << "Milk: " << foodFinder.searchMap("Milk").size() << std::endl;
    std::cout << "Yogurt: " << foodFinder.searchMap("Yogurt").size() << std::endl;
    std::cout << "Pudding: " << foodFinder.searchMap("Pudding").size() << std::endl;

    std::cout << "Milk according to Protein :";
    std::vector<Food> s = foodFinder.searchMapNutrientDesc("Milk", "protein");
    for(Food f : s)
    {
        std::cout << f.getProtein() << " ";
    }

    /*
    std::vector<std::string> headers = loadHeadersFromFile("food.csv");
    for(const auto& header : headers){
        std::cout << header << " ";
    }
    std::cout << "\nHeader Count: " << headers.size() << std::endl;*/
    return 0;
}


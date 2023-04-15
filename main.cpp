#include <iostream>
#include <string>
#include <vector>
#include "Food.h"
#include "hashtable.h"

int main() {
    std::string fileName = "food.csv"; // File name
    std::vector<Food> foods = loadFromFile(fileName); // vector to hold all Food instances

    return 0;
}


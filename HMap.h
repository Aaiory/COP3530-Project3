#ifndef FINALPROJECTHMAP
#define FINALPROJECTHMAP

#include <string>
#include <vector>
#include <algorithm>
#include "Food.h"

class FoodMap
{
    //Category Class, basically just a list containing every food item in a category plus name for easy manipulation
    struct FoodCategory
    {
        std::string name;
        std::vector<Food> foodstuffs;
        void insertFood(Food food);
        explicit FoodCategory(std::string& name);
    };
    //Member Variables
    int buckets;
    int filled;
    float loadfactor;
    float maxload;
    std::vector<std::vector<FoodCategory>> foodmap; //Separate chaining policy

    public:
    //Constructor
    FoodMap(int buckets, float maxload);

    //Hash (ASCII value of all characters % the bucket count)
    int hashFunction(std::string& catname);

    //Insert Functions
    void insertFood(Food food);
    void insertCategory(FoodCategory cat);

    //Rehash Function
    void reHash();

    //Search Functions
    std::vector<Food> search(std::string category);
};

#endif
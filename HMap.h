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

    //Sort Comparators
    static bool sortNdbsNumber(Food a, Food b);
    static bool sortAlphaCarotene(Food a, Food b);
    static bool sortBetaCarotene(Food a, Food b);
    static bool sortBetaCryptoxanthin(Food a, Food b);
    static bool sortCarbohydrate(Food a, Food b);
    static bool sortCholesterol(Food a, Food b);
    static bool sortCholine(Food a, Food b);
    static bool sortFiber(Food a, Food b);
    static bool sortLuteinZeaxanthin(Food a, Food b);
    static bool sortLycopene(Food a, Food b);
    static bool sortNiacin(Food a, Food b);
    static bool sortProtein(Food a, Food b);
    static bool sortRetinol(Food a, Food b);
    static bool sortRiboflavin(Food a, Food b);
    static bool sortSelenium(Food a, Food b);
    static bool sortSugarTotal(Food a, Food b);
    static bool sortThiamin(Food a, Food b);
    static bool sortWater(Food a, Food b);
    static bool sortMonoFat(Food a, Food b);
    static bool sortPolyFat(Food a, Food b);
    static bool sortSatFat(Food a, Food b);
    static bool sortTotalFat(Food a, Food b);
    static bool sortCalcium(Food a, Food b);
    static bool sortCopper(Food a, Food b);
    static bool sortIron(Food a, Food b);
    static bool sortMagnesium(Food a, Food b);
    static bool sortPhosphorus(Food a, Food b);
    static bool sortPotassium(Food a, Food b);
    static bool sortSodium(Food a, Food b);
    static bool sortZinc(Food a, Food b);
    static bool sortVitARAE(Food a, Food b);
    static bool sortVitB12(Food a, Food b);
    static bool sortVitB6(Food a, Food b);
    static bool sortVitC(Food a, Food b);
    static bool sortVitE(Food a, Food b);
    static bool sortVitK(Food a, Food b);

    //Search Functions
    std::vector<Food> search(std::string category);
    std::vector<Food> search(std::string category, std::string nutrition);
};

#endif
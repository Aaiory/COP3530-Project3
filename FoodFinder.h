#include "HMap.h"
#include "RBTree.h"
#include "Food.h"

class FoodFinder
{
    //Comparable Structures
    RBTree tree;
    FoodMap map = FoodMap(10, 0.5);

    //Sort Comparators, will be used with the standard sort function to sort according to nutrient values
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

public:

    //Constructor
    FoodFinder(std::string filename);

    //Insert Function
    void insert(Food food);

    //Sort Function
    void sortNutrient(std::vector<Food>& result, std::string nutrition); //sorts in descending order by nutrient

    //Search Functions
    std::vector<Food> searchMap(std::string category);
    std::vector<Food> searchTree(std::string category);
    std::vector<Food> searchMapNutrientDesc(std::string category, std::string nutrition);
    std::vector<Food> searchMapNutrientAsc(std::string category, std::string nutrition);
    std::vector<Food> searchTreeNutrientDesc(std::string category, std::string nutrition);
    std::vector<Food> searchTreeNutrientAsc(std::string category, std::string nutrition);



};
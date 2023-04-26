#include "HMap.h"
#include "RBTree.h"
#include "Food.h"

class FoodFinder
{
    //Comparable Structures
    RBTree tree;
    FoodMap map = FoodMap(10, 0.5);

    //Sort Comparators, will be used with the standard sort function to sort according to nutrient values
    static bool sortNdbsNumber(const Food& a, const Food& b);
    static bool sortAlphaCarotene(const Food& a, const Food& b);
    static bool sortBetaCarotene(const Food& a, const Food& b);
    static bool sortBetaCryptoxanthin(const Food& a, const Food& b);
    static bool sortCarbohydrate(const Food& a, const Food& b);
    static bool sortCholesterol(const Food& a, const Food& b);
    static bool sortCholine(const Food& a, const Food& b);
    static bool sortFiber(const Food& a, const Food& b);
    static bool sortLuteinZeaxanthin(const Food& a, const Food& b);
    static bool sortLycopene(const Food& a, const Food& b);
    static bool sortNiacin(const Food& a, const Food& b);
    static bool sortProtein(const Food& a, const Food& b);
    static bool sortRetinol(const Food& a, const Food& b);
    static bool sortRiboflavin(const Food& a, const Food& b);
    static bool sortSelenium(const Food& a, const Food& b);
    static bool sortSugarTotal(const Food& a, const Food& b);
    static bool sortThiamin(const Food& a, const Food& b);
    static bool sortWater(const Food& a, const Food& b);
    static bool sortMonoFat(const Food& a, const Food& b);
    static bool sortPolyFat(const Food& a, const Food& b);
    static bool sortSatFat(const Food& a, const Food& b);
    static bool sortTotalFat(const Food& a, const Food& b);
    static bool sortCalcium(const Food& a, const Food& b);
    static bool sortCopper(const Food& a, const Food& b);
    static bool sortIron(const Food& a, const Food& b);
    static bool sortMagnesium(const Food& a, const Food& b);
    static bool sortPhosphorus(const Food& a, const Food& b);
    static bool sortPotassium(const Food& a, const Food& b);
    static bool sortSodium(const Food& a, const Food& b);
    static bool sortZinc(const Food& a, const Food& b);
    static bool sortVitARAE(const Food& a, const Food& b);
    static bool sortVitB12(const Food& a, const Food& b);
    static bool sortVitB6(const Food& a, const Food& b);
    static bool sortVitC(const Food& a, const Food& b);
    static bool sortVitE(const Food& a, const Food& b);
    static bool sortVitK(const Food& a, const Food& b);

public:

    //Constructor
    explicit FoodFinder(const std::string& filename);

    //Insert Function
    void insert(const Food& food);

    //Sort Function
    void sortNutrient(std::vector<Food>& result, const std::string& nutrition); //sorts in descending order by nutrient

    //Search Functions
    std::vector<Food> searchMap(std::string category);
    std::vector<Food> searchTree(const std::string& category);
    std::vector<Food> searchMapNutrientDesc(std::string category, const std::string& nutrition);
    std::vector<Food> searchMapNutrientAsc(std::string category, const std::string& nutrition);
    std::vector<Food> searchTreeNutrientDesc(const std::string& category, const std::string& nutrition);
    std::vector<Food> searchTreeNutrientAsc(const std::string& category, const std::string& nutrition);



};

#include "FoodFinder.h"

#include <utility>

FoodFinder::FoodFinder(const std::string& filename)
{
    std::string fileName = "food.csv"; // File name
    std::vector<Food> foods = loadFromFile(filename); // vector to hold all Food instances

    for (const auto& food : foods)
    {
        tree.insert(food);
        map.insertFood(food);
    }
}

//Insert Function

void FoodFinder::insert(const Food& food)
{
    tree.insert(food);
    map.insertFood(food);
}


//Sorting Functions

bool FoodFinder::sortNdbsNumber(const Food& a, const Food& b) { return (a.getNdbsNumber() > b.getNdbsNumber()); }
bool FoodFinder::sortAlphaCarotene(const Food& a, const Food& b) { return (a.getAlphaCarotene() > b.getAlphaCarotene()); }
bool FoodFinder::sortBetaCarotene(const Food& a, const Food& b) { return (a.getBetaCarotene() > b.getBetaCarotene()); }
bool FoodFinder::sortBetaCryptoxanthin(const Food& a, const Food& b) { return (a.getBetaCryptoxanthin() > b.getBetaCryptoxanthin()); }
bool FoodFinder::sortCarbohydrate(const Food& a, const Food& b) { return (a.getCarbohydrate() > b.getCarbohydrate()); }
bool FoodFinder::sortCholesterol(const Food& a, const Food& b) { return (a.getCholesterol() > b.getCholesterol()); }
bool FoodFinder::sortCholine(const Food& a, const Food& b) { return (a.getCholine() > b.getCholine()); }
bool FoodFinder::sortFiber(const Food& a, const Food& b) { return (a.getFiber() > b.getFiber()); }
bool FoodFinder::sortLuteinZeaxanthin(const Food& a, const Food& b) { return (a.getLuteinZeaxanthin() > b.getLuteinZeaxanthin()); }
bool FoodFinder::sortLycopene(const Food& a, const Food& b) { return (a.getLycopene() > b.getLycopene()); }
bool FoodFinder::sortNiacin(const Food& a, const Food& b) { return (a.getNiacin() > b.getNiacin()); }
bool FoodFinder::sortProtein(const Food& a, const Food& b) { return (a.getProtein() > b.getProtein()); }
bool FoodFinder::sortRetinol(const Food& a, const Food& b) { return (a.getRetinol() > b.getRetinol()); }
bool FoodFinder::sortRiboflavin(const Food& a, const Food& b) { return (a.getRiboflavin() > b.getRiboflavin()); }
bool FoodFinder::sortSelenium(const Food& a, const Food& b) { return (a.getSelenium() > b.getSelenium()); }
bool FoodFinder::sortSugarTotal(const Food& a, const Food& b) { return (a.getSugarTotal() > b.getSugarTotal()); }
bool FoodFinder::sortThiamin(const Food& a, const Food& b) { return (a.getThiamin() > b.getThiamin()); }
bool FoodFinder::sortWater(const Food& a, const Food& b) { return (a.getWater() > b.getWater()); }
bool FoodFinder::sortMonoFat(const Food& a, const Food& b) { return (a.getMonoFat() > b.getMonoFat()); }
bool FoodFinder::sortPolyFat(const Food& a, const Food& b) { return (a.getPolyFat() > b.getPolyFat()); }
bool FoodFinder::sortSatFat(const Food& a, const Food& b) { return (a.getSatFat() > b.getSatFat()); }
bool FoodFinder::sortTotalFat(const Food& a, const Food& b) { return (a.getTotalFat() > b.getTotalFat()); }
bool FoodFinder::sortCalcium(const Food& a, const Food& b) { return (a.getCalcium() > b.getCalcium()); }
bool FoodFinder::sortCopper(const Food& a, const Food& b) { return (a.getCopper() > b.getCopper()); }
bool FoodFinder::sortIron(const Food& a, const Food& b){return (a.getIron() > b.getIron());}
bool FoodFinder::sortMagnesium(const Food& a, const Food& b) { return (a.getMagnesium() > b.getMagnesium()); }
bool FoodFinder::sortPhosphorus(const Food& a, const Food& b) { return (a.getPhosphorus() > b.getPhosphorus()); }
bool FoodFinder::sortPotassium(const Food& a, const Food& b) { return (a.getPotassium() > b.getPotassium()); }
bool FoodFinder::sortSodium(const Food& a, const Food& b) { return (a.getSodium() > b.getSodium()); }
bool FoodFinder::sortZinc(const Food& a, const Food& b) { return (a.getZinc() > b.getZinc()); }
bool FoodFinder::sortVitARAE(const Food& a, const Food& b) { return (a.getVitaminARAE() > b.getVitaminARAE()); }
bool FoodFinder::sortVitB12(const Food& a, const Food& b) { return (a.getVitaminB12() > b.getVitaminB12()); }
bool FoodFinder::sortVitB6(const Food& a, const Food& b) { return (a.getVitaminB6() > b.getVitaminB6()); }
bool FoodFinder::sortVitC(const Food& a, const Food& b) { return (a.getVitaminC() > b.getVitaminC()); }
bool FoodFinder::sortVitE(const Food& a, const Food& b) { return (a.getVitaminE() > b.getVitaminE()); }
bool FoodFinder::sortVitK(const Food& a, const Food& b) { return (a.getVitaminK() > b.getVitaminK()); }

void FoodFinder::sortNutrient(std::vector<Food>& result, const std::string& nutrition)
{
    if(nutrition == "Nutrient Data Bank Number")
        sort(result.begin(), result.end(), sortNdbsNumber);
    else if(nutrition == "Alpha Carotene")
        sort(result.begin(), result.end(), sortAlphaCarotene);
    else if(nutrition == "Beta Carotene")
        sort(result.begin(), result.end(), sortBetaCarotene);
    else if(nutrition == "Beta Cryptoxanthin")
        sort(result.begin(), result.end(), sortBetaCryptoxanthin);
    else if(nutrition == "Carbohydrate")
        sort(result.begin(), result.end(), sortCarbohydrate);
    else if(nutrition == "Cholesterol")
        sort(result.begin(), result.end(), sortCholesterol);
    else if(nutrition == "Choline")
        sort(result.begin(), result.end(), sortCholine);
    else if(nutrition == "Fiber")
        sort(result.begin(), result.end(), sortFiber);
    else if(nutrition == "Lutein and Zeaxanthin")
        sort(result.begin(), result.end(), sortLuteinZeaxanthin);
    else if(nutrition == "Lycopene")
        sort(result.begin(), result.end(), sortLycopene);
    else if(nutrition == "Niacin")
        sort(result.begin(), result.end(), sortNiacin);
    else if(nutrition == "Protein")
        sort(result.begin(), result.end(), sortProtein);
    else if(nutrition == "Retinol")
        sort(result.begin(), result.end(), sortRetinol);
    else if(nutrition == "Riboflavin")
        sort(result.begin(), result.end(), sortRiboflavin);
    else if(nutrition == "Selenium")
        sort(result.begin(), result.end(), sortSelenium);
    else if(nutrition == "Sugar Total")
        sort(result.begin(), result.end(), sortSugarTotal);
    else if(nutrition == "Thiamin")
        sort(result.begin(), result.end(), sortThiamin);
    else if(nutrition == "Water")
        sort(result.begin(), result.end(), sortWater);
    else if(nutrition == "Monosaturated Fat")
        sort(result.begin(), result.end(), sortMonoFat);
    else if(nutrition == "Polysaturated Fat")
        sort(result.begin(), result.end(), sortPolyFat);
    else if(nutrition == "Saturated Fat")
        sort(result.begin(), result.end(), sortSatFat);
    else if(nutrition == "Total Lipid")
        sort(result.begin(), result.end(), sortTotalFat);
    else if(nutrition == "Calcium")
        sort(result.begin(), result.end(), sortCalcium);
    else if(nutrition == "Copper")
        sort(result.begin(), result.end(), sortCopper);
    else if(nutrition == "Iron")
        sort(result.begin(), result.end(), sortIron);
    else if(nutrition == "Magnesium")
        sort(result.begin(), result.end(), sortMagnesium);
    else if(nutrition == "Phosphorus")
        sort(result.begin(), result.end(), sortPhosphorus);
    else if(nutrition == "Potassium")
        sort(result.begin(), result.end(), sortPotassium);
    else if(nutrition == "Sodium")
        sort(result.begin(), result.end(), sortSodium);
    else if(nutrition == "Zinc")
        sort(result.begin(), result.end(), sortZinc);
    else if(nutrition == "Vitamin A - RAE")
        sort(result.begin(), result.end(), sortVitARAE);
    else if(nutrition == "Vitamin B12")
        sort(result.begin(), result.end(), sortVitB12);
    else if(nutrition == "Vitamin B6")
        sort(result.begin(), result.end(), sortVitB6);
    else if(nutrition == "Vitamin C")
        sort(result.begin(), result.end(), sortVitC);
    else if(nutrition == "Vitamin E")
        sort(result.begin(), result.end(), sortVitE);
    else if(nutrition == "Vitamin K")
        sort(result.begin(), result.end(), sortVitK);
}


//Search Functions

std::vector<Food> FoodFinder::searchMap(std::string category)
{
    return map.search(std::move(category));
}

std::vector<Food> FoodFinder::searchTree(const std::string& category)
{
    return tree.search(category);
}


std::vector<Food> FoodFinder::searchMapNutrientDesc(std::string category, const std::string& nutrition)
{
    std::vector<Food> result = map.search(std::move(category));
    FoodFinder::sortNutrient(result, nutrition);
    return result;
}

std::vector<Food> FoodFinder::searchMapNutrientAsc(std::string category, const std::string& nutrition)
{
    std::vector<Food> result = searchMapNutrientDesc(std::move(category), nutrition);
    reverse(result.begin(), result.end());
    return result;
}


std::vector<Food> FoodFinder::searchTreeNutrientDesc(const std::string& category, const std::string& nutrition)
{
    std::vector<Food> result = tree.search(category);
    FoodFinder::sortNutrient(result, nutrition);
    return result;
}

std::vector<Food> FoodFinder::searchTreeNutrientAsc(const std::string& category, const std::string& nutrition)
{
    std::vector<Food> result = searchTreeNutrientDesc(category, nutrition);
    reverse(result.begin(), result.end());
    return result;
}


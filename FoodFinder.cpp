
#include "FoodFinder.h"

FoodFinder::FoodFinder(std::string filename)
{
    this->map = map;
    std::string fileName = "food.csv"; // File name
    std::vector<Food> foods = loadFromFile(filename); // vector to hold all Food instances

    for (const auto& food : foods)
    {
        tree.insert(food);
        map.insertFood(food);
    }
}

//Insert Function

void FoodFinder::insert(Food food)
{
    tree.insert(food);
    map.insertFood(food);
}


//Sorting Functions

bool FoodFinder::sortNdbsNumber(Food a, Food b) { return (a.getNdbsNumber() > b.getNdbsNumber()); }
bool FoodFinder::sortAlphaCarotene(Food a, Food b) { return (a.getAlphaCarotene() > b.getAlphaCarotene()); }
bool FoodFinder::sortBetaCarotene(Food a, Food b) { return (a.getBetaCarotene() > b.getBetaCarotene()); }
bool FoodFinder::sortBetaCryptoxanthin(Food a, Food b) { return (a.getBetaCryptoxanthin() > b.getBetaCryptoxanthin()); }
bool FoodFinder::sortCarbohydrate(Food a, Food b) { return (a.getCarbohydrate() > b.getCarbohydrate()); }
bool FoodFinder::sortCholesterol(Food a, Food b) { return (a.getCholesterol() > b.getCholesterol()); }
bool FoodFinder::sortCholine(Food a, Food b) { return (a.getCholine() > b.getCholine()); }
bool FoodFinder::sortFiber(Food a, Food b) { return (a.getFiber() > b.getFiber()); }
bool FoodFinder::sortLuteinZeaxanthin(Food a, Food b) { return (a.getLuteinZeaxanthin() > b.getLuteinZeaxanthin()); }
bool FoodFinder::sortLycopene(Food a, Food b) { return (a.getLycopene() > b.getLycopene()); }
bool FoodFinder::sortNiacin(Food a, Food b) { return (a.getNiacin() > b.getNiacin()); }
bool FoodFinder::sortProtein(Food a, Food b) { return (a.getProtein() > b.getProtein()); }
bool FoodFinder::sortRetinol(Food a, Food b) { return (a.getRetinol() > b.getRetinol()); }
bool FoodFinder::sortRiboflavin(Food a, Food b) { return (a.getRiboflavin() > b.getRiboflavin()); }
bool FoodFinder::sortSelenium(Food a, Food b) { return (a.getSelenium() > b.getSelenium()); }
bool FoodFinder::sortSugarTotal(Food a, Food b) { return (a.getSugarTotal() > b.getSugarTotal()); }
bool FoodFinder::sortThiamin(Food a, Food b) { return (a.getThiamin() > b.getThiamin()); }
bool FoodFinder::sortWater(Food a, Food b) { return (a.getWater() > b.getWater()); }
bool FoodFinder::sortMonoFat(Food a, Food b) { return (a.getMonoFat() > b.getMonoFat()); }
bool FoodFinder::sortPolyFat(Food a, Food b) { return (a.getPolyFat() > b.getPolyFat()); }
bool FoodFinder::sortSatFat(Food a, Food b) { return (a.getSatFat() > b.getSatFat()); }
bool FoodFinder::sortTotalFat(Food a, Food b) { return (a.getTotalFat() > b.getTotalFat()); }
bool FoodFinder::sortCalcium(Food a, Food b) { return (a.getCalcium() > b.getCalcium()); }
bool FoodFinder::sortCopper(Food a, Food b) { return (a.getCopper() > b.getCopper()); }
bool FoodFinder::sortIron(Food a, Food b){return (a.getIron() > b.getIron());}
bool FoodFinder::sortMagnesium(Food a, Food b) { return (a.getMagnesium() > b.getMagnesium()); }
bool FoodFinder::sortPhosphorus(Food a, Food b) { return (a.getPhosphorus() > b.getPhosphorus()); }
bool FoodFinder::sortPotassium(Food a, Food b) { return (a.getPotassium() > b.getPotassium()); }
bool FoodFinder::sortSodium(Food a, Food b) { return (a.getSodium() > b.getSodium()); }
bool FoodFinder::sortZinc(Food a, Food b) { return (a.getZinc() > b.getZinc()); }
bool FoodFinder::sortVitARAE(Food a, Food b) { return (a.getVitaminARAE() > b.getVitaminARAE()); }
bool FoodFinder::sortVitB12(Food a, Food b) { return (a.getVitaminB12() > b.getVitaminB12()); }
bool FoodFinder::sortVitB6(Food a, Food b) { return (a.getVitaminB6() > b.getVitaminB6()); }
bool FoodFinder::sortVitC(Food a, Food b) { return (a.getVitaminC() > b.getVitaminC()); }
bool FoodFinder::sortVitE(Food a, Food b) { return (a.getVitaminE() > b.getVitaminE()); }
bool FoodFinder::sortVitK(Food a, Food b) { return (a.getVitaminK() > b.getVitaminK()); }

void FoodFinder::sortNutrient(std::vector<Food>& result, std::string nutrition)
{
    if(nutrition == "ndbNumber")
        sort(result.begin(), result.end(), sortNdbsNumber);
    else if(nutrition == "alphaCarotene")
        sort(result.begin(), result.end(), sortAlphaCarotene);
    else if(nutrition == "betaCarotene")
        sort(result.begin(), result.end(), sortBetaCarotene);
    else if(nutrition == "betaCryptoxanthin")
        sort(result.begin(), result.end(), sortBetaCryptoxanthin);
    else if(nutrition == "carbohydrate")
        sort(result.begin(), result.end(), sortCarbohydrate);
    else if(nutrition == "cholesterol")
        sort(result.begin(), result.end(), sortCholesterol);
    else if(nutrition == "choline")
        sort(result.begin(), result.end(), sortCholine);
    else if(nutrition == "fiber")
        sort(result.begin(), result.end(), sortFiber);
    else if(nutrition == "luteinZeaxanthin")
        sort(result.begin(), result.end(), sortLuteinZeaxanthin);
    else if(nutrition == "lycopene")
        sort(result.begin(), result.end(), sortLycopene);
    else if(nutrition == "niacin")
        sort(result.begin(), result.end(), sortNiacin);
    else if(nutrition == "protein")
        sort(result.begin(), result.end(), sortProtein);
    else if(nutrition == "retinol")
        sort(result.begin(), result.end(), sortRetinol);
    else if(nutrition == "riboflavin")
        sort(result.begin(), result.end(), sortRiboflavin);
    else if(nutrition == "selenium")
        sort(result.begin(), result.end(), sortSelenium);
    else if(nutrition == "sugarTotal")
        sort(result.begin(), result.end(), sortSugarTotal);
    else if(nutrition == "thiamin")
        sort(result.begin(), result.end(), sortThiamin);
    else if(nutrition == "water")
        sort(result.begin(), result.end(), sortWater);
    else if(nutrition == "monoFat")
        sort(result.begin(), result.end(), sortMonoFat);
    else if(nutrition == "polyFat")
        sort(result.begin(), result.end(), sortPolyFat);
    else if(nutrition == "satFat")
        sort(result.begin(), result.end(), sortSatFat);
    else if(nutrition == "totalFat")
        sort(result.begin(), result.end(), sortTotalFat);
    else if(nutrition == "calcium")
        sort(result.begin(), result.end(), sortCalcium);
    else if(nutrition == "copper")
        sort(result.begin(), result.end(), sortCopper);
    else if(nutrition == "iron")
        sort(result.begin(), result.end(), sortIron);
    else if(nutrition == "magnesium")
        sort(result.begin(), result.end(), sortMagnesium);
    else if(nutrition == "phosphorus")
        sort(result.begin(), result.end(), sortPhosphorus);
    else if(nutrition == "potassium")
        sort(result.begin(), result.end(), sortPotassium);
    else if(nutrition == "sodium")
        sort(result.begin(), result.end(), sortSodium);
    else if(nutrition == "zinc")
        sort(result.begin(), result.end(), sortZinc);
    else if(nutrition == "vitARAE")
        sort(result.begin(), result.end(), sortVitARAE);
    else if(nutrition == "vitB12")
        sort(result.begin(), result.end(), sortVitB12);
    else if(nutrition == "vitB6")
        sort(result.begin(), result.end(), sortVitB6);
    else if(nutrition == "vitC")
        sort(result.begin(), result.end(), sortVitC);
    else if(nutrition == "vitE")
        sort(result.begin(), result.end(), sortVitE);
    else if(nutrition == "vitK")
        sort(result.begin(), result.end(), sortVitK);
    return;
}


//Search Functions

std::vector<Food> FoodFinder::searchMap(std::string category)
{
    return map.search(category);
}

std::vector<Food> FoodFinder::searchTree(std::string category)
{
    return tree.search(category);
}


std::vector<Food> FoodFinder::searchMapNutrientDesc(std::string category, std::string nutrition)
{
    std::vector<Food> result = map.search(category);
    FoodFinder::sortNutrient(result, nutrition);
    return result;
}

std::vector<Food> FoodFinder::searchMapNutrientAsc(std::string category, std::string nutrition)
{
    std::vector<Food> result = searchMapNutrientDesc(category, nutrition);
    reverse(result.begin(), result.end());
    return result;
}


std::vector<Food> FoodFinder::searchTreeNutrientDesc(std::string category, std::string nutrition)
{
    std::vector<Food> result = tree.search(category);
    FoodFinder::sortNutrient(result, nutrition);
    return result;
}

std::vector<Food> FoodFinder::searchTreeNutrientAsc(std::string category, std::string nutrition)
{
    std::vector<Food> result = searchTreeNutrientDesc(category, nutrition);
    reverse(result.begin(), result.end());
    return result;
}


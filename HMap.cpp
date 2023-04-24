#include "HMap.h"

FoodMap::FoodCategory::FoodCategory(std::string& name)
{
    this->name = name;
}

void FoodMap::FoodCategory::insertFood(Food food)
{
    foodstuffs.push_back(food);
}

FoodMap::FoodMap(int buckets, float maxload)
{
    this->buckets = buckets;
    this->maxload = maxload;
    loadfactor = 0.0f;
    filled = 0;
    while(foodmap.size() < buckets) //allows for [] access of empty rows used in insertFood
    {
        std::vector<FoodCategory> emptyvec;
        foodmap.push_back(emptyvec);
    }
}

int FoodMap::hashFunction(std::string& catname)
{
    int result = 0;
    for(char c : catname)
    {
        result += c;
    }
    return result % buckets;
}

void FoodMap::insertFood(Food food)
{
    std::string category = food.getCategory();
    int index = hashFunction(category);
    std::vector<FoodCategory>& row = foodmap[index];
    bool found = false;
    for(int i = 0;i < row.size();i++)
    {
        FoodCategory& cat = row[i];
        if(cat.name == food.getCategory())
        {
            cat.insertFood(food);
            found = true;
            break;
        }
    }

    if(!found)
    {
        std::string catname = food.getCategory();
        FoodCategory newcat(catname);
        newcat.foodstuffs.push_back(food);
        row.push_back(newcat);
        filled++;
    }
    loadfactor = float(filled)/buckets;
    if(loadfactor > maxload)
    {
        reHash();
    }
}

void FoodMap::insertCategory(FoodMap::FoodCategory cat)
{
    int index = hashFunction(cat.name);
    std::vector<FoodCategory>& row = foodmap[index];
    row.push_back(cat);
    filled++;
}


void FoodMap::reHash()
{
    buckets *= 2;
    std::vector<FoodCategory> holder;
    for(int i = 0;i < foodmap.size();i++)
    {
        for(int j = 0;j < foodmap[i].size();j++)
        {
            holder.push_back(foodmap[i][j]);
        }
    }
    std::vector<std::vector<FoodCategory>> emptymap;
    foodmap = emptymap;
    while(foodmap.size() < buckets)
    {
        std::vector<FoodCategory> emptyvec;
        foodmap.push_back(emptyvec);
    }
    for(FoodCategory cat : holder)
    {
        insertCategory(cat);
    }
}

std::vector<Food> FoodMap::search(std::string category)
{
    std::vector<Food> vec;
    int index = hashFunction(category);
    std::vector<FoodCategory>& row = foodmap[index];
    for(FoodCategory cat : row)
    {
        if(cat.name == category)
            vec = cat.foodstuffs;
    }
    return vec;
}

//Sorting Comparisons
bool FoodMap::sortNdbsNumber(Food a, Food b) { return (a.getNdbsNumber() > b.getNdbsNumber()); }
bool FoodMap::sortAlphaCarotene(Food a, Food b) { return (a.getAlphaCarotene() > b.getAlphaCarotene()); }
bool FoodMap::sortBetaCarotene(Food a, Food b) { return (a.getBetaCarotene() > b.getBetaCarotene()); }
bool FoodMap::sortBetaCryptoxanthin(Food a, Food b) { return (a.getBetaCryptoxanthin() > b.getBetaCryptoxanthin()); }
bool FoodMap::sortCarbohydrate(Food a, Food b) { return (a.getCarbohydrate() > b.getCarbohydrate()); }
bool FoodMap::sortCholesterol(Food a, Food b) { return (a.getCholesterol() > b.getCholesterol()); }
bool FoodMap::sortCholine(Food a, Food b) { return (a.getCholine() > b.getCholine()); }
bool FoodMap::sortFiber(Food a, Food b) { return (a.getFiber() > b.getFiber()); }
bool FoodMap::sortLuteinZeaxanthin(Food a, Food b) { return (a.getLuteinZeaxanthin() > b.getLuteinZeaxanthin()); }
bool FoodMap::sortLycopene(Food a, Food b) { return (a.getLycopene() > b.getLycopene()); }
bool FoodMap::sortNiacin(Food a, Food b) { return (a.getNiacin() > b.getNiacin()); }
bool FoodMap::sortProtein(Food a, Food b) { return (a.getProtein() > b.getProtein()); }
bool FoodMap::sortRetinol(Food a, Food b) { return (a.getRetinol() > b.getRetinol()); }
bool FoodMap::sortRiboflavin(Food a, Food b) { return (a.getRiboflavin() > b.getRiboflavin()); }
bool FoodMap::sortSelenium(Food a, Food b) { return (a.getSelenium() > b.getSelenium()); }
bool FoodMap::sortSugarTotal(Food a, Food b) { return (a.getSugarTotal() > b.getSugarTotal()); }
bool FoodMap::sortThiamin(Food a, Food b) { return (a.getThiamin() > b.getThiamin()); }
bool FoodMap::sortWater(Food a, Food b) { return (a.getWater() > b.getWater()); }
bool FoodMap::sortMonoFat(Food a, Food b) { return (a.getMonoFat() > b.getMonoFat()); }
bool FoodMap::sortPolyFat(Food a, Food b) { return (a.getPolyFat() > b.getPolyFat()); }
bool FoodMap::sortSatFat(Food a, Food b) { return (a.getSatFat() > b.getSatFat()); }
bool FoodMap::sortTotalFat(Food a, Food b) { return (a.getTotalFat() > b.getTotalFat()); }
bool FoodMap::sortCalcium(Food a, Food b) { return (a.getCalcium() > b.getCalcium()); }
bool FoodMap::sortCopper(Food a, Food b) { return (a.getCopper() > b.getCopper()); }
bool FoodMap::sortIron(Food a, Food b){return (a.getIron() > b.getIron());}
bool FoodMap::sortMagnesium(Food a, Food b) { return (a.getMagnesium() > b.getMagnesium()); }
bool FoodMap::sortPhosphorus(Food a, Food b) { return (a.getPhosphorus() > b.getPhosphorus()); }
bool FoodMap::sortPotassium(Food a, Food b) { return (a.getPotassium() > b.getPotassium()); }
bool FoodMap::sortSodium(Food a, Food b) { return (a.getSodium() > b.getSodium()); }
bool FoodMap::sortZinc(Food a, Food b) { return (a.getZinc() > b.getZinc()); }
bool FoodMap::sortVitARAE(Food a, Food b) { return (a.getVitaminARAE() > b.getVitaminARAE()); }
bool FoodMap::sortVitB12(Food a, Food b) { return (a.getVitaminB12() > b.getVitaminB12()); }
bool FoodMap::sortVitB6(Food a, Food b) { return (a.getVitaminB6() > b.getVitaminB6()); }
bool FoodMap::sortVitC(Food a, Food b) { return (a.getVitaminC() > b.getVitaminC()); }
bool FoodMap::sortVitE(Food a, Food b) { return (a.getVitaminE() > b.getVitaminE()); }
bool FoodMap::sortVitK(Food a, Food b) { return (a.getVitaminK() > b.getVitaminK()); }

std::vector<Food> FoodMap::search(std::string category, std::string nutrition)
{
    std::vector<Food> result = search(category);
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
    return result;
}
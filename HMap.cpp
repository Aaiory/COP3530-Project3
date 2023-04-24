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
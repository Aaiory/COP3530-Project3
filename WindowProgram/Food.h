#ifndef FINAL_PROJECT_2_FOOD_H
#define FINAL_PROJECT_2_FOOD_H

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

class Food {
private:
    std::string category;
    std::string description;
    unsigned int ndbNumber;
    unsigned int alphaCarotene;
    unsigned int betaCarotene;
    unsigned int betaCryptoxanthin;
    float carbohydrate;
    unsigned int cholesterol;
    float choline;
    float fiber;
    unsigned int luteinZeaxanthin;
    unsigned int lycopene;
    float niacin;
    float protein;
    unsigned int retinol;
    float riboflavin;
    float selenium;
    float sugarTotal;
    float thiamin;
    float water;
    float monoFat;
    float polyFat;
    float satFat;
    float totalFat;
    unsigned int calcium;
    float copper;
    float iron;
    unsigned int magnesium;
    unsigned int phosphorus;
    unsigned int potassium;
    unsigned int sodium;
    float zinc;
    unsigned int vitARAE;
    float vitB12;
    float vitB6;
    float vitC;
    float vitE;
    float vitK;
public:
    Food(std::string category, std::string description, unsigned int ndbNumber, unsigned int alphaCarotene,
         unsigned int betaCarotene, unsigned int betaCryptoxanthin, float carbohydrate, unsigned int cholesterol,
         float choline, float fiber, unsigned int luteinZeaxanthin, unsigned int lycopene, float niacin,
         float protein, unsigned int retinol, float riboflavin, float selenium, float sugarTotal,
         float thiamin, float water, float monoFat, float polyFat, float satFat, float totalFat,
         unsigned int calcium, float copper, float iron, unsigned int magnesium, unsigned int phosphorus, unsigned int potassium,
         unsigned int sodium, float zinc, unsigned int vitARAE, float vitB12, float vitB6, float vitC, float vitE,
         float vitK) : category(std::move(category)), description(std::move(description)), ndbNumber(ndbNumber),
                       alphaCarotene(alphaCarotene), betaCarotene(betaCarotene), betaCryptoxanthin(betaCryptoxanthin),
                       carbohydrate(carbohydrate), cholesterol(cholesterol), choline(choline), fiber(fiber),
                       luteinZeaxanthin(luteinZeaxanthin), lycopene(lycopene), niacin(niacin), protein(protein),
                       retinol(retinol), riboflavin(riboflavin), selenium(selenium), sugarTotal(sugarTotal),
                       thiamin(thiamin), water(water), monoFat(monoFat), polyFat(polyFat), satFat(satFat),
                       totalFat(totalFat), calcium(calcium), copper(copper), iron(iron), magnesium(magnesium),
                       phosphorus(phosphorus), potassium(potassium), sodium(sodium), zinc(zinc), vitARAE(vitARAE),
                       vitB12(vitB12), vitB6(vitB6), vitC(vitC), vitE(vitE), vitK(vitK) {}

    void printValuesInFood();
    std::string getCategory() const { return category; }
    std::string getDescription() const { return description; }
    unsigned int getNdbsNumber() const { return ndbNumber; }
    unsigned int getAlphaCarotene() const { return alphaCarotene; }
    unsigned int getBetaCarotene() const { return betaCarotene; }
    unsigned int getBetaCryptoxanthin() const { return betaCryptoxanthin; }
    float getCarbohydrate() const { return carbohydrate; }
    unsigned int getCholesterol() const { return cholesterol; }
    float getCholine() const { return choline; }
    float getFiber() const { return fiber; }
    unsigned int getLuteinZeaxanthin() const { return luteinZeaxanthin; }
    unsigned int getLycopene() const { return lycopene; }
    float getNiacin() const { return niacin; }
    float getProtein() const { return protein; }
    unsigned int getRetinol() const { return retinol; }
    float getRiboflavin() const { return riboflavin; }
    float getSelenium() const { return selenium; }
    float getSugarTotal() const { return sugarTotal; }
    float getThiamin() const { return thiamin; }
    float getWater() const { return water; }
    float getMonoFat() const { return monoFat; }
    float getPolyFat() const { return polyFat; }
    float getSatFat() const { return satFat; }
    float getTotalFat() const { return totalFat; }
    unsigned int getCalcium() const { return calcium; }
    float getCopper() const { return copper; }
    float getIron() const { return iron; }
    unsigned int getMagnesium() const { return magnesium; }
    unsigned int getPhosphorus() const { return phosphorus; }
    unsigned int getPotassium() const { return potassium; }
    unsigned int getSodium() const { return sodium; }
    float getZinc() const { return zinc; }
    unsigned int getVitaminARAE() const { return vitARAE; }
    float getVitaminB12() const { return vitB12; }
    float getVitaminB6() const { return vitB6; }
    float getVitaminC() const { return vitC; }
    float getVitaminE() const { return vitE; }
    float getVitaminK() const { return vitK; }
};


static std::vector<Food> loadFromFile(const std::string& fileName) {
    std::vector<Food> foods;
    std::ifstream file("../" + fileName);

    if (!file) {
        throw std::runtime_error("Error opening file " + fileName);
    }

    std::string line;
    getline(file, line);  // skip the header line

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string field;

        // Parse the category field
        getline(ss, field, ',');
        std::string category = field;

        // Parse the description field
        std::string description;
        if (getline(ss, field, ',') && field.front() == '"') {
            description = field.substr(1);  // skip the opening quotation mark
            while (getline(ss, field, ',') && field.back() != '"') {
                description += "," + field;
            }
            if (!field.empty()) {
                // field ends with a closing quotation mark
                description += "," + field.substr(0, field.size()-1);
            }
        } else {
            description = field;
        }

        // Parse the remaining fields and convert them to the appropriate data types
        unsigned int ndbNumber, alphaCarotene, betaCarotene, betaCryptoxanthin, cholesterol,
                luteinZeaxanthin, lycopene, retinol, calcium, magnesium,
                phosphorus, potassium, sodium, vitARAE;
        float carbohydrate, choline, fiber, niacin, protein, riboflavin, selenium,
                sugarTotal, thiamin, water, monoFat, polyFat, satFat, totalFat, zinc,
                vitB12, vitB6, vitC, vitE, vitK, copper, iron;

        getline(ss, field, ','); ndbNumber = std::stoi(field);
        getline(ss, field, ','); alphaCarotene = std::stoi(field);
        getline(ss, field, ','); betaCarotene = std::stoi(field);
        getline(ss, field, ','); betaCryptoxanthin = std::stoi(field);
        getline(ss, field, ','); carbohydrate = std::stof(field);
        getline(ss, field, ','); cholesterol = std::stoi(field);
        getline(ss, field, ','); choline = std::stof(field);
        getline(ss, field, ','); fiber = std::stof(field);
        getline(ss, field, ','); luteinZeaxanthin = std::stoi(field);
        getline(ss, field, ','); lycopene = std::stoi(field);
        getline(ss, field, ','); niacin = std::stof(field);
        getline(ss, field, ','); protein = std::stof(field);
        getline(ss, field, ','); retinol = std::stoi(field);
        getline(ss, field, ','); riboflavin = std::stof(field);
        getline(ss, field, ','); selenium = std::stof(field);
        getline(ss, field, ','); sugarTotal = std::stof(field);
        getline(ss, field, ','); thiamin = std::stof(field);
        getline(ss, field, ','); water = std::stof(field);
        getline(ss, field, ','); monoFat = std::stof(field);
        getline(ss, field, ','); polyFat = std::stof(field);
        getline(ss, field, ','); satFat = std::stof(field);
        getline(ss, field, ','); totalFat = std::stof(field);
        getline(ss, field, ','); calcium = std::stoi(field);
        getline(ss, field, ','); copper = std::stof(field);
        getline(ss, field, ','); iron = std::stof(field);
        getline(ss, field, ','); magnesium = std::stoi(field);
        getline(ss, field, ','); phosphorus = std::stoi(field);
        getline(ss, field, ','); potassium = std::stoi(field);
        getline(ss, field, ','); sodium = std::stoi(field);
        getline(ss, field, ','); zinc = std::stof(field);
        getline(ss, field, ','); vitARAE = std::stoi(field);
        getline(ss, field, ','); vitB12 = std::stof(field);
        getline(ss, field, ','); vitB6 = std::stof(field);
        getline(ss, field, ','); vitC = std::stof(field);
        getline(ss, field, ','); vitE = std::stof(field);
        getline(ss, field, ','); vitK = std::stof(field);

        // Create a new Food object
        Food food(category, description, ndbNumber, alphaCarotene, betaCarotene, betaCryptoxanthin, carbohydrate, cholesterol,
                  choline, fiber, luteinZeaxanthin, lycopene, niacin, protein, retinol, riboflavin,
                  selenium, sugarTotal, thiamin, water, monoFat, polyFat, satFat, totalFat, calcium,
                  copper, iron, magnesium, phosphorus, potassium, sodium, zinc, vitARAE, vitB12, vitB6, vitC, vitE, vitK);
        foods.push_back(food);
    }
    return  foods;
}


#endif //FINAL_PROJECT_2_FOOD_H

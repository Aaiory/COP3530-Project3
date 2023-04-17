#include "Food.h"

std::vector<Food> loadFromFile(const std::string &fileName) {
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

std::vector<std::string> loadHeadersFromFile(const std::string &filename) {
    std::vector<std::string> headers;
    std::ifstream file("../" + filename);
    if (file.is_open()) {
        std::string line;
        if (std::getline(file, line)) {
            std::istringstream ss(line);
            std::string header;
            while (std::getline(ss, header, ',')) {
                headers.push_back(header);
            }
        }
        file.close();
    }
    return headers;
}

void Food::printValuesInFood() {
    std::cout << category << ", " <<
              description << "," <<
              ndbNumber << "," <<
              alphaCarotene << "," <<
              betaCarotene << "," <<
              betaCryptoxanthin << "," <<
              carbohydrate << "," <<
              cholesterol << "," <<
              choline << "," <<
              fiber << "," <<
              luteinZeaxanthin << "," <<
              lycopene << "," <<
              niacin << "," <<
              protein << "," <<
              retinol << "," <<
              riboflavin << "," <<
              selenium << "," <<
              sugarTotal << "," <<
              thiamin << "," <<
              water << "," <<
              monoFat << "," <<
              polyFat << "," <<
              satFat << "," <<
              totalFat << "," <<
              calcium << "," <<
              copper << "," <<
              iron << "," <<
              magnesium << "," <<
              phosphorus << "," <<
              potassium << "," <<
              sodium << "," <<
              zinc << "," <<
              vitARAE << "," <<
              vitB12 << "," <<
              vitB6 << "," <<
              vitC << "," <<
              vitE << "," <<
              vitK << std::endl;
}

#include <iostream>
#include <fstream>
#include <iterator>
#include <iomanip>
#include "Breed.h"
#include "Monster.h"
#include "cJson/cJSON.h"
#include <vector>


std::vector<Monsters::Breed *> CreateObjectsFromJson(cJSON *JSONFile) {
    std::vector<Monsters::Breed *> allMonsters;
    cJSON *JsonObjects = NULL;
    cJSON *breedJson = NULL;
    cJSON *parentJson = NULL;
    cJSON *healthJson = NULL;
    cJSON *attackJson = NULL;


    if (JSONFile == NULL) {
        std::cerr << "Couldn't parse";
        exit(-10);
    }
    cJSON_ArrayForEach(JsonObjects, JSONFile) {
        breedJson = JsonObjects;
        parentJson = cJSON_GetObjectItemCaseSensitive(breedJson, "parent");
        healthJson = cJSON_GetObjectItemCaseSensitive(breedJson, "health");
        attackJson = cJSON_GetObjectItemCaseSensitive(breedJson, "attack");
        if (parentJson == NULL) {
            allMonsters.push_back(
                    new Monsters::Breed(nullptr, cJSON_GetNumberValue(healthJson), cJSON_GetStringValue(attackJson),
                                        breedJson->string));
        } else {
            Monsters::Breed *parent = NULL;
            for (auto monster: allMonsters) {
                auto n = monster->getName().get();
                if (((std::string) monster->getName().get()).compare(parentJson->string)) {
                    parent = monster;
                    break;
                }
            }
            allMonsters.push_back(
                    new Monsters::Breed(parent, cJSON_GetNumberValue(healthJson), cJSON_GetStringValue(attackJson),
                                        breedJson->string));
        }
    }

    return allMonsters;
}

int main() {
    constexpr char *PATH_TO_JSON_FILE("./../JsonFiles/Monsters.json");
    std::fstream JsonFile;
    std::stringstream ss;
    JsonFile.open(PATH_TO_JSON_FILE, std::ios::in | std::ios::out);
    if (JsonFile.is_open()) {
        while (ss << JsonFile.rdbuf()) {
        }
    }
    JsonFile.close();
    const std::string &StringFromStringStream = ss.str();
    const char *CharFromString = StringFromStringStream.c_str();
    cJSON *JSONString = cJSON_Parse(CharFromString);
    auto breeds = CreateObjectsFromJson(JSONString);
    std::vector<Monsters::Monster *> monsters;
    for (auto breed: breeds) {
        monsters.push_back(breed->newMonster());
        std::cout << monsters.at(monsters.size() - 1)->toString() << std::endl;
    }

    cJSON_Delete(JSONString);
    return 0;
}

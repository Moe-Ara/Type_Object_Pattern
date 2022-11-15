#include <iostream>
#include <fstream>
#include <iterator>
#include <iomanip>
#include "Breed.h"
#include "Monster.h"
#include "cJson/cJSON.h"
#include <vector>


std::vector<Monsters::Breed *> CreateObjectsFromJson(const char *const path) {
    std::vector<Monsters::Breed *> allMonsters;
    cJSON *JsonObjects = NULL;
    cJSON *breed = NULL;
    cJSON *parent = NULL;
    cJSON *health = NULL;
    cJSON *attack = NULL;
    cJSON *JSONFile = cJSON_Parse(path);
    if (path == NULL) {
        std::cerr << "Couldn't parse";
        exit(-10);
    }
    cJSON_ArrayForEach(JsonObjects, JSONFile) {
        cJSON_ArrayForEach(JsonObjects->child, JsonObjects) {
            breed = JsonObjects->child;
            parent = cJSON_GetObjectItemCaseSensitive(breed->child, "parent");
            health = cJSON_GetObjectItemCaseSensitive(breed->child, "health");
            attack = cJSON_GetObjectItemCaseSensitive(breed->child, "attack");
            std::shared_ptr<Monsters::Breed> MonsterBre(
                    new Monsters::Breed(nullptr, health->valueint, attack->valuestring));
            if (parent == NULL) {
                allMonsters.push_back(
                        new Monsters::Breed(nullptr, health->valueint, attack->valuestring, breed->child->string));
            } else {
                allMonsters.push_back(new Monsters::Breed(allMonsters.at(allMonsters.size() - 1), health->valueint,
                                                          attack->valuestring, breed->child->string));
            }


        }
    }
    cJSON_Delete(JSONFile);
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
    auto breeds = CreateObjectsFromJson(CharFromString);
    std::vector<Monsters::Monster *> monsters;
    for (auto breed: breeds) {
        monsters.push_back(breed->newMonster());
        std::cout << monsters.at(monsters.size() - 1)->toString() << std::endl;
    }


}

//
// Created by Mohamad on 11/14/2022.
//

#include <sstream>
#include "Breed.h"
using Monsters::Monster;
using Monsters::Breed;

auto Breed::getAttack() -> std::shared_ptr<const char> {
    if (m_AttackString != NULL || m_parent == NULL) {
        return std::make_shared<const char>(*m_AttackString);
    }
    return m_parent->getAttack();
}
auto Breed::getHealth() -> int {
    if (m_health != 0 || m_parent == NULL) {
        return m_health;
    }
    return m_parent->getHealth();
}
auto Breed::getParent() -> std::shared_ptr<Breed> {
    if (m_parent == NULL) {
        return NULL;
    }
    return std::shared_ptr<Breed>(m_parent);
}

auto Breed::newMonster() -> Monsters::Monster* {
    return new Monster(*this);
}

Breed::~Breed() {

}

Monsters::Breed::Breed(Breed* parent, int health, const char* attack):m_AttackString(attack),m_health(health),m_parent(parent) {

}

Monsters::Breed::Breed(Breed* parent, int health, const char* attack, const char* name):m_AttackString(attack),m_health(health),m_parent(parent),m_name(name) {

}

auto Breed::toString() -> std::string {
   std::stringstream ss;
   ss<<this->getHealth();
   std::string s;
   ss>>s;
   return (std::string)m_name +": "+"{ "+ "health: "+ s+ ", Attack: "+(std::string)m_AttackString + " }";
}
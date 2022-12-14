//
// Created by Mohamad on 11/14/2022.
//

#include <sstream>
//#include <string>
#include "Breed.h"
using Monsters::Monster;
using Monsters::Breed;

auto Breed::getAttack() -> std::shared_ptr<const char> {
    if (m_AttackString != NULL || m_parent == NULL) {
        return std::make_shared<const char>(*m_AttackString);
    }
    return m_parent->getAttack();
}

auto Breed::getName() -> std::shared_ptr<const char> {
    std::string  s;
    s.compare(" ");
    if (!((std::string) m_name).compare(" ")|| m_parent == NULL) {
        return std::make_shared<const char>(*m_name);
    }
    return m_parent->getName();
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



Monsters::Breed::Breed(Breed* parent, int health, const char* attack):m_AttackString(attack),m_health(health),m_parent(parent) {
    /*
    //TODO: IMPLEMENT THIS
    if(parent!=NULL)
    {
        if(health==0){
            m_health=parent.getHealth();
        }
        if(attack==NULL){
            m_attack=parent.getAttack();
        }
    } */

}

Monsters::Breed::Breed(Breed* parent, int health, const char* attack, const char* name):m_AttackString(attack),m_health(health),m_parent(parent),m_name(name) {

    
    /*
    //TODO: IMPLEMENT THIS
    if(parent!=NULL)
    {
        if(health==0){
            m_health=parent.getHealth();
        }
        if(attack==NULL){
            m_attack=parent.getAttack();
        }
        if(((std::string) m_name).compare(" ")){
            m_name=parent.getName();
        }
    } */
    
}

auto Breed::toString() -> std::string {
   std::stringstream ss;
   ss<<this->getHealth();
   std::string s;
   ss>>s;
   return (std::string)m_name +": "+"{ "+ "health: "+ s+ ", Attack: "+(std::string)m_AttackString + " }";
}
Breed::~Breed() {
delete m_parent;
delete m_AttackString;
delete m_name;
}

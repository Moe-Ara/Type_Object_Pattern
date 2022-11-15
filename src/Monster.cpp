//
// Created by Mohamad on 11/14/2022.
//

#include "Monster.h"
#include "Breed.h"
using Monsters::Monster;
using Monsters::Breed;
Monster::Monster(Breed &breed): m_breed(breed),m_health(breed.getHealth()) {}

int Monster::getHealth() {
    return m_health;
}

Breed& Monster::getBreed() {
    return m_breed;
}

std::shared_ptr<const char> Monster::getAttackString() {
    return m_breed.getAttack();
}

std::string Monster::toString() {
    return m_breed.toString();
}
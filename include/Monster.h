//
// Created by Mohamad on 11/14/2022.
//
#ifndef TYPEOBJECT_MONSTER_H
#define TYPEOBJECT_MONSTER_H
#include <iostream>
#include <memory>
namespace Monsters{
    class Breed;
    class Monster {
        friend class Breed;
    private:
        int m_health;
        Breed& m_breed;
        Monster(Breed&);//Constructor
        Monster(Monster&); //Copy Constructor
        ;//Destructor
    public:
        Breed& getBreed();
        int getHealth();
        std::shared_ptr<const char> getAttackString();
        std::string toString();

        //    Monster&(Monster&& monster);//move constructor
        //    Monster& operator=(Monster&&);//Move Assignment
        //    Monster& operator=(Monster&); //Assignment
                ~Monster(){}
    };

}


#endif //TYPEOBJECT_MONSTER_H

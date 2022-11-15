//
// Created by Mohamad on 11/14/2022.
//
#ifndef TYPEOBJECT_BREED_H
#define TYPEOBJECT_BREED_H

#include <iostream>
#include <memory>
#include "Monster.h"

namespace Monsters {
    class Breed {
        Breed *m_parent;
        int m_health;
        const char *m_AttackString;
        const char *m_name= " ";

    public:
        ~Breed();
        Breed(const Breed &) = delete; //copy Constructor
        Breed(Breed *, int, const char *);//Constructor
        Breed(Breed *, int, const char *, const char *);//Constructor
        auto getHealth() -> int;
        auto getAttack() -> std::shared_ptr<const char>;
        auto newMonster() -> Monsters::Monster *;
        auto getName() ->std::shared_ptr<const char>;
        auto getParent() -> std::shared_ptr<Breed>;
        auto toString()->std::string ;
        Breed();

    };
}


#endif //TYPEOBJECT_BREED_H

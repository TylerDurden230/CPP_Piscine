#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Const.hpp"

class Dog: public Animal{
    public:
        Dog();
        virtual ~Dog();
        virtual void makeSound() const;   
};


#endif
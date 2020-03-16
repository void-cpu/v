#include "../Mylife_H/DogAndCat.h"


Pet::Pet(std::string type) {
    this->type = type;
}

std::string Pet::getPetType() {
    return type;
}

CatDogQue::CatDogQue() {
    count = 0;
}

void CatDogQue::push(Pet pet) {
    if ("dog" == pet.getPetType())
        dogQ.push(PetStamp(pet, count++));
    else if ("cat" == pet.getPetType())
        catQ.push(PetStamp(pet, count++));
    else
        std::cout << "err,not dog or cat!";
}

Pet CatDogQue::popAll() {
    if (!catQ.empty() && !dogQ.empty()) {
        if (dogQ.front().getCount() < catQ.front().getCount()) {
            Pet tmp = dogQ.front().getPet();
            dogQ.pop();
            return tmp;
        } else {
            Pet tmp = catQ.front().getPet();
            catQ.pop();
            return tmp;
        }
    } else if (!catQ.empty()) {
        Pet tmp = catQ.front().getPet();
        catQ.pop();
        return tmp;
    } else if (!dogQ.empty()) {
        Pet tmp = dogQ.front().getPet();
        dogQ.pop();
        return tmp;
    } else
        std::cout << "Error,empty queue!";
}

Dog CatDogQue::popDog() {
    if (!dogQ.empty())
    {
        Pet tmpP = dogQ.front().getPet();
        Dog tmpD;
        Pet *pd = &tmpD;
        *pd = tmpP;

        dogQ.pop();
        return tmpD;
    }
    else
        std::cout << "Error,empty dog queue!";
    return Dog();
}

Cat CatDogQue::popCat() {
    if (!catQ.empty())
    {
        Pet tmpP = catQ.front().getPet();
        Cat tmpC;
        Pet *pc = &tmpC;
        *pc = tmpP;

        catQ.pop();
        return tmpC;
    }
    else
        std::cout << "Error,empty cat queue!";
    return Cat();
}

bool CatDogQue::isEmpty() {
    return dogQ.empty() && catQ.empty();
}

bool CatDogQue::isDogEmpty() {
    return dogQ.empty();
}

bool CatDogQue::isCatEmpty() {
    return catQ.empty();
}

Pet PetStamp::getPet() {
    return pet;
}

long PetStamp::getCount() {
    return count;
}

std::string PetStamp::getPetType() {
    return pet.getPetType();
}
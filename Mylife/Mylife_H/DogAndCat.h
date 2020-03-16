#ifndef UNTITLED1_DOGANDCAT_H
#define UNTITLED1_DOGANDCAT_H

#include <iostream>
#include <queue>

using namespace std;

/**
 *宠物的基类
**/
class Pet
{
public:
    Pet(std::string type);
    std::string getPetType();
private:
    std::string type;
};

/**
 *派生类=>继承于宠物类=>狗这个类
**/
class Dog : public Pet
{
public:
    Dog() : Pet("dog") {}
};

/**
 *派生类=>继承于宠物类=>猫这个类
**/
class Cat : public Pet
{
public:
    Cat() : Pet("cat") {}
};

class PetStamp
{
public:
    PetStamp(Pet p, long count) : pet(p){this->count = count;}

    Pet getPet();

    long getCount();

    std::string getPetType();

private:
    Pet pet;
    long count;
};


class CatDogQue
{
public:
    CatDogQue();

    void push(Pet pet);

    Pet popAll();

    Dog popDog();

    Cat popCat();

    bool isEmpty();

    bool isDogEmpty();

    bool isCatEmpty();

private:
    std::queue<PetStamp> dogQ;
    std::queue<PetStamp> catQ;
    long count;
};
#endif //UNTITLED1_DOGANDCAT_H

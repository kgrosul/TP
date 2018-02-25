#ifndef PIZZA_OTHERFOOD_H
#define PIZZA_OTHERFOOD_H

#include "iostream"
#include "vector"
class ISalad{
    int price;
public:
    virtual void make() = 0;
    virtual ~ISalad(){};

};

class IDrink{
    int price;
public:
    virtual void make() = 0;
    virtual ~IDrink(){};

};

class ISandwich{
    int price;
public:
    virtual void make() = 0;
    virtual ~ISandwich(){};

};

class CMskSalad: public  ISalad{
    int price = 200;
public:
    void make();
};


class CSpbSalad: public  ISalad{
    int price = 150;
public:
    void make();

};

class CMskDrink: public IDrink{
    int price = 100;
public:
    void make();

};

class CSpbDrink: public IDrink{
    int price = 500;
public:
    void make();

};

class CMskSandwich: public ISandwich{
    int price = 250;
public:
    void make();

};

class CSpbSandwich: public ISandwich{
    int price = 175;
public:
    void make();

};

class IAddFoodFactory{
public:
    virtual IDrink* createDrink() = 0;
    virtual ISalad* createSalad() = 0;
    virtual ISandwich* createSandwich() = 0;
    virtual ~IAddFoodFactory(){}
};

class CMskAddFoodFactory: public IAddFoodFactory{
    IDrink* createDrink();
    ISalad* createSalad();
    ISandwich* createSandwich();

};

class CSpbAddFoodFactory: public IAddFoodFactory{
    IDrink* createDrink();
    ISalad* createSalad();
    ISandwich* createSandwich();

};


#endif //PIZZA_OTHERFOOD_H

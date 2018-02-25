
#ifndef PIZZA_PIZZA_H
#define PIZZA_PIZZA_H


#include <iostream>
#include <string>
#include <vector>
#include <memory>

class  CPizza{
    std::string dough;
    std::vector<std::string> ingredients;
    std::vector<std::string> sauces;
    int price;

public:
    void setDough(const std::string& d);
    void setSauces(const std::vector<std::string> &s);
    void setIngredients(const std::vector<std::string> &i);
    void cook(int time);
    void setPrice(int money);
    void show();

};

class IPizzaBuilder {
protected:
    std::shared_ptr<CPizza> pizza;
public:
    virtual ~IPizzaBuilder() {}
    std::shared_ptr<CPizza> getPizza();
    void createPizza();
    virtual void chooseDough() = 0;
    virtual void addSauces() = 0;
    virtual void addIngredients() = 0;
    virtual void cook() = 0;
    virtual void setPrice() = 0;

};

class CMargaritaPizzaBuilder: public  IPizzaBuilder{
public:
    CMargaritaPizzaBuilder(): IPizzaBuilder(){}
    ~CMargaritaPizzaBuilder() {}
    void chooseDough();
    void addIngredients();
    void addSauces();
    void cook();
    void setPrice();
};


class C4CheesesPizzaBuilder: public  IPizzaBuilder{
public:
    C4CheesesPizzaBuilder(): IPizzaBuilder(){}
    ~C4CheesesPizzaBuilder() {}
    void chooseDough();
    void addIngredients();
    void addSauces();
    void cook();
    void setPrice();

};


class CHawaiianPizzaBuilder: public  IPizzaBuilder{
public:
    CHawaiianPizzaBuilder(): IPizzaBuilder(){}
    ~CHawaiianPizzaBuilder() {}
    void chooseDough();
    void addIngredients();
    void addSauces();
    void cook();
    void setPrice();

};

class CCustomPizzaBuilder: public  IPizzaBuilder{
public:
    CCustomPizzaBuilder(): IPizzaBuilder(){}
    ~CCustomPizzaBuilder() {}
    void chooseDough();
    void addIngredients();
    void addSauces();
    void cook();
    void setPrice();

};


class CChef{
    IPizzaBuilder* pizzaBuilder;
public:
    CChef();
    ~CChef(){};
    void setPizzaBuilder(IPizzaBuilder* builder);
    std::shared_ptr<CPizza> getPizza();
    void createPizza();

};

#endif //PIZZA_PIZZA_H

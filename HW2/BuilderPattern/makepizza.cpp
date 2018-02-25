#include "makepizza.h"

std::shared_ptr<CPizza> makeHawaiianPizza(){
    CChef chef;
    СHawaiianPizzaBuilder builder;
    chef.setPizzaBuilder(&builder);
    chef.createPizza();
    auto pizza = chef.getPizza();
    return pizza;
}

std::shared_ptr<CPizza> make4СheesesPizza(){
    CChef chef;
    С4СheesesPizzaBuilder builder;
    chef.setPizzaBuilder(&builder);
    chef.createPizza();
    auto pizza = chef.getPizza();
    return pizza;
}

std::shared_ptr<CPizza> makeMargaritaPizza(){
    CChef chef;
    СMargaritaPizzaBuilder builder;
    chef.setPizzaBuilder(&builder);
    chef.createPizza();
    auto pizza = chef.getPizza();
    return pizza;
}

std::shared_ptr<CPizza> makeCustomPizza(){
    CChef chef;
    СCustomPizzaBuilder builder;
    chef.setPizzaBuilder(&builder);
    chef.createPizza();
    auto pizza = chef.getPizza();
    return pizza;
}
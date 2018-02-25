#include "makepizza.h"

std::shared_ptr<CPizza> makeHawaiianPizza(){
    CChef chef;
    CHawaiianPizzaBuilder builder;
    chef.setPizzaBuilder(&builder);
    chef.createPizza();
    auto pizza = chef.getPizza();
    return pizza;
}

std::shared_ptr<CPizza> make4CheesesPizza(){
    CChef chef;
    C4CheesesPizzaBuilder builder;
    chef.setPizzaBuilder(&builder);
    chef.createPizza();
    auto pizza = chef.getPizza();
    return pizza;
}

std::shared_ptr<CPizza> makeMargaritaPizza(){
    CChef chef;
    CMargaritaPizzaBuilder builder;
    chef.setPizzaBuilder(&builder);
    chef.createPizza();
    auto pizza = chef.getPizza();
    return pizza;
}

std::shared_ptr<CPizza> makeCustomPizza(){
    CChef chef;
    CCustomPizzaBuilder builder;
    chef.setPizzaBuilder(&builder);
    chef.createPizza();
    auto pizza = chef.getPizza();
    return pizza;
}

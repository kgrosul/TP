#ifndef PIZZA_RUN_H
#define PIZZA_RUN_H
#include "otherfood.h"
#include "pizza.h"
#include "makepizza.h"



struct order{
    std::string city;
    std::vector<std::string> pizzas;
    int drinks;
    int salads;
    int sandwiches;
};

order gerOrder();

void createBox();

void pack(std::shared_ptr<CPizza>);

void pack(...);

void deliver();

void prepareOrder(order _order);

bool neworders();

void run();
#endif //PIZZA_RUN_H

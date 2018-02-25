#include "run.h"

order gerOrder(){
    order newOrder;
    std::cin >> newOrder.city;
    int numberOfPizzas;
    std::cin >> numberOfPizzas;
    newOrder.pizzas.resize(numberOfPizzas);
    for(int i = 0; i < numberOfPizzas; ++i)
        std::cin >> newOrder.pizzas[i];
    std::cin >> newOrder.drinks;
    std::cin >> newOrder.salads;
    std::cin >> newOrder.sandwiches;
    return newOrder;
}

void createBox(){
    std::cout << "create new box" << std::endl;
}

void pack(std::shared_ptr<CPizza>){
    std::cout << "put pizza in a box" << std::endl;

}
void pack(...){
    std::cout << "put food in a box" << std::endl;
}

void deliver(){
    std::cout << "deliver box to the customer" << std::endl;
}

void prepareOrder(order _order){
    createBox();
    IAddFoodFactory* addFoodFactory = nullptr;
    if(_order.city == "Msk"){
        addFoodFactory = new CMskAddFoodFactory;
    } else {
        addFoodFactory = new CSpbAddFoodFactory;
    }
    std::shared_ptr<CPizza> pizza;
    for(auto pizzaName:_order.pizzas){
        if(pizzaName == "Hawaiian"){
            pizza = makeHawaiianPizza();
        }
        if(pizzaName == "4Cheeses"){
            pizza = make4CheesesPizza();
        }
        if(pizzaName == "Margarita"){
            pizza = makeMargaritaPizza();
        }
        else{
            pizza = makeCustomPizza();
        }

        pack(pizza);
    }
    for(int i = 0; i < _order.drinks; ++i){
        auto drink = addFoodFactory->createDrink();
        drink->make();
        pack(drink);
        delete drink;
    }

    for(int i = 0; i < _order.salads; ++i){
        auto salad = addFoodFactory->createSalad();
        salad->make();
        pack(salad);
        delete salad;
    }

    for(int i = 0; i < _order.sandwiches; ++i){
        auto sandwich = addFoodFactory->createSandwich();
        sandwich->make();
        pack(sandwich);
        delete sandwich;
    }

    deliver();
}


bool neworders(){
    std::cout << "check if there are any new orders " << std::endl;
    return true;

}

void run() {
    while (neworders()) {
        prepareOrder(gerOrder());
    }

}

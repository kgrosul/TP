#include "run.h"

order gerOrder(){
    order newOrder;
    std::cout << "choose city: Msk or Sbp" << std::endl;
    std::cin >> newOrder.city;
    int numberOfPizzas;
    std::cout << "write number or pizzas" << std::endl;
    std::cin >> numberOfPizzas;
    newOrder.pizzas.resize(numberOfPizzas);
    std::cout << "choose pizzas: Hawaiian, Margarita, 4Cheeses or Custom" << std::endl;
    for(int i = 0; i < numberOfPizzas; ++i)
        std::cin >> newOrder.pizzas[i];
    std::cout << "write number or drinks" << std::endl;
    std::cin >> newOrder.drinks;
    std::cout << "write number or salads" << std::endl;
    std::cin >> newOrder.salads;
    std::cout << "write number or sandwiches" << std::endl;
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
    IAddFoodFactory* addFoodFactory = nullptr;
    if(_order.city == "Msk"){
        addFoodFactory = new CMskAddFoodFactory;
    } else if(_order.city == "Spb") {
        addFoodFactory = new CSpbAddFoodFactory;
    } else {
        std::cout << "sorry we have no delivery to your city" << std::endl;
        return;
    }
    createBox();
    std::shared_ptr<CPizza> pizza;
    for(auto pizzaName:_order.pizzas){
        if(pizzaName == "Hawaiian"){
            pizza = makeHawaiianPizza();
        }
        else if(pizzaName == "4Cheeses"){
            pizza = make4CheesesPizza();
        }
        else if(pizzaName == "Margarita"){
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

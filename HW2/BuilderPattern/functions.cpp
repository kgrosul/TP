#include "functions.h"

bool orders(){
    std::cout << "Are there any orders?" << std::endl;
    return true;
}

void deliverOreder(){
    std::cout << "delivering order" << std::endl;

}

std::string getOrder(){
    std::string order;
    std::cin >> order;
    return order;
}

void makeOrder(){
    std::string order = getOrder();
    if(order == "Margarita")
        makeMargaritaPizza();
    else if(order == "Hawaiian")
        makeHawaiianPizza();
    else if(order == "4Cheeses")
        make4СheesesPizza();
    else std::cout << "Sorry, we haven't this pizza:(" << std::endl;
    deliverOreder();

}

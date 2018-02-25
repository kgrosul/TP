#include "pizza.h"

void CPizza::setDough(const std::string& d){ dough = d; }
void CPizza::setSauces(const std::vector<std::string> &s){ sauces = s; }
void CPizza::setIngredients(const std::vector<std::string> &i){ ingredients = i; }
void CPizza::cook(int time){ std::cout << "сook " <<
                               time << " seconds." << std::endl; }
void CPizza::setPrice(int money){ price = money; }
void CPizza::show(){
    std::cout << "Dough: " << dough << "\n"
              << "Ingredients: ";
    for(auto ing : ingredients)
        std::cout << ing << " ";
    std::cout << "\n" << "Sauces: ";
    for(auto s : sauces)
        std::cout << s << " ";
    std::cout << "\n" << "Price: " << price << std::endl;
};



std::shared_ptr<CPizza> IPizzaBuilder::getPizza() { return pizza; }
void IPizzaBuilder::createPizza() { pizza.reset(new CPizza); }


void СMargaritaPizzaBuilder::chooseDough(){ pizza->setDough("Thin");}
void СMargaritaPizzaBuilder::addIngredients(){ pizza->setIngredients({"Mozzarella",
                                              "Tomatoes",
                                              "Basil",
                                              "Olive oil"});}
void СMargaritaPizzaBuilder::addSauces(){ pizza->setSauces({"tomato sauce"}); }
void СMargaritaPizzaBuilder::cook(){ pizza->cook(360); }
void СMargaritaPizzaBuilder::setPrice(){ pizza->setPrice(499); }


void С4СheesesPizzaBuilder::chooseDough(){ pizza->setDough("Medium");}
void С4СheesesPizzaBuilder::addIngredients(){ pizza->setIngredients({"Mozzarella",
                                              "Emmental",
                                              "Gorgonzola",
                                              "Parmesan",
                                              "Olive oil",
                                              "Oregano"});}
void С4СheesesPizzaBuilder::addSauces(){}
void С4СheesesPizzaBuilder::cook(){ pizza->cook(600); }
void С4СheesesPizzaBuilder::setPrice(){ pizza->setPrice(549); }


void СHawaiianPizzaBuilder::chooseDough(){ pizza->setDough("Thick");}
void СHawaiianPizzaBuilder::addIngredients(){ pizza->setIngredients({"Pineapples",
                                              "Chicken",
                                              "Cheese",
                                              "Ham"});}
void СHawaiianPizzaBuilder::addSauces(){pizza->setSauces({"Ketchup"}); }
void СHawaiianPizzaBuilder::cook(){ pizza->cook(800); }
void СHawaiianPizzaBuilder::setPrice(){ pizza->setPrice(399); }


void СCustomPizzaBuilder::chooseDough(){
    std::cout << "choose dough for custom pizza:\n thick, medium or thin";
    std::string dough;
    std::cin >> dough;
    pizza->setDough(dough);
}
void СCustomPizzaBuilder::addIngredients() {
    std::cout << "choose ingredients for custom pizza:\n Chicken, Ham, Tomatoes, Cheese, Pineapples, Basil\n"<<
            "Mozzarella, Emmental, Gorgonzola, Oregano, Olive oil, Onion, Wine, Mushrooms, Pumpkin" << std::endl;
    std::cout << "write number of ingredients" << std::endl;
    int number;
    std::cin >> number;
    std::cout << "write ingredients" << std::endl;
    std::vector<std::string> ingredients;
    for(int i = 0; i < number; ++i){
        std::string ing;
        std::cin >> ing;
        ingredients.push_back(ing);
    }
    pizza->setIngredients(ingredients);
}
void СCustomPizzaBuilder::addSauces() {
    std::cout << "choose sauces for custom pizza: Barbecue, Cheese, Sweet & Spicy, Ketchup,  Hot, Mayonnaise" <<
              std::endl;
    std::cout << "write number of sauces" << std::endl;
    int number;
    std::cin >> number;
    std::cout << "write sauces" << std::endl;
    std::vector<std::string> sauces;
    for (int i = 0; i < number; ++i) {
        std::string sc;
        std::cin >> sc;
        sauces.push_back(sc);
    }
    pizza->setSauces(sauces);
}
void СCustomPizzaBuilder::cook(){ pizza->cook(600); }
void СCustomPizzaBuilder::setPrice(){ pizza->setPrice(999); }


CChef::CChef(): pizzaBuilder(nullptr){}
void CChef::setPizzaBuilder(IPizzaBuilder* builder){ pizzaBuilder = builder; }
std::shared_ptr<CPizza> CChef::getPizza() { return pizzaBuilder->getPizza(); }
void CChef::createPizza() {
    pizzaBuilder->createPizza();
    pizzaBuilder->chooseDough();
    pizzaBuilder->addIngredients();
    pizzaBuilder->addSauces();
    pizzaBuilder->cook();
    pizzaBuilder->setPrice();
}


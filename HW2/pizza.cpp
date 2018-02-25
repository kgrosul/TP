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


void CMargaritaPizzaBuilder::chooseDough(){ pizza->setDough("Thin");}
void CMargaritaPizzaBuilder::addIngredients(){ pizza->setIngredients({"Mozzarella",
                                                                      "Tomatoes",
                                                                      "Basil",
                                                                      "Olive oil"});}
void CMargaritaPizzaBuilder::addSauces(){ pizza->setSauces({"tomato sauce"}); }
void CMargaritaPizzaBuilder::cook(){ pizza->cook(360); }
void CMargaritaPizzaBuilder::setPrice(){ pizza->setPrice(499); }


void C4CheesesPizzaBuilder::chooseDough(){ pizza->setDough("Medium");}
void C4CheesesPizzaBuilder::addIngredients(){ pizza->setIngredients({"Mozzarella",
                                                                     "Emmental",
                                                                     "Gorgonzola",
                                                                     "Parmesan",
                                                                     "Olive oil",
                                                                     "Oregano"});}
void C4CheesesPizzaBuilder::addSauces(){}
void C4CheesesPizzaBuilder::cook(){ pizza->cook(600); }
void C4CheesesPizzaBuilder::setPrice(){ pizza->setPrice(549); }


void CHawaiianPizzaBuilder::chooseDough(){ pizza->setDough("Thick");}
void CHawaiianPizzaBuilder::addIngredients(){ pizza->setIngredients({"Pineapples",
                                                                     "Chicken",
                                                                     "Cheese",
                                                                     "Ham"});}
void CHawaiianPizzaBuilder::addSauces(){pizza->setSauces({"Ketchup"}); }
void CHawaiianPizzaBuilder::cook(){ pizza->cook(800); }
void CHawaiianPizzaBuilder::setPrice(){ pizza->setPrice(399); }


void CCustomPizzaBuilder::chooseDough(){
    std::cout << "choose dough for custom pizza:\n thick, medium or thin";
    std::string dough;
    std::cin >> dough;
    pizza->setDough(dough);
}
void CCustomPizzaBuilder::addIngredients() {
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
void CCustomPizzaBuilder::addSauces() {
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
void CCustomPizzaBuilder::cook(){ pizza->cook(600); }
void CCustomPizzaBuilder::setPrice(){ pizza->setPrice(999); }


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


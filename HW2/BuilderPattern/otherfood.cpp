
#include "otherfood.h"

void CMskSalad::make(){ std::cout << "make Cesar salad" << std::endl; }


void CSpbSalad::make(){ std::cout << "make Brooklyn salad" << std::endl; }



void CMskDrink::make(){ std::cout  << "make coffee" << std::endl; }



void CSpbDrink:: make(){ std::cout  << "make tea" << std::endl; }


void CMskSandwich::make(){ std::cout << "make Cheeseburger" << std::endl; }


void CSpbSandwich::make(){ std::cout << "make Fishburger" << std::endl; }



IDrink* CMskAddFoodFactory::createDrink(){ return new CMskDrink; }
ISalad* CMskAddFoodFactory::createSalad(){ return new CMskSalad; }
ISandwich* CMskAddFoodFactory::createSandwich(){ return new CMskSandwich; }


IDrink* CSpbAddFoodFactory::createDrink(){ return new CSpbDrink; }
ISalad* CSpbAddFoodFactory::createSalad(){ return new CSpbSalad; }
ISandwich* CSpbAddFoodFactory::createSandwich(){ return new CSpbSandwich; }
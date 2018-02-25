#include "gtest/gtest.h"
#include "memory"
#include "pizza.h"
#include "makepizza.h"
#include "run.h"



TEST(makeMargaritaTest, MargaritaDoughTest) {
    auto pizza = makeMargaritaPizza();
    ASSERT_EQ("Thin", pizza->showDough());
}

TEST(makeMargaritaTest, MargaritaPriceTest) {
    auto pizza = makeMargaritaPizza();
    ASSERT_EQ(499, pizza->showPrice());

}

TEST(makeMargaritaTest, MargaritaIngredientsTest) {
    auto pizza = makeMargaritaPizza();
    std::vector<std::string> ingredients = {"Mozzarella",
                                            "Tomatoes",
                                            "Basil",
                                            "Olive oil"};
    ASSERT_EQ(ingredients, pizza->showIngredients());
}
TEST(makeMargaritaTest, MargaritaSaucesTest) {
    auto pizza = makeMargaritaPizza();
    std::vector<std::string> sauces = {"Tomato sauce"};
    ASSERT_EQ(sauces, pizza->showSauces());
}

TEST(makeHawaiianTest, HawaiianDoughTest) {
    auto pizza = makeHawaiianPizza();
    ASSERT_EQ("Thick", pizza->showDough());
}

TEST(makeHawaiianTest, HawaiianPriceTest) {
    auto pizza = makeHawaiianPizza();
    ASSERT_EQ(399, pizza->showPrice());
}

TEST(makeHawaiianTest, HawaiianIngredientsTest) {
    auto pizza = makeHawaiianPizza();
    std::vector<std::string> ingredients = {"Pineapples",
                                            "Chicken",
                                            "Cheese",
                                            "Ham"};
    ASSERT_EQ(ingredients, pizza->showIngredients());
}
TEST(makeHawaiianTest, HawaiianSaucesTest) {
    auto pizza = makeHawaiianPizza();
    std::vector<std::string> sauces = {"Ketchup"};
    ASSERT_EQ(sauces, pizza->showSauces());
}

TEST(make4CheesesTest, fCheesesDoughTest) {
    auto pizza = make4CheesesPizza();
    ASSERT_EQ("Medium", pizza->showDough());
}

TEST(make4CheesesTest, fCheesesPriceTest) {
    auto pizza = make4CheesesPizza();
    ASSERT_EQ(549, pizza->showPrice());
}

TEST(make4CheesesTest, fCheesesIngredientsTest) {
    auto pizza = make4CheesesPizza();
    std::vector<std::string> ingredients = {"Mozzarella",
                                            "Emmental",
                                            "Gorgonzola",
                                            "Parmesan",
                                            "Olive oil",
                                            "Oregano"};

    ASSERT_EQ(ingredients, pizza->showIngredients());
}

TEST(make4CheesesTest, fCheesesSaucesTest){
auto pizza = make4CheesesPizza();
std::vector<std::string> sauces = {};
ASSERT_EQ(sauces, pizza->showSauces());
}

TEST(OrderingTest, newOrdersTest){
    ASSERT_TRUE(neworders());

}

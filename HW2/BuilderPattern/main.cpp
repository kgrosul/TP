#include "pizza.h"
#include "makepizza.h"
#include "functions.h"


int main() {
    while (orders()){
        makeOrder();
    }

    return 0;
}

#include <iostream>
#include "FavColor.h"


int main(){
    /* std::cout << "Whats your fav color?"<< FavColor('r'); */
    std::cout << "Whats your fav color?\n";
    char colorinput;
    std::cin >> colorinput;
    std::cout << "this is your fav color:\n" << FavColor(colorinput);
}

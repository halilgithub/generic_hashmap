#include <iostream>
#include "HashMap.h"
#include <typeinfo>


int main(){


    HashMap<std::string,int> hmap;

    if (hmap.isEmpty())
        std::cout << "Hasmap is empty !" << std::endl;
    else
        std::cout << "Hashmap is not empty" << std::endl;

    bool success = hmap.insert("halil",12);
    std::cout << success << std::endl;
    //hmap.printHashMap();

    return 0;
}

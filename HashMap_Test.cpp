#include <iostream>
#include "HashMap.h"


int main(){


    HashMap<std::string,int> hmap;

    if (hmap.isEmpty())
        std::cout << "Hasmap is empty !" << std::endl;
    else
        std::cout << "Hashmap is not empty" << std::endl;

    bool success = hmap.insert("halil",12);
    success = hmap.insert("hali",13);
    success = hmap.insert("hall",14);
    success = hmap.insert("hail",15);
    success = hmap.insert("hail",16);
    std::cout << success << std::endl;
    hmap.printHashMap();

    return 0;
}

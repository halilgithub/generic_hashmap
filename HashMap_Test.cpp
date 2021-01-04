#include <iostream>
#include "HashMap.h"


int main(){


    HashMap<std::string,int> hmap;

    if (hmap.isEmpty())
        std::cout << "Hasmap is empty !" << std::endl;
    else
        std::cout << "Hashmap is not empty" << std::endl;

    bool success = hmap.insert("halil",12);
    success = hmap.insert("audrey",13);
    success = hmap.insert("ester",14);
    success = hmap.insert("halil",18);
    success = hmap.insert("sebastian",16);


    hmap.printHashMap();

    return 0;
}

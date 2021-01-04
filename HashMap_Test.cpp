#include <iostream>
#include "HashMap.h"


int main(){


    HashMap<std::string,int> hmap;

    if (hmap.isEmpty())
        std::cout << "Hasmap is empty !" << std::endl;
    else
        std::cout << "Hashmap is not empty" << std::endl;

    std::cout << std::endl;

    bool success = hmap.insert("melanie",12);
    success = hmap.insert("melanie",18);
    success = hmap.insert("audrey",13);
    success = hmap.insert("ester",14);
    success = hmap.insert("isabella",22);
    success = hmap.insert("helena",56);
    success = hmap.insert("marta",11);
    success = hmap.insert("beatrice",88);
    success = hmap.insert("magdalena",99);
    success = hmap.insert("katja",44);
    success = hmap.insert("laura",33);
    success = hmap.deleteElement("audrey");

    auto key = "ester";
    auto value = hmap.search(key);
    if(value.has_value())
        std::cout << "[INFO] The element exists: (" << key << ", " << value.value() << ")" << std::endl;
    else
        std::cout << "[INFO] An element with key:" << key << " doesn't exist !" << std::endl;

    key = "marie";
    value = hmap.search(key);
    if(value.has_value())
        std::cout << "[INFO] The element exists: (" << key << ", " << value.value() << ")" << std::endl;
    else
        std::cout << "[INFO] An element with key:" << key << " doesn't exist !" << std::endl;

    std::cout << std::endl;

    hmap.printHashMap();

    return 0;
}

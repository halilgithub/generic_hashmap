#include <iostream>
#include "HashMap.h"


int main(){


    HashMap<std::string,int> hmap;

    if (hmap.isEmpty())
        std::cout << "Hashmap is empty !" << std::endl;
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

    HashMap<int,int> hmap2;

     if (hmap2.isEmpty())
        std::cout << "Hashmap is empty !" << std::endl;
    else
        std::cout << "Hashmap is not empty" << std::endl;

    std::cout << std::endl;

    bool success2 = hmap2.insert(12, 1201);
    success2 = hmap2.insert(18, 1805);
    success2 = hmap2.insert(13, 1307);
    success2 = hmap2.insert(14, 1402);
    success2 = hmap2.insert(22, 2209);


    auto key2 = 13;
    auto value2 = hmap2.search(key2);
    if(value2.has_value())
        std::cout << "[INFO] The element exists: (" << key2 << ", " << value2.value() << ")" << std::endl;
    else
        std::cout << "[INFO] An element with key:" << key2 << " doesn't exist !" << std::endl;

    key2 = 30;
    value2 = hmap2.search(key2);
    if(value2.has_value())
        std::cout << "[INFO] The element exists: (" << key2 << ", " << value2.value() << ")" << std::endl;
    else
        std::cout << "[INFO] An element with key:" << key2 << " doesn't exist !" << std::endl;

    std::cout << std::endl;

    hmap2.printHashMap();

    return 0;
}

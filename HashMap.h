#pragma once

#include <string>
#include <list>
#include <vector>
#include <optional>
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <sstream>


template <typename key_type, typename value_type>
class HashMap
{

public:
    using size_type = std::size_t;
    using optional_type = std::optional<value_type>;
    using pair_type = std::pair<key_type,value_type>;
    using list_type = std::list<pair_type>;

    HashMap() = default;
    ~HashMap() = default;

    bool isEmpty() const;
    size_type hashFunction(key_type key);
    optional_type search(key_type key);
    bool insert(key_type key, value_type value);
    bool deleteElement(key_type key);
    void printHashMap();

private:
    size_type mSize = 0;
    std::vector<list_type> mBuckets;
};


template <typename key_type, typename value_type>
bool HashMap<key_type, value_type>::isEmpty() const
{
    return (mSize == 0);
}

template <typename key_type, typename value_type>
typename HashMap<key_type, value_type>::size_type HashMap<key_type, value_type>::hashFunction(key_type key)
{
    std::string str_key = static_cast<std::ostringstream*>(&(std::ostringstream() << key))->str();
    size_type hash_output = std::hash<std::string>()(str_key);
    std::cout << "[SUCCESS] The key is hashed: " << hash_output << std::endl;
    return hash_output;
}

template <typename key_type, typename value_type>
typename HashMap<key_type, value_type>::optional_type HashMap<key_type, value_type>::search(key_type key)
{
    size_type hash_output = hashFunction(key);
    try{
        std::cout << "111" << std::endl;
        auto & bucket = mBuckets[hash_output];
        std::cout << "222" << std::endl;
        typename HashMap<key_type, value_type>::list_type::iterator it;
        for (it = begin(bucket); it != end(bucket); ++it)
        {
            std::cout << "333" << std::endl;
            if (it->first == key){
                std::cout << "[INFO] The element exists: (" << it->first << ", " << it->second << ")" << std::endl;
                return it->second;
            }
        }

        std::cout << "[INFO] The element with key=" << key << "doesn't exist !" << std::endl;
        return std::nullopt;
    }catch(std::exception &ex){
        std::cout << ex.what() << std::endl;
        return std::nullopt;
    }
}

template <typename key_type, typename value_type>
bool HashMap<key_type, value_type>::insert(key_type key, value_type value)
{
    auto mapped_value = search(key);

    if (mapped_value.has_value()){
        std::cout << "[ERROR] The element couldn't be inserted, key already exists !" << std::endl;
        return false;  //  insert operation is unsuccessfull
    }
    else
    {
        try{
            size_type hash_output = hashFunction(key);
            mBuckets[hash_output].emplace_back(key,value);
            std::cout << "[SUCCESS] The element has been inserted !" << std::endl;
            ++mSize;
            return true;  // insert operation is successfull
        }catch (std::exception &ex){
            std::cout << ex.what() << std::endl;
            return false;
        }
    }
}

template <typename key_type, typename value_type>
bool HashMap<key_type, value_type>::deleteElement(key_type key)
{

    size_type hash_output = hashFunction(key);
    auto & bucket = mBuckets[hash_output];

    for (auto it = begin(bucket); it != end(bucket); ++it)
    {
        if (it->first == key){
            bucket.erase(it);
            std::cout << "[SUCCESS] The element has been deleted !" << std::endl;
            --mSize;
            return true;  // delete operation is successfull
        }
    }

    std::cout << "[ERROR] The element couldn't be deleted, key doesn't exist !" << std::endl;
    return false;  //  delete operation is unsuccessfull

}

template <typename key_type, typename value_type>
void HashMap<key_type, value_type>::printHashMap()
{
    std::cout << "Printing all the elements in the HashMap" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    for(auto it_vector = begin(mBuckets); it_vector != end(mBuckets); ++it_vector)
    {
        size_type bucketIndex = std::distance(begin(mBuckets), it_vector);
        std::cout << "Bucket[" << bucketIndex << "]:" << std::endl;
        for (auto it_list = begin(it_vector); it_list != end(it_vector); ++it_list)
            std::cout << "\t(" << it_list->first << ", " << it_list->second << ")" << std::endl;
        std::cout << std::endl;
    }
}


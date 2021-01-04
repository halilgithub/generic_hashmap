#pragma once

#include <string>
#include <list>
#include <array>
#include <optional>
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <sstream>
#include <utility>


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

    size_type mElementNum = 0;
    static const size_type mBucketNum = 13;
    std::array<list_type, mBucketNum> mBuckets;
};


template <typename key_type, typename value_type>
bool HashMap<key_type, value_type>::isEmpty() const
{
    std::cout <<"Number of buckets (static const declared ): "<< mBuckets.size() << std::endl;
    return (mElementNum == 0);
}

template <typename key_type, typename value_type>
typename HashMap<key_type, value_type>::size_type HashMap<key_type, value_type>::hashFunction(key_type key)
{
    std::string str_key = static_cast<std::ostringstream*>(&(std::ostringstream() << key))->str();
    size_type hash_output = std::hash<std::string>()(str_key);
    return hash_output;
}

template <typename key_type, typename value_type>
typename HashMap<key_type, value_type>::optional_type HashMap<key_type, value_type>::search(key_type key)
{
    size_type bucketIndex = hashFunction(key) % mBucketNum;
    //std::cout << "[SUCCESS] The key is hashed, bucket index is: " << bucketIndex << std::endl;

    if (mBuckets[bucketIndex].size() != 0){

        auto & bucket = mBuckets[bucketIndex];
        typename HashMap<key_type, value_type>::list_type::iterator it;

        for (it = begin(bucket); it != end(bucket); ++it)
        {
            if (it->first == key){
                //std::cout << "[INFO] The element exists: (" << it->first << ", " << it->second << ")" << std::endl;
                return it->second;
            }
        }
    }

    //std::cout << "[INFO] The element with key:" << key << " doesn't exist !" << std::endl;
    return std::nullopt;

}

template <typename key_type, typename value_type>
bool HashMap<key_type, value_type>::insert(key_type key, value_type value)
{
    auto mapped_value = search(key);

    if (mapped_value.has_value()){
        std::cout << "[ERROR] The element (" << key << ", " << value << ") couldn't be inserted, key already exists !" << std::endl;
        return false;  //  insert operation is unsuccessfull
    }
    else
    {
        size_type bucketIndex = hashFunction(key) % mBucketNum;
        std::pair <key_type,value_type> element = std::make_pair(key,value);
        mBuckets[bucketIndex].emplace_back(element);
        std::cout << "[SUCCESS] The element (" << key << ", " << value << ") has been inserted !" << std::endl;
        ++mElementNum;
        return true;  // insert operation is successfull
    }
}

template <typename key_type, typename value_type>
bool HashMap<key_type, value_type>::deleteElement(key_type key)
{

    size_type bucketIndex = hashFunction(key) % mBucketNum;
    //std::cout << "[SUCCESS] The key is hashed, bucket index is: " << bucketIndex << std::endl;

    if (mBuckets[bucketIndex].size() != 0){
        auto & bucket = mBuckets[bucketIndex];
        for (auto it = begin(bucket); it != end(bucket); ++it)
        {
            if (it->first == key){
                bucket.erase(it);
                std::cout << "[SUCCESS] The element (" << key << ", " << it->second << ") has been deleted !" << std::endl;
                --mElementNum;
                return true;  // delete operation is successfull
            }
        }
    }

    std::cout << "[ERROR] The key:" << key << " couldn't be deleted, key doesn't exist !" << std::endl;
    return false;  //  delete operation is unsuccessfull

}

template <typename key_type, typename value_type>
void HashMap<key_type, value_type>::printHashMap()
{
    std::cout << "Printing all the elements in the HashMap" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    for(size_type bucketIndex = 0; bucketIndex < mBucketNum; bucketIndex++)
    {
        //size_type bucketIndex = std::distance(begin(mBuckets), it_array);
        if (mBuckets[bucketIndex].size() != 0){
            std::cout << "Bucket[" << bucketIndex << "]:" << std::endl;
            auto & bucket = mBuckets[bucketIndex];
            for (auto it_list = begin(bucket); it_list != end(bucket); ++it_list)
                std::cout << "\t(" << it_list->first << ", " << it_list->second << ")" << std::endl;
            std::cout << std::endl;
        }
    }
    std::cout << "Total number of elements in hash map: " << mElementNum << std::endl;
    std::cout << std::endl;
}


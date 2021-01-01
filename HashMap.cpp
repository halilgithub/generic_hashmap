#include <iostream>
#include "HashMap.h"

template <typename key_type, typename value_type>
bool HashMap<key_type, value_type>::isEmpty() const
{
    return (mSize == 0);
}

template <typename key_type, typename value_type>
size_type HashMap<key_type, value_type>::hashFunction(key_type key)
{
    size_type hash_output = std::hash<key_type>()(key);
    cout << "[SUCCESS] The key is hashed: " << key_hash << endl;
    return hash_output;
}

template <typename key_type, typename value_type>
optional_type HashMap<key_type, value_type>::search(key_type key)
{
    size_type hash_output = hashFunction(key);
    auto & bucket = mBuckets[hash_output];

    for (auto it = begin(bucket); it < end(bucket); ++it)
    {
        if (it->first == key){
            cout << "[INFO] The pair exists: (" << key << ', ' << pair->second << ')' << endl;
            return pair->second;
        }
    }

    return std::nullopt;
}

template <typename key_type, typename value_type>
bool HashMap<key_type, value_type>::insert(key_type key, value_type value)
{
    auto mapped_value = search(key);

    if (mapped_value.has_value()){
        cout << "[ERROR] The pair couldn't be inserted, key already exists !" << endl;
        return false;  //  insert operation is unsuccessfull
    }
    else
    {
        size_type hash_output = hashFunction(key);
        mBuckets[hash_output].emplace_back(key,value);
        cout << "[SUCCESS] The pair has been inserted !" << endl;
        ++mSize;
        return true;  // insert operation is successfull
    }
}

template <typename key_type, typename value_type>
bool HashMap<key_type, value_type>::delete(key_type key)
{

    size_type hash_output = hashFunction(key);
    auto & bucket = mBuckets[hash_output];

    for (auto it = begin(bucket); it < end(bucket); ++it)
    {
        if (it->first == key){
            bucket.erase(it);
            cout << "[SUCCESS] The pair has been deleted !" << endl;
            --mSize;
            return true;  // delete operation is successfull
        }
    }

    if (it == end(bucket)){
        cout << "[ERROR] The pair couldn't be deleted, key doesn't exist !" << endl;
        return false;  //  delete operation is unsuccessfull
    }

}

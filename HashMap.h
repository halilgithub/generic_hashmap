#pragma once

#include <string>
#include <list>
#include <vector>

template <typename key_type, typename value_type>
class HashMap
{

public:
    using size_type = std::size_t;
    using optional_type = std::optional<value_type>;
    using pair_type = std::pair<key_type,value_type>
    using list_type = std::list<pair_type>

    HashMap() = default;
    ~HashMap() = default;

    bool isEmpty() const;
    size_type hashFunction(key_type key);
    optional_type search(key_type key);
    bool insert(key_type key, value_type value);
    bool delete(key_type key);
    void printHashMap();

private:
    size_type mSize = 0;
    std::vector<list_type> mBuckets;
};

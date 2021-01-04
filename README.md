# generic_hashmap
a generic Hash Map application using C++ standart library containers and algorithms.

## introduction and status
This hash table is an implementation of separate chaining method. I wrote it as a template class thus it allows (key, value) pairs of variant types. In order to make it fully qualify as a Standard Library container, some other methods and type aliases must be provided. (iterator classes, Move assignment operator, copy constructor etc.) These methods and type aliases are lacking in the project.

## features
For interfaces are provided:
- insert
- delete
- search
- print all the elements in hash map.

## usage
Number of Buckets is declared as static const and can be editted for smaller or bigger bucket numbers. Buckets are hold in std::array because the number of buckets is already known at compile time.

## copyright and license
This project is under the MIT License.

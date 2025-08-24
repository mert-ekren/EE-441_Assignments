#include <iostream>
#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#define SORTEDLIST_MAX_SIZE 20

class SortedList {
private:
    float elements[SORTEDLIST_MAX_SIZE]; // an array of floatss the size as  max_size
    size_t size; // size of the list

public:
    // Constructors
    SortedList(); //Default constructor with size of 0

    // Member functions

    void copy(const SortedList& other); //copy is used to create identical object, array in this case

    float index(size_t ind);// it will return you the float on the indexed position on the array

    size_t insert(float number);// insert a new float to the sorted list at the correct position

    float remove(size_t index);// remove the float indexed at that location

    size_t find(float number);// to find the index of the float searched

    void print() const;// prints the sorted array will print 
};
#endif

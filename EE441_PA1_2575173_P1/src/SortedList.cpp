#include "SortedList.h"
#include <iostream>
#include <stdexcept>

// Constructor

SortedList::SortedList() : size(0) {} // default constructer will create a list with the size 0

// Member functions

// Copies a given list into the object
void SortedList::copy(const SortedList& other) {
    // we will first check the size of the array to makesure the size is not greater than the maximum 
    // allowable size for an array in this class
    if (other.size > SORTEDLIST_MAX_SIZE) {
        throw std::length_error("List size exceeds maximum size.");
    }
    // we will then copy the size of the first of the first object on to the second object
    size = other.size; 
    //we will then linearly copy the first array onto the second array of the SortedList class
    for (size_t i = 0; i < size; ++i) {
        elements[i] = other.elements[i];
    }
}

// Returns the number at the given index
float SortedList::index(size_t ind) {
    // we will first check the size of the array to make sure such index exist
    // if not we will throw an error
    if (ind >= size) {
        throw std::out_of_range("Index out of range.");
    }
    // if such index exists we will return the float at that index
    return elements[ind];
}

// Inserts a number in sorted order and returns its index
size_t SortedList::insert(float number) {
    // we will first check the size of the array to make sure there is still space to insert another float
    // if not we will throw an error
    if (size >= SORTEDLIST_MAX_SIZE) {
        throw std::length_error("List is full.");
    }
    // if such a spot exist we will then check where there exist a place such that
    // the number is smaller than the ith element in the array
    size_t i;
    for (i = 0; i < size; ++i) {
        if (elements[i] > number) {
            break;
        }
    }
    // we will than update the list accordingly by shifting
    for (size_t j = size; j > i; --j) {
        elements[j] = elements[j - 1];
    }
    // and insert the number at the correct location
    elements[i] = number;
    // update the size of the list
    size++;
    // return the index of the newly inserted number
    return i;
}

// Removes the number at the given index and returns it
float SortedList::remove(size_t index) {
    // we first check such an index exist in our list object and
    // throw an error if no such index exist
    if (index >= size) {
        throw std::out_of_range("Index out of range.");
    }
    // we will than store the float at the given index at float , temp
    float temp = elements[index];
    // we will than update the list accordingly by shifting
    for (size_t i = index; i < size - 1; ++i) {
        elements[i] = elements[i + 1];
    }
    // update the size of the list
    size--;
    // returns the removed float
    return temp;
}

// Finds the index of a given number using binary search
size_t SortedList::find(float number) {
    // we begin by first allocating the smallest and the largest index
    size_t left = 0;
    size_t right = size - 1;
    // we then begin binary search deviding and continue to devide in a while loop 
    // constantly updating the boundries
    while (left <= right) {
        size_t mid = left + (right - left) / 2;
    // when we find the number we return its index
        if (elements[mid] == number) {
            return mid;
        }
        if (elements[mid] < number) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // if we can not find the searched number we will return an error saying the float does not exist 
    // in the sorted list
    throw std::domain_error("Number not found in the list.");
}

// Prints the values in the list
void SortedList::print() const {
    // if size of the sorted list is 0 we will say that the list is empty
    if (size == 0) {
        std::cout << "The list is empty" << std::endl;
    } 
    // if the sorted list is not empty we will then output the sorted list
    else {
        for (size_t i = 0; i < size; ++i) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }
}

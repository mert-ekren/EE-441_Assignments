#include "SortedList.h"
#include <iostream>
#include <stdexcept>

int main() {
    SortedList list1;

    list1.print();

    list1.insert(3.5);    // İnserting numbers
    list1.insert(1.2);
    list1.insert(2.8);
    list1.insert(3.4);
    list1.insert(3.8);
    list1.insert(3.5);
    list1.insert(10.2);
    list1.insert(21.8);
    size_t temp_k=list1.insert(43.4);
    std::cout << "inserted number is at index : " << temp_k << std::endl;   
    list1.insert(30.8);
    list1.insert(39.5);
    list1.insert(12.2);
    list1.insert(72.8);
    list1.insert(63.4);
    list1.insert(33.8);
    list1.insert(35.5);
    list1.insert(18.2);
    list1.insert(24.8);
    list1.insert(13.4);
    list1.insert(13.2);

    try{
        // inserting the 21st element size is 20 so it will cause an error
        list1.insert(10);
    } catch (const std::length_error& e) {
        std::cerr << "the error is : " << e.what() << std::endl;
    }

    list1.print();  // print the sorted list

    std::cout << "Element at index 1: " << list1.index(1) << std::endl;

    try {
        // accessing an outof range index element/indexed number
        std::cout << list1.index(100) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "the error is : " << e.what() << std::endl;
    }
    std::cout << "we will now remove the number at index 1" << std::endl;
    // removing number at index 1
    list1.remove(1);
    
    list1.print();
    std::cout << "we will now try(!) to remove the number at index 30" << std::endl;
    try{
        //removing an out-of-range index
        list1.remove(30);
    } catch (const std::out_of_range& e) {
        std::cerr << "the error is : "<< e.what() << std::endl;
    }
    std::cout << "we search for 3.8" << std::endl;
        // finding 3.8
    std::cout << "Found 3.8 at index: " << list1.find(3.8) << std::endl;

    std::cout << "we search for 5.9" << std::endl;
    try {
        // finding a nonexistent number
        size_t index2 = list1.find(5.9);
        std::cout << "Found 5.9 at index: " << index2 << std::endl;
    } catch (const std::domain_error& e) {
        std::cerr << "the error is : " << e.what() << std::endl;
    }

    // copying list 1 on to list 2
    SortedList list2 = list1;

    std::cout << "List1" << std::endl;
    list1.print();
    std::cout << "List2" << std::endl;
    list2.print();

    return 0;
}

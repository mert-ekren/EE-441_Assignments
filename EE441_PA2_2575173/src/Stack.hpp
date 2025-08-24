#pragma once
#include <iostream>
#include <stdexcept>

// for generic class implementation
template <class T>

class Stack
{
private:
    size_t m_capacity; // Maximum capacity of the stack
    size_t m_size;     // Current number of elements in the stack
    T* m_data;         // Pointer to dynamically allocated array

public:
    // Default constructor with size and caoacity 0 and without a pointer to the array
    Stack() : m_capacity(0), m_size(0), m_data(nullptr) {}

    // Parameterized constructor to create a stakc of a set capacity
    Stack(size_t capacity) : m_capacity(capacity), m_size(0), m_data(nullptr) {
        if (capacity > 0) {
            m_data = new T[capacity];
        }
    }

    // destructor to destroy the stack after the operations are completed
    ~Stack() {
        delete[] m_data;
        m_data = nullptr;
        if(m_data != nullptr){
            throw std::logic_error("Function \"destructor\" is not implemented!");
        }
    }

    // Check if the stack is empty returns 1 if it is and 0 if it is not
    bool is_empty() const {
        return m_size == 0;
        throw std::logic_error("Function \"is_empty\" is not implemented!");
    }

    // Clear the stack 
    void clear() {
        delete[] m_data;
        m_data = nullptr;
        m_capacity = 0;
        m_size = 0;


    }

    // Reserve memory for a new capacity to increase the size of the stack
    void reserve(size_t new_capacity) {
        if (new_capacity <= m_capacity) return;

        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            new_data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;

    }

    // Add an element to the top of the stack this is the push
void push_back(const T& value) {
    if (m_size == m_capacity) {
        reserve(m_capacity == 0 ? 1 : m_capacity * 2); // double the capacity if full
    }
    m_data[m_size] = value;  // Assign the value at the current size

    ++m_size; // Increment the size only after validation
}


    // Remove and return the top element this is the pop
    T pop_back() {
        if (is_empty()) {
            throw std::out_of_range("Stack is empty. Cannot pop.");
        }
        return m_data[--m_size];
    }

    // Friend function to overload << operator 
    friend std::ostream& operator<<(std::ostream& os, const Stack& stack) {
        os << "[ ";
        for (size_t i = 0; i < stack.m_size; ++i) {
            os << stack.m_data[i] << ' ';
        }
        os << ']';
        return os;
    }
};

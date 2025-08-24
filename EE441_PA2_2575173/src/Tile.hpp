#pragma once
#include <iostream>
#include <stdexcept> // For exception handling

class Tile {
public:
    char m_suit;   // Suit of the tile ('B', 'C', 'D')
    int m_number;  // Number on the tile (e.g., 1 to 9)

    // default constructor the default case is of type m_suit as default as B 
    // and m_number parameter as the number on the default tile as 1
    Tile() : m_suit('B'), m_number(1) {
        if (m_suit != 'B' && m_number != 1) {
            throw std::invalid_argument("Invalid suit. Must be 'B', 'C', or 'D'.");
    }
    }

    // parameterized constructor to create tile with given imputs aslong as the inputs are valid B C or D
    // the same goes for the numbers 1 through 9 are valid but otherwise it is not correct
    Tile(char s, int n) {
        if (s != 'B' && s != 'C' && s != 'D') {
            throw std::invalid_argument("Invalid suit. Must be 'B', 'C', or 'D'.");
        }
        if (n < 1 || n > 9) {
            throw std::invalid_argument("Invalid number. Must be between 1 and 9.");
        }
        m_suit = s;
        m_number = n;
    }

    // comparator for checking equality it will check if the numbers and suits are the same
    bool operator==(const Tile& other) const {
        return m_suit == other.m_suit && m_number == other.m_number;
    }

    // Overload less-than operator to check the values of tiles 
    // first the m_suits D is better than C is better than B
    // then we can check the numbers if the suits are equal
    bool operator<(const Tile& other) const {
        if (m_suit != other.m_suit) {
            return m_suit < other.m_suit; // Compare suits first if they are not equal
        }
        return m_number < other.m_number; // Compare numbers if suits are equal
    }

    // Overload greater than for checking for checking
    bool operator>(const Tile& other) const {
        return !(*this <= other); 
    }

    // Overload less than or equal for checking
    bool operator<=(const Tile& other) const {
        return *this < other || *this == other;
    }

    // Overload greater than or equal for checking
    bool operator>=(const Tile& other) const {
        return !(*this < other);
    }

    // Overload not equal for checking if they are not equal
    bool operator!=(const Tile& other) const {
        return !(*this == other);
    }

    // Friend function to overload the operators << 
    friend std::ostream& operator<<(std::ostream& os, const Tile& tile) {
        os << tile.m_suit << tile.m_number;
        return os;
    }
};

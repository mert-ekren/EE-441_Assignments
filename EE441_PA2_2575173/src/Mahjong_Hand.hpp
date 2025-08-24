#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Tile.hpp"

#define MAX_HAND_SIZE 14

class Hand {
private:
    Tile* m_tiles[MAX_HAND_SIZE]; // Array of pointers to Tile objects
    size_t m_handSize;            // Current hand size

    // helper function to insert a tile at a specific position at our hand
    // we first check if the index is within range
    // we then insert a tile at the location specified and shift the hand
    void insert_before(size_t index, Tile* new_tile) {
        if (m_handSize >= MAX_HAND_SIZE) {
            throw std::out_of_range("Hand is full. Cannot insert tile.");
        }
        for (size_t i = m_handSize; i > index; --i) {
            m_tiles[i] = m_tiles[i - 1];
        }
        m_tiles[index] = new_tile;
        ++m_handSize;

    }

    // function to pop a tile pointer at a specific index in the hand
    // we will first check if such an index exist
    // then we will pop the index and shift accordingly
    Tile* pop(size_t index) {
        if (index >= m_handSize) {
            throw std::out_of_range("Invalid index for pop.");
        }
        Tile* removed = m_tiles[index];
        for (size_t i = index; i < m_handSize - 1; ++i) {
            m_tiles[i] = m_tiles[i + 1];
        }
        m_tiles[--m_handSize] = nullptr;
        return removed;
    }

public:
    // Default constructor
    Hand() : m_handSize(0) {
        for (size_t i = 0; i < MAX_HAND_SIZE; ++i) {
            m_tiles[i] = nullptr;
        }
   

    }

    // Destructor to deallocate stuff.
    ~Hand() {
        clear();
    }

    // Clear the hand no more tiles are in our size is 0 and pointer is now nullpointer
    void clear() {
        for (size_t i = 0; i < m_handSize; ++i) {
            delete m_tiles[i];
            m_tiles[i] = nullptr;
        }
        m_handSize = 0;
    }

    // Add a tile to the hand, keeping it sorted if there is space
    // and send an error if there is no new space to add more tiles
    void add_tile(Tile* tile) {
        if (m_handSize >= MAX_HAND_SIZE) {
            throw std::out_of_range("Hand is full. Cannot add more tiles.");
        }

        size_t index = 0;
        while (index < m_handSize && *m_tiles[index] < *tile) {
            ++index;
        }
        insert_before(index, tile);


    }

    // to discard the useless tile 
    // most useless 
    Tile* discard_tile() {
        if (m_handSize == 0) {
            throw std::out_of_range("Hand is empty. Cannot discard.");
        }

        // Step 1: Remove from quadruplets bitwise and the 4 consecutive tiles
        for (size_t i = 0; i < m_handSize - 3; ++i) {
            if (*m_tiles[i] == *m_tiles[i + 1] &&
                *m_tiles[i] == *m_tiles[i + 2] &&
                *m_tiles[i] == *m_tiles[i + 3]) {
                return pop(i);
            }
        }

        // Step 2: Remove single tiles remove the odd one out
        for (size_t i = 0; i < m_handSize; ++i) {
            // we will first find if the tile has a duplicate and call him out :( jk i love every tile equally
            bool hasDuplicate = (i > 0 && *m_tiles[i] == *m_tiles[i - 1]) ||
                                (i < m_handSize - 1 && *m_tiles[i] == *m_tiles[i + 1]);
            if (!hasDuplicate) {
                return pop(i);
            }
        }

        // Step 3: Remove from pairs from doubles but not the triplets i shall not miss that one
        for (size_t i = 1; i < m_handSize - 1; ++i) {
            if ((*m_tiles[i] == *m_tiles[i + 1]) and (*m_tiles[i] != *m_tiles[i - 1])) {
                return pop(i);
            }
        }
        for (size_t i = 1; i < m_handSize - 2; ++i) {
            if ((*m_tiles[i] == *m_tiles[i - 1]) and (*m_tiles[i] != *m_tiles[i + 1])) {
                return pop(i);
            }
        }

        // If no tiles can be removed this should not happen it is part of the theory, remove the last one but we wont get here hopefully
        return pop(m_handSize - 1);

    }

    // to win i need 4 triplets and 1 pair
    bool check_win_condition() const {
        if (m_handSize != MAX_HAND_SIZE) return false;

        int tripletCount = 0, pairCount = 0;
        for (size_t i = 0; i < m_handSize;) {
            int count = 1;
            while (i + count < m_handSize && *m_tiles[i] == *m_tiles[i + count]) {
                ++count;
            }
            if (count == 3) ++tripletCount;
            else if (count == 2) ++pairCount;

            i += count;
        }

        return tripletCount == 4 && pairCount == 1;

    }

    // print my tiles in the hand in the same row and then finish the row and assert dominance over the text file glory to the ones who look forward
    void display_hand() const {
        for (size_t i = 0; i < m_handSize; ++i) {
            std::cout << *m_tiles[i] << " ";
        }
        std::cout << "\n";
    }
};

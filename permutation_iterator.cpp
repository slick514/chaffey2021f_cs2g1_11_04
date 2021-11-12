//
// Created by Justin Gries on 11/10/2021.
//

#include <sstream>
#include <iostream>
#include "permutation_iterator.h"

PermutationIterator::PermutationIterator(const std::string &word) {
    if( !word.empty()) {
        first_char = word.at(0);
        if( word.length() > 1 ) {
            tail = remove_first_character(word);
            helperator = new PermutationIterator(tail);
        }
    }
    permutation_count = (int)word.length();
}

std::string PermutationIterator::next_permutation() {
    std::stringstream builder;
    if( has_more_permutations()) {
        builder << first_char;
        if( tail.empty()) {         // Single letter, no helper to worry about
            deincrement_count();
        } else {                              // Take care of helperator functionality
            if( helperator->has_more_permutations()) {
                builder << helperator->next_permutation();
                rotate_if_helperator_exhausted();
            }
        }
    }
    return builder.str();
}

void PermutationIterator::rotate_if_helperator_exhausted() {
    if( !helperator->has_more_permutations()) {
        rotate_word();
        deincrement_count();
        refresh_helperator();
        // This is how I was doing it previously, before I figured out the allocation/deallocation thing...
        // Six of one, half a dozen of the other, really, but I'm glad that I feel like I've got a better handle on
        // pointers and memory allocation...
        // helperator->refresh(tail);
    }
}

void PermutationIterator::rotate_word() {
    if( !tail.empty()) {
        char new_first_char = tail.at(0);
        tail.erase(0, 1);
        tail.push_back(first_char);
        first_char = new_first_char;
    }
}

bool PermutationIterator::has_more_permutations() const {
    return permutation_count > 0;
}

std::string remove_first_character(const std::string &old_word) {
    return old_word.substr(1, old_word.length());
}

void PermutationIterator::deincrement_count() {
    permutation_count--;
}

PermutationIterator::~PermutationIterator() {
    delete helperator;
}

void PermutationIterator::refresh(const std::string &word) {
    if( !word.empty()) {
        first_char = word.at(0);
        tail = word.length() > 1 ? remove_first_character(word) : "";
        if( helperator != nullptr && helperator->has_more_permutations())
            helperator->refresh(tail);
        permutation_count = (int)word.length();
    }
}

void PermutationIterator::refresh_helperator() {
    PermutationIterator *old_heap_address = helperator;
    helperator = new PermutationIterator(tail);
    delete old_heap_address;
}

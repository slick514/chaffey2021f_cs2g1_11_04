//
// Created by Justin Gries on 11/10/2021.
//

#include <sstream>
#include <iostream>
#include "permutation_iterator.h"

PermutationIterator::PermutationIterator(const std::string &word) {
    if( !word.empty()) {
        first_char = word.at(0);
        end_word = word.length() > 1 ? remove_first_character(word) : "";
        if( !end_word.empty())
            helperator = new PermutationIterator(end_word);
    }
    permutation_count = (int)word.length();
}

std::string PermutationIterator::next_permutation() {
    std::stringstream builder;
    if( has_more_permutations()) {
        builder << first_char;
        if( helperator == nullptr ) {  //single letter, no helper to worry about
            deincrement_count();
        } else {
            if( helperator->has_more_permutations()) {
                builder << helperator->next_permutation();
                if( !helperator->has_more_permutations()) {
                    rotate_word();
                    deincrement_count();
                    helperator->refresh(end_word);
                }
            }
        }
    }
    std::string rtn_value = builder.str();
    return rtn_value;
}

void PermutationIterator::rotate_word() {
    if( !end_word.empty()) {
        char new_first_char = end_word.at(0);
        end_word.erase(0, 1);
        end_word.push_back(first_char);
        first_char = new_first_char;
    }
}

bool PermutationIterator::has_more_permutations() const {
    return permutation_count > 0;
}

std::string PermutationIterator::remove_first_character(const std::string &old_word) {
    std::string new_word = old_word;
    new_word.erase(0, 1);
    return new_word;
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
        end_word = word.length() > 1 ? remove_first_character(word) : "";
        if( helperator != nullptr && helperator->has_more_permutations())
            helperator->refresh(end_word);
        permutation_count = (int)word.length();
    }
}

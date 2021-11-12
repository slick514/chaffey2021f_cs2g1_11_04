//
// Created by Justin Gries on 11/10/2021.
//

#ifndef CHAFFEY2021F_CS2G1_11_04_PERMUTATION_ITERATOR_H
#define CHAFFEY2021F_CS2G1_11_04_PERMUTATION_ITERATOR_H
#include <string>

class PermutationIterator
{
public:
    explicit PermutationIterator(const std::string &word);
    ~PermutationIterator();
    std::string next_permutation();
    bool has_more_permutations() const;
private:
    char first_char;
    std::string end_word;
    int permutation_count;
    PermutationIterator* helperator = nullptr;
    void rotate_word();
    static std::string remove_first_character(const std::string &old_word);
    void deincrement_count();

    void refresh(const std::string &word);
};


#endif //CHAFFEY2021F_CS2G1_11_04_PERMUTATION_ITERATOR_H

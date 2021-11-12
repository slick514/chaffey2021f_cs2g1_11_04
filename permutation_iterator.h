//
// Created by Justin Gries on 11/10/2021.
//

#ifndef CHAFFEY2021F_CS2G1_11_04_PERMUTATION_ITERATOR_H
#define CHAFFEY2021F_CS2G1_11_04_PERMUTATION_ITERATOR_H

#include <string>

class PermutationIterator {
public:
    explicit PermutationIterator(const std::string &word);

    /**
     * release of the helper function's allocated memory when finished
     */
    ~PermutationIterator();

    /**
     * @return a string representing this iterators next iteration
     */
    std::string next_permutation();

    /**
     * @return true if this iterator is not out of iterations and false if all permutations have been exhausted;
     */
    bool has_more_permutations() const;

private:
    char first_char;
    std::string tail;
    int permutation_count;
    PermutationIterator *helperator = nullptr;  // "helperator" = "helper iterator"

    /**
     * assigns the first character of the tail as the new first_char; tacks the old first_char on to the end of the tail
     */
    void rotate_word();

    /**
     * removes one from the permutation count
     */
    void deincrement_count();

    /**
     * resets the PermutationIterator with a new word
     * No longer used, as I switchedto "refresh_helperator" instead, but left here for documentation purposes
     * @param word the word that will now be the source of this iterator's data
     */
    void refresh(const std::string &word);

    /**
     * If the helper iterator has exhausted its iterations, rotate our base-word, deincrement the counter, and reset
     * the helper iterator based off the new tail
     */
    void rotate_if_helperator_exhausted();

    /**
     * creates a new helperator, and frees up the memory from the previous heap allocation
     */
    void refresh_helperator();
};

/**
 * Returns returns a duplicate of "old_word", less the first character;
 * @param old_word
 * @return
 */
static std::string remove_first_character(const std::string &old_word);

#endif //CHAFFEY2021F_CS2G1_11_04_PERMUTATION_ITERATOR_H

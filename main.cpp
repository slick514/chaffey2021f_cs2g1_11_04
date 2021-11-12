#include <iostream>
#include "permutation_iterator.h"

int main() {
    /* 
    The number of permutations is "n!" where n is the word length. Essentially, if you want this thing to end in a reasonable amount of time, keep the number of letters below 9.
    Note that the last permutation is the reverse of the original word.
    */
    PermutationIterator my_iterator("randomly");
    while(my_iterator.has_more_permutations()) {
        std::cout << my_iterator.next_permutation() << std::endl;

    }    return 0;
}

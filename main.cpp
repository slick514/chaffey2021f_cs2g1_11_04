#include <iostream>
#include "permutation_iterator.h"

int main() {
    PermutationIterator my_iterator("able");
    while(my_iterator.has_more_permutations()) {
        std::cout << my_iterator.next_permutation() << std::endl;

    }    return 0;
}

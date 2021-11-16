#include <iostream>
#include "permutation_iterator.h"

using namespace std;

const int MAX_CHARS = 8;

int main() {
    /* 
    The number of permutations is "n!" where n is the word length. Essentially, if you want this thing to end in a reasonable amount of time, keep the number of letters below 9.
    Note that the last permutation is the reverse of the original word.
    */
    cout << "Welcome to Permutations 11.4" << endl;
    string word;
    string answer;
    bool decision;
    do {
        decision = true;
        std::cout << "Please enter a word:" << endl;
        cin >> word;
        if( word.length() > MAX_CHARS ) {
            cout << "Are you sure? A word with more than " << MAX_CHARS << " is going to take " << endl;
            cout << "for...\nev...\ner...\n";
            cout << "(Y)es/(N)o";
            cin >> answer;
            decision = !answer.empty() && tolower(answer[0] == 'y');
        }
    } while( !decision );
    PermutationIterator my_iterator(word);
    while( my_iterator.has_more_permutations()) {
        std::cout << my_iterator.next_permutation() << std::endl;
    }
    return 0;
}

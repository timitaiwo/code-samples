#include <iostream>
#include <array>

// This program implements a binary search algorithm to determine the location of a prime number in an array of prime numbers
// This implementation is based off the binary search algorithm on khanacademy 
// i.e https://www.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search

typedef std::array<int, 25> ArrHolder;

int doSearch(ArrHolder array, int targetValue) {

    size_t arr_size {std::size(array)};
    size_t min_val_index {0};
    size_t max_val_index {arr_size - 1};

    size_t num_runs {0};
    size_t max_runs {50};

    std::cout << "array size is " << arr_size << std::endl << std::endl;
    
    while (true) {
        std::cout << "run " << (num_runs + 1) << ": ";
        
        if (num_runs >= max_runs){
            std::cout << "algo has run for too long" << std::endl;
            return -1;
        }

        size_t guess_index = (max_val_index + min_val_index)/2;
        int guess_value = array[guess_index];
        
        std::cout << "guess index is " << guess_index;
        std::cout << ", values at index is " << array[guess_index] << std::endl;

        if (guess_value > targetValue) {
            max_val_index = guess_index;
        } else if (guess_value < targetValue) {
            min_val_index = guess_index;
        } else if (guess_value == targetValue) {
            std::cout << "\nValue found at " << guess_index << std::endl;
            return guess_index;
        }
        
        num_runs += 1;
    }

    return -1;
}


int main() {

    ArrHolder primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int targetValue = 73;
    
    doSearch(primes, targetValue);
}
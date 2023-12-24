'''
This program implements a binary search algorithm to determine the location of a prime number in an array of prime numbers
This implementation is based off the binary search algorithm on khanacademy with a tweak to use a random index instead of 
the average index value of the min and max indexes. The khan academy course is found at 
https://www.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search
'''

import random
random.seed(554)

def doSearch(array:list, targetValue: int):
    min_arr_index: int = 0
    max_arr_index: int = len(array)
    num_iterations: int = 0

    while(True):
        # print(f"min is {min_arr_index} and max is {max_arr_index}")
        if (num_iterations >= 50):
            break
        
        valid_guesses = array[min_arr_index: max_arr_index] 
        guess_index = min_arr_index + round(random.random() * len(valid_guesses))
        guess_value = array[guess_index]

        if guess_value > targetValue:
            max_arr_index = guess_index
        elif guess_value < targetValue:
            min_arr_index = guess_index
        elif guess_value == targetValue:
            print(f"round {num_iterations + 1}: guess_value is {guess_value}, guess_index is {guess_index}\n")
            print ("Value found at index ", guess_index)
            return guess_index

        print(f"round {num_iterations + 1}: guess_value is {guess_value}, guess_index is {guess_index}\n")
        num_iterations += 1

        # for i in valid_guesses:
        #     print(i)


    return -1


primes : list = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
targetValue : int = 73

# print(len(primes))

doSearch(primes, targetValue)
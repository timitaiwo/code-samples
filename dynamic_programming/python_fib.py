'''
Implement Fibonnacci sequence using recursion, 
recursion and memoisation as well as 
buttom-up dynamic programming  
'''

def fib_recurse(target_n : int):

    if target_n > 40:
        raise RecursionError

    if target_n < 2:
        return 1

    output = fib_recurse(target_n-1) + fib_recurse(target_n-2)

    return output

memo = dict()
def fib_memo(target_n : int):

    if target_n < 2:
        return 1

    if target_n in memo:
        return memo[target_n]
    
    output = fib_memo(target_n-1) + fib_memo(target_n-2)

    memo[target_n] = output
    
    return output


def fib_bottom_up(target_n : int):
    memo = dict()

    memo[0] = 1
    memo[1] = 1
    
    for number in range(2, target_n + 1):
        memo[number] = memo[number-1] + memo[number-2]

    return memo[target_n]

if __name__ == "__main__":

    numbers = [3, 30, 300]

    for n in numbers:
        print(f"Using naive recursion ({n}): ")
        
        try:
            print(fib_recurse(n), "\n")
        except:
            print(f"Choosing not to use naive recursion as {n} is too big\n")
        
        print(f"Using memoization recursion ({n}): ")

        try:
            print(fib_memo(n), "\n")
        except:
            print(f"Cannot use memoization recursion as {n} is too big")
        
        print(f"Using buttom-up dynamic programming ({n}): ")
        print(fib_bottom_up(n), "\n")
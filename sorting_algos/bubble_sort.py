from swap import *

arr : list = [3, 2, 4, 1, 5]

arr_sorted = False
runs = 1

print(f"run {runs}: The arr is {arr}")

while not arr_sorted:
    num_changes = 0
    for i in range(len(arr)):
        current = i
        next = i+1

        if next == len(arr):
            break

        if arr[current] > arr[next]:
            swap(arr, current, next)
            num_changes += 1
    
    runs += 1
    if num_changes == 0:
        break
    print(f"run {runs}: The arr is {arr}")

# print(arr)
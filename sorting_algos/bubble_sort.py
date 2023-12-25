from swap import swap

def bubble_sort(arr: list):
    runs: int = 1
    print("This is a bubble sort")
    print(f"run {runs}: The arr is {arr}")
    while True:
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


from bubble_sort import bubble_sort

arr : list = [3, 2, 4, 1, 5, 0]
arr2 : list = [8, 2, 4, 6, 9, 7, 10, 1, 5, 3]

# bubble_sort(arr2)

def merge_sort(arr: list):

    midpoint = int(len(arr)/2)
    
    if len(arr) > 1:
        left_arr = arr[:midpoint]
        
        return arr



print(merge_sort(arr))

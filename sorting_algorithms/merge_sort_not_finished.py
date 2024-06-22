from swap import swap

def merge(left_arr, right_arr):
    '''
    Takes two ordered list and merge them
    '''

    combined_arr = []

    len_left = len(left_arr)
    len_right = len(right_arr)

    num_checks = len_left if len_right < len_left else len_left

    for i in range(num_checks):
        pass

        # if i == num_checks-1:
        #     combined_arr.append(left_arr[num_checks:])

    return combined_arr


print(merge([1, 2, 3, 4], [7, 9, 12, 56]))

def merge_sort(arr: list):

    midpoint = int(len(arr)/2)
    
    if len(arr) > 1:
        left_arr = arr[:midpoint]
        right_arr = arr[midpoint+1:]
        
        return merge(merge_sort(left_arr), merge_sort(right_arr))

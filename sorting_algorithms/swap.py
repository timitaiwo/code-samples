def swap(arr, current, next):
    temp = arr[current]
    arr[current] = arr[next]
    arr[next] = temp
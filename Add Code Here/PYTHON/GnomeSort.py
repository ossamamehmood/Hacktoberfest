def gnome_sort(arr):
    """Gnome Sort main function"""
    idx = 0
    while idx < len(arr):
        if idx == 0 or arr[idx] >= arr[idx - 1]:
            idx += 1
        else:
            arr[idx], arr[idx - 1] = arr[idx - 1], arr[idx]
            idx -= 1
    return arr
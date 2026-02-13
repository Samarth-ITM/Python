def main(): 
    nums = [1, 2, 3, 4, 5, 6, 7]
    target = 0
    l = 0
    r = len(nums) - 1
    f = 0

    while r >= l:
        m = (l + r)/2
        if nums[m] == target:
            print("Found at index", m)
            f = 1
            break
        elif nums[m] < target:
            l = m + 1
        else:
            r = m - 1

    if f != 1:
        print("Not Found")



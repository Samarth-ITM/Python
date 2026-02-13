def moveZeroes(nums):
    """
    :type nums: List[int]
    :rtype: None Do not return anything, modify nums in-place instead.
    """
    t = []
    c = 0
    for i in range(len(nums)):
        if nums[i] != 0:
            t.append(nums[i])
        else:
            c += 1
    for i in range(c):
        t.append(0)
    return t
            
            
n = [0,1,0,3,12]

print(moveZeroes(n))
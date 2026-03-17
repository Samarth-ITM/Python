def ss(nums, k):
    maxsum = []
    l = 0
    r = k
    ls = []
    f = 0
    while r <= len(nums):
        cursum = 0
        for i in range(l, r):
            if nums[i] not in ls:
                cursum += nums[i]
                ls.append(nums[i])
            else:
                f=1
        if f == 1:
            cursum = 0
        f = 0
        ls = [-1]
        maxsum.append(cursum)
        ls = []
        l += 1
        r += 1

    return max(maxsum) if maxsum else 0

nums = [1,1,1,7,8,9]
k = 3


print(ss(nums, k))


        
        


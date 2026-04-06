nums = [2, 0]


nums = sorted(nums) #n(logn)

for i in range(len(nums)): #n 
    if (i+1<len(nums)): #1 + 1
        if ((nums[i+1]) != nums[i]+1): #3
            print(nums[i]+1) #1
    else:
        continue
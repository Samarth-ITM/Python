nums = [2, 0]


nums = sorted(nums)

for i in range(len(nums)):
    if (i+1<len(nums)):
        if ((nums[i+1]) != nums[i]+1):
            print(nums[i]+1)
    else:
        continue
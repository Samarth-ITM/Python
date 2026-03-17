nums = [2,7,11,15]
target = 9

t = [nums[i] for i in range(len(nums)) if nums[i]<target]
print(t)
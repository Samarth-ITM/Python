
nums = [1,2,3,3]



for i in range(len(nums)):
    if nums[i] in (nums[0:i] or nums[i+1:]):
        print(nums[i])
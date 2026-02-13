nums = [-1,-2,-3,-4,-5]
target = -8





for i in range(len(nums)):

    if (target - nums[i] in (nums[:i] or nums[i+1:])) and i != nums.index(target - nums[i] ):
        print([nums.index(target - nums[i]), i ])

    else:
        continue


import numpy as np

nums = [1,2,3,4]


j = 1
i = 0
s = 1
res = []
while i < len(nums):
    if j < len(nums):
        if i == j:
            j+=1
            continue
        else:
            s *= nums[j]
            j+=1
    else:
        res.append(s)
        s=1
        i+=1
        j=0
print(res)
    
t = []
for i in range(len(nums)):
    element = nums.pop(i) 
    t.append(np.prod(nums))
    nums.insert(i, element)
print(list(t))




print([1]*5)q
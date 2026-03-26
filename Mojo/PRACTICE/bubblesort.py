nums = [10,9,8,7,6,5,4,3,2,1]
n = len(nums) -1 
flag = False  
for i in range(n):
    flag = False
    for j in range(0, n - i):
        if nums[j] > nums[j + 1]:
            nums[j], nums[j + 1] = nums[j+1], nums[j]
            flag = True
    if flag == False:
        break
print(nums)


def findDisappearedNumbers(nums):
    nums = sorted(list(set((nums))))
    t = []
    print(nums)
    if nums[0] != 1:
        t.append(1)
    c = 0
    l = len(nums)
    while c<=l:
        if c+1 < len(nums) and nums[c]+1 != nums[c+1]:
            t.append(nums[c])
            t.append(nums[c]+1)
            l+=2
        else:
            t.append(c)
        c+= 1
        if t[-1] == max(nums):
            break
    print(t)
        
nums = [4,3,2,7,8,2,3,1]

findDisappearedNumbers(nums)
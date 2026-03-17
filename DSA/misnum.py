nums = [2147483647]

def firstMissingPositive(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    m = max(nums)
    for i in range(1,m):
        if i not in nums:
            return i
        else:
            i+=1
    return m+1

print(firstMissingPositive(nums))

nums1 = [4,1,2,3,5]


stack = []
ans = [-1]*len(nums1)

for i in range(len(nums1)-1, -1, -1):
    while stack and stack[-1]<=nums1[i]:
        stack.pop()
    if not(stack):
        ans[i] = -1
    else:
        ans[i] = stack[-1]
    stack.append(nums1[i])
    
print(ans)
s = "abac"

from collections import Counter
class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l = Counter(s)
        keys = list(l.values())

        if len(s) == 0: return False
        if len(keys) == 1: return True
            
        # if min(l.values())!= keys[1] or max(l.values())!=keys[-2]: return False

        # if sum(l.values())&1: return False
        
        r1 = r2 = len(list(s)) - 1

        while r2 > (len(s)//2 -1):
            r2 -= 1            
            dsub = r1 - r2
            if s[r1]==s[r2]:
                subins = len(s)/dsub
                if subins == int(subins): #error
                    print(s[r1])
                    print(s[r2])
                    print(s[r2+1: r1+1])
                    print(s[r2+1: r1+1]*int(subins))
                    if s[r2+1: r1+1]*int(subins) == s:
                        return True
        return False

print(Solution().repeatedSubstringPattern(s))
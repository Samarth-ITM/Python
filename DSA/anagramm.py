

def groupAnagrams(strs: List[str]) -> List[List[str]]: # pyright: ignore[reportUndefinedVariable]
    from collections import Counter
    #find counter for each, and check check pointers match and then append in main list
    n = len(strs)
    l = []
    if n == 1:
        l.append([strs[0]])
        return l
    for i in strs:
        s = []
        s.append(i)
        print(i)

        for j in strs[:strs.index(i)] + strs[strs.index(i)+1:]:
            if Counter(i) == Counter(j):
                s.append(j)
                strs.remove(j)
        l.append(s)
    return l

strs =["","b",""]

groupAnagrams(strs)
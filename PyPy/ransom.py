ransomNote ="bg"
magazine ="efjbdfbbbgdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj"


from collections import Counter
r = dict(Counter(sorted(list(ransomNote))))
m = dict(Counter(sorted(list(magazine))))

f = 0
for i in r.items():
    if i[0] in m.keys():
        f += (m.get(i[0])) # type: ignore
print(f)

s ="abccccdd"


s1 = []
s2 = []
scrap = []
s = sorted(s, reverse = True)
skip = 0
for i in range(0,len(s)):
    if skip == 1:
        skip = 0
        continue
    
    elif i+1<len(s) and s[i] == s[i+1]:
        s1.append(s[i])
        s2.append(s[i+1])
        skip = 1
    else:
        scrap.append(s[i])
        try:
            scrap.append(s[i+1])
        except:
            continue
            
if len(scrap)>=1 and s1:
    print((len(s1+s2[::-1]))+1)
    
elif len(s)==1:
    print(1)
else:
    print(len(s1+s2[::-1]))
s = "MCMXCIV"
c = 0
for i in range(len(s)):

    if s[i] == "I":
        if i + 1 < len(s) and (s[i+1] == "V" or s[i+1] == "X"):
            pass
        else:
            c += 1

    elif s[i] == "V":
        if i - 1 >= 0 and s[i-1] == "I":
            c += 4
        else:
            c += 5

    elif s[i] == "X":
        if i - 1 >= 0 and s[i-1] == "I":
            c += 9
        elif i + 1 < len(s) and (s[i+1] == "L" or s[i+1] == "C"):
            pass
        else:
            c += 10

    elif s[i] == "L":
        if i - 1 >= 0 and s[i-1] == "X":
            c += 40
        else:
            c += 50

    elif s[i] == "C":
        if i + 1 < len(s) and (s[i+1] == "M" or s[i+1] == "D"):
            pass
        elif i - 1 >= 0 and s[i-1] == "X":
            c += 90
        else:
            c += 100

    elif s[i] == "D":
        if i - 1 >= 0 and s[i-1] == "C":
            c += 400
        else:
            c += 500

    elif s[i] == "M":
        if i - 1 >= 0 and s[i-1] == "C":
            c += 900
        else:
            c += 1000
    else:
        pass
print(c)
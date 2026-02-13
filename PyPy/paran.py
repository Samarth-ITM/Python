s = ")"
def paran(s):
    p = list(s)
    t = []
    skip = 0
    c = 0
    if len(p) == 1:
        return False
    for i in range(len(p)):
        if p[i] in "({[":
            t.append(p[i])
            c += 1
        elif p[i] in ")]}":
            skip = 1
            if i-1>=0 and (p[i]==")" and t[c-1] == "("):
                t.pop()
                c -=1 
            elif i-1>=0 and (p[i]=="]" and t[c-1] == "["):
                t.pop()
                c -= 1
            elif i-1>=0 and (p[i]=="}" and t[c-1] == "{"):
                t.pop()
                c -= 1
    if t == []:
        return (True)
    else:
        return False

print(paran(s))
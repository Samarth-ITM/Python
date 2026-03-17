n = 19

n = (list(map(int, str(abs(n)) if n < 0 else str(n))))
print(n)

if len(n) == 1 and n[0] == 1:
    print(True)

t = 0

while True:
    for i in n:
        t += i**2
    n = t
    n = (list(map(int, str(abs(n)) if n < 0 else str(n))))
    
    if t==1:
        return True
    t = 0


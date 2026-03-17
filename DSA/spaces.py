releaseTimes = [0, 5, 20, 11]
keysPressed ="aapd"
keysPressed =list(keysPressed)
nrt=[releaseTimes[0]]


for i in range(1, len(releaseTimes)):
    t = releaseTimes[i] - releaseTimes[i-1]
    nrt.append(t)

perf = dict(zip(keysPressed, nrt))

min = []
for i in nrt:
    if i == max(nrt):
        min.append(i)

if len(min)==1:
    print(keysPressed[nrt.index(max(nrt))])

tax = []
for i,j in perf.items():
    if j == min[0]:
        tax.append(i)
        
print(max(tax))


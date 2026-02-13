def calPoints(operations):
    """
    :type operations: List[str]
    :rtype: int
    """
    o = operations
    rec = []

    for i in o:
        try:
            if int(i):
                rec.append(i)
        except:
            if i == "C":
                if rec:
                    rec.pop()
            elif i == "D":
                if rec:
                    rec.append(int(rec[-1])*2)
            elif i == "+":
                if len(rec)>=2:
                    rec.append(int(rec[-1])+int(rec[-2]))
            else:
                pass
    rec = [int(i) for i in rec]
    return sum(rec)
    
op = ["1","C"]

print(calPoints(op))


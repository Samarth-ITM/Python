moves = "RL"

def judgeCircle(moves):
        """
        :type moves: str
        :rtype: bool
        """
        U = 1
        D = -1
        L = 2
        R = -2
        s = []
        t = list(moves)
        for i in t:
            if i== "U":
                s.append(U)
            elif i == "D":
                s.append(D)
            elif i == "L":
                s.append(L)
            elif i == "R":
                s.append(R)
        
        if sum(s) == 0:
            return True
        else:
            return False
            
print(judgeCircle(moves))
class com1:
    class Emp:
        def __init__(self, name, num):
            self.name = name
            self.num = num
        def det(self):
            return f"{self.name} {self.num}"
            
    def __init__(self, name):
        self.name = name
        self.ls = []    
        
    def addemp(self, name, num):
        new_emp = self.Emp(name, num)
        self.ls.append(new_emp)
        
    def show(self):
        return [i.det() for i in self.ls]


c1 = com1("Nigga")

c1.addemp("1", 1)
c1.addemp("2", 2)

print(c1.show())
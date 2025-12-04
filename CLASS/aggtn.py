class School:
    def __init__(self, nm):
        self.name = str(nm)
        self.ls = []
        
    def db(self, std):
        self.ls.append(std)

    def listd(self):
        for std in self.ls:
            print(f"{std.name} is in grade {std.grade}")
        

class Stud:
    def __init__(self, name, grade):
        self.name = str(name)
        self.grade = int(grade)

sch = School("ITM")

s1 = Stud("1", 1)
s2 = Stud("2", 2)
s3 = Stud("3", 3)


sch.db(s1)
sch.db(s2)
sch.db(s3)


sch.listd()





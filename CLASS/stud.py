class Student:
    money = 20
    num_std = 0
    def __init__(self, name, age):
        self.name = name
        self.age = age
        Student.num_std += 1
        
        
std1 = Student("Sam", 18)
std2 = Student("Nigga", 12)
std3 = Student("man", 99)

print(std1.name)
print(std1.age)
print(std2.name)
print(std2.age)
print(std3.name)
print(std3.age)
print(Student.money)
print(Student.num_std)
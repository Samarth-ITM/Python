class Animals:
    
    place = "zoo"
    number = 0
    def __init__(self, name, isalive):
        self.name = name
        self.isalive = True
        Animals.number +=1
        pass
    
    def eat(self):
        print(f"{self.name} is eating")
        
    def sleep(self):
        print(f"{self.name} is sleeping")
        
class Dog(Animals):
    def speak(self):
        print(f"{self.name} says WOOF")
    pass

class Rat(Animals):
    def steal(self):
        print("Steal")
    pass

class Cat(Animals):
    def climb(self):
        print("Climb")
    pass

dog = Dog("Scooby", True)
cat = Cat("Meow", False)
rat = Rat("Moloch", True)


dog.eat()
dog.sleep()
dog.speak()

cat.eat()
cat.sleep()
cat.climb()

rat.eat()
rat.sleep()
rat.steal()

print(f"Animals stay in {Animals.place}")
print(f"There are {Animals.number} Animals")


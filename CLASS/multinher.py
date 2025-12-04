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
        
class Predators(Animals):
    def pred(self):
        print(f"{self.name} is hunting")
        
class Prey(Animals):
    def prey(self):
        print(f"{self.prey} is fleeing")
        
        
                
class Dog(Animals, Predators):
    def speak(self):
        print(f"{self.name} says WOOF")
    pass
    
class Rat(Animals, Prey):
    def steal(self):
        print("Steal")
    pass

class Cat(Animals, Predators, Prey):
    def climb(self):
        print("Climb")
    pass

dog = Dog("Scooby", True)
cat = Cat("Meow", False)
rat = Rat("Moloch", True)


dog.eat()
dog.sleep()
dog.speak()
dog.pred()

cat.eat()
cat.sleep()
cat.climb()

rat.eat()
rat.sleep()
rat.steal()

print(f"Animals stay in {Animals.place}")
print(f"There are {Animals.number} Animals")


class Animal():
    def __init__(self, name, has_limbs, is_intel):
        self.name = str(name)
        self.has_limbs = bool(has_limbs)
        self.is_intel = bool(is_intel)
        pass
    
    def land(self):
        print(f"{self.name} {"lives" if self.has_limbs else "does not live"} on land")
        
        
class Humans(Animal):
    def __init__(self, name, has_limbs, is_intel):
        super().__init__(name, has_limbs, is_intel)
        
    def efbh(self):
        print(f"{self.name} Eats food by hand has he has {self.has_limbs} limbs and is {self.is_intel} intel")
    pass

class Monkey(Humans):
    def __init__(self, name, has_limbs, is_intel):
        super().__init__(name, has_limbs, is_intel)
        
    def dumb(self):
        print(f"{self.name} is dumb as he has {self.is_intel} intel.")
    pass

class Fish(Animal):
    def __init__(self, name, has_limbs, is_intel):
        super().__init__(name, has_limbs, is_intel)
        
    def swim(self):
        print(f"{self.name} swims under water as he has {self.has_limbs} limbs and has {self.is_intel} intel")
    pass


hum = Humans("Nigga", True, True)
mon = Monkey("Kiikikikiii", True, False)
fis = Fish("Glup Glup", False, False)



hum.efbh()
hum.land()

mon.efbh()

mon.dumb()

mon.land()


fis.swim()

fis.land()

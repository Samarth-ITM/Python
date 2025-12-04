class Car:
    def __init__(self, model, year, colour, for_sale):
        self.model = model
        self.year =  year
        self.colour = colour
        self.for_sale = for_sale
    
    def drive(self):
        print(f"You drive the {self.colour} car")
        
    def stop(self):
        print(f"You stop the {self.colour} car")
        
    def desc(self):
        print(f"This is a {self.model} of {self.year} for {self.for_sale}")

car1 = Car("Mango", 2025, "black", True)

car2 = Car("Mango", 2007, "yellow", False)
print(car1)
print(car1.model)
print(car1.year)
print(car1.colour)
print(car1.for_sale)

print(car2)
print(car2.model)
print(car2.year)
print(car2.colour)
print(car2.for_sale)

car1.drive()
car2. drive()
car1.stop()
car2.stop()

car1.desc()
car2.desc()
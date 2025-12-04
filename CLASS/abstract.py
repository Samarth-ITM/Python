from abc import ABC, abstractmethod


class Bank(ABC):
    
    def __init__(self, name):
        self.name = name
    
    @abstractmethod
    def withdraw(self):
        pass

    @abstractmethod
    def deposit(self):
        pass

    
class Boss(Bank):

    def withdraw(self):
        print(f"{self.name} has withdrawn")

    def deposit(self):
        print(f"{self.name} has deposited")
        
    def salary(self):
        print(f"{self.name} has gotten salary")


class Manger(Boss):
    def emp(self):
        print(f"{self.name} is employed")
        

manager = Manger("nigga")
manager.withdraw()
manager.deposit()
manager.emp()
manager.salary()
boss = Boss("Nigger")
boss.withdraw()
boss.deposit()
boss.salary()
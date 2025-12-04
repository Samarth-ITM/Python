class Game:
    class Player:
        def __init__(self, name, level):
            self.name = name
            self.level = level
            pass
        
        def player_items(self):
            self.items = []
            pass

        def into(self):
            print(f"{self.name} (Level {self.level})")
            
    class Item:
        def __init__(self, name, power):
            self.name = name
            self.power = power

        def info(self):
            print(f"{self.name} [+{self.power}]")
            pass
    def __init__(self,  name):
        self.name = name
        self.gamers = []

    def add_player(self, player_name, player_lvl):
        self.no_item = ""
        new_player = self.Player(player_name, player_lvl)
        self.gamers.append(new_player)
    
    def add_item_to_player(self, to_item, item_name, item_power):
        item = self.Item(item_name, item_power)
        to_item = self.Player.player_items.items(to_item)
        self.Player.player_items.items.append(to_item)
        
    def show_players(self):
        return [play.info() for play in self.gamers]
    
    def show_inventory(self, player_name):
        return [inv.info() for inv in self.Player.player_items.items]
    
g = Game("QuestX")
g.add_player("Sam", 5)
g.add_player("Alex", 2)

g.add_item_to_player("Sam", "Sword", 10)
g.add_item_to_player("Sam", "Shield", 7)
g.add_item_to_player("Alex", "Bow", 5)

print(g.show_players())
print(g.show_inventory("Sam"))

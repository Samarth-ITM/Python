class Game:
    class Player:
        def __init__(self, name, level):
            self.name = name
            self.level = level
            self.items = []
            pass

        def info(self):
            print(f"{self.name} (Level {self.level})")
            
    class Item:
        def __init__(self, name, power):
            self.name = name
            self.power = power

        def info(self):
            return f"{self.name} [+{self.power}]"
            pass
    def __init__(self,  name):
        self.name = name
        self.gamers = []

    def add_player(self, player_name, player_lvl):
        self.no_item = ""
        new_player = self.Player(player_name, player_lvl)
        self.gamers.append(new_player)
    
    def add_item_to_player(self, player_name, item_name, item_power):
        # create the item
        item = self.Item(item_name, item_power)

        # find the correct player and attach the item
        for player in self.gamers:
            if player.name == player_name:
                player.items.append(item)
                break
        
    def show_players(self):
        return [player.info() for player in self.gamers]
    
    def show_inventory(self, player_name):
        # find player, then return their item infos
        for player in self.gamers:
            if player.name == player_name:
                return [item.info() for item in player.items]
        return []  # if player not found
    

g = Game("QuestX")
g.add_player("Sam", 5)
g.add_player("Alex", 2)

g.add_item_to_player("Sam", "Sword", 10)
g.add_item_to_player("Sam", "Shield", 7)
g.add_item_to_player("Alex", "Bow", 5)

print(g.show_players())
print(g.show_inventory("Sam"))

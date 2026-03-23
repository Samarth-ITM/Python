print("Welcome to the tea shop!")
print("We have the following teas available:")
teas = ["1. Green Tea", "2. Black Tea", "3. Oolong Tea", "4. White Tea", "5. Herbal Tea"]
for tea in teas:
    print(f"- {tea}")
selected_tea = input("\nPlease select a tea by typing its number:")
if selected_tea in teas:
    print(f"You have selected {selected_tea}. Enjoy your tea!")
else:
    print("Sorry, we don't have that tea.")
    
#making seleted tea

if selected_tea == "1":
    #whcich type of green tea
    green_teas = ["Sencha", "Matcha", "Gyokuro", "Longjing"]
    print("We have the following types of Green Tea:")
    for tea in green_teas:
        print(f"- {tea}")
    selected_green_tea = input("\nPlease select a type of Green Tea by typing its name:")
    #milk condition
    milk_option = input("Would you like to add milk to your Green Tea? (yes/no):")
    if milk_option.lower() == "yes":
        which_milk = input("Which type of milk would you like to add? (1. Whole Milk, 2. Skim Milk, 3. Almond Milk, 4. Soy Milk):")
        print(f"You have selected {which_milk}.")
    if selected_green_tea in green_teas:
        print(f"You have selected {selected_green_tea}. Enjoy your tea!")
    else:
        print("Sorry, we don't have that type of Green Tea.")
        
elif selected_tea == "2":
    #which type of black tea
    black_teas = ["1. Assam", "2. Darjeeling", "3. Earl Grey", "4. English Breakfast"]
    print("We have the following types of Black Tea:")
    for tea in black_teas:
        print(f"- {tea}")
    selected_black_tea = input("\nPlease select a type of Black Tea by typing its number:")
    milk_option = input("Would you like to add milk to your Black Tea? (yes/no):")
    if milk_option.lower() == "yes":
        which_milk = input("Which type of milk would you like to add? (1. Whole Milk, 2. Skim Milk, 3. Almond Milk, 4. Soy Milk):")
        print(f"You have selected {which_milk}.")
    if selected_black_tea in black_teas:
        print(f"You have selected {selected_black_tea}. Enjoy your tea!")
    else:
        print("Sorry, we don't have that type of Black Tea.")
        
elif selected_tea == "3":
    #which type of oolong tea
    oolong_teas = ["1. Tie Guan Yin", "2. Da Hong Pao", "3. Wuyi Rock Tea", "4. Milk Oolong"]
    print("We have the following types of Oolong Tea:")
    for tea in oolong_teas:
        print(f"- {tea}")
    
    selected_oolong_tea = input("\nPlease select a type of Oolong Tea by typing its number:")
    milk_option = input("Would you like to add milk to your Oolong Tea? (yes/no):")
    if milk_option.lower() == "yes":
        which_milk = input("Which type of milk would you like to add? (1. Whole Milk, 2. Skim Milk, 3. Almond Milk, 4. Soy Milk):")
        print(f"You have selected {which_milk}.")
    if selected_oolong_tea in oolong_teas:
        print(f"You have selected {selected_oolong_tea}. Enjoy your tea!")
    else:
        print("Sorry, we don't have that type of Oolong Tea.")
        
elif selected_tea == "4":
    #which type of white tea
    white_teas = ["1. Silver Needle", "2. White Peony", "3. Shou Mei", "4. Gong Mei"]
    print("We have the following types of White Tea:")
    for tea in white_teas:
        print(f"- {tea}")
    selected_white_tea = input("\nPlease select a type of White Tea by typing its number:")
    milk_option = input("Would you like to add milk to your White Tea? (yes/no):")
    if milk_option.lower() == "yes":
        which_milk = input("Which type of milk would you like to add? (1. Whole Milk, 2. Skim Milk, 3. Almond Milk, 4. Soy Milk):")
        print(f"You have selected {which_milk}.")
        
    if selected_white_tea in white_teas:
        print(f"You have selected {selected_white_tea}. Enjoy your tea!")
    else:
        print("Sorry, we don't have that type of White Tea.")
        
elif selected_tea == "5":
    #which type of herbal tea
    herbal_teas = ["1. Chamomile", "2. Peppermint", "3. Rooibos", "4. Hibiscus"]
    print("We have the following types of Herbal Tea:")
    for tea in herbal_teas:
        print(f"- {tea}")
    selected_herbal_tea = input("\nPlease select a type of Herbal Tea by typing its number:")
    milk_option = input("Would you like to add milk to your Herbal Tea? (yes/no):")
    if milk_option.lower() == "yes":
        which_milk = input("Which type of milk would you like to add? (1. Whole Milk, 2. Skim Milk, 3. Almond Milk, 4. Soy Milk):")
        print(f"You have selected {which_milk}.")
    if selected_herbal_tea in herbal_teas:
        print(f"You have selected {selected_herbal_tea}. Enjoy your tea!")
    else:
        print("Sorry, we don't have that type of Herbal Tea.")

else:
    print("Sorry, we don't have that tea.")
    




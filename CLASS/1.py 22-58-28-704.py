rent = 9330
rent = 500
no_100_notes = 0
no_50_notes = 0
no_10_notes = 0
# Calculate the number of notes required to meet the given rent amount
while rent - 100 >= 0:
    no_100_notes += 1
    rent = rent - 100
while rent - 50 >= 50:
    rent = rent - 50
    no_50_notes +=1 
while rent - 10 >= 10:
    rent = rent - 10
    no_10_notes += 1


# Print the result
print("Monica will require:")
print(str(no_100_notes) + " x ₹100 notes")
print(str(no_50_notes) + " x ₹50 notes")
print(str(no_10_notes) + " x ₹10 notes")
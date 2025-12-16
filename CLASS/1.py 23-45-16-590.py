# Use nested while loops to iterate through the Nested List `fish_tank`
# Print Found Nemo at `i,j` when `*` is found.
fish_tank = [
  ['w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'],
  ['w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'],
  ['w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'],
  ['w', 'w', 'w', 'w', 'w', '*', 'w', 'w', 'w', 'w'],
  ['w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w']
]
r = 0 
c = 0
for i in fish_tank:
  r+=1
  for j in i:
    c+=1
    if j == "*":
      print(r,c)
      break
    

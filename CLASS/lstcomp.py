num = [1,2,3,4,5,6,7,8,9, 10]
num = [i**2 for i in num if i%2==0]
print(num)

str = ["apple", "mango", "mustard", "grape", "banana"]
str = [i.capitalize() for i in str if len(i)<6]
print(str)

mrk = [87, 55, 29, 98, 21, 56, 60]
mrk = ["pass" if i >60 else "fail" for i in mrk]
print(mrk)
number = int(input("please enter a number to divide: "))

# create the number list
num_list = list(range(1, number + 1))
div_list = []

# iterate through the num_list
for num in num_list:
    # if the user number is divisible by num, append
    if number % num == 0:
        div_list.append(num)
print(div_list)

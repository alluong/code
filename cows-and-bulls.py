import random

# append leading 0 as needed
def append_zero(num):
    if (int(num) < 10):
        num = "000" + num
    elif (int(num) < 100):
        num = "00" + num
    elif (int(num) < 1000):
        num = "0" + num
    return num

# check user numbere
def check_num(in_num):
    cow = 0
    bull = 0
    for elem in range(len(seed)):
        if seed[elem] == in_num[elem]:
            cow += 1
        else:
            bull += 1
    if cow == len(seed):
        print(str(cow) + " cows")
        return True
    print(str(cow) + " cows and " + str(bull) + " bulls")
    return False

# generate a random number between 0 to 9999 and append leading 0
seed = append_zero(str(random.randint(0, 9999)))

if __name__ == "__main__":
    done = False
    while not done:
        num = append_zero(input("please enter a 4-digit number: "))
        print(num)
        if check_num(num):
            done = True
            print("done")

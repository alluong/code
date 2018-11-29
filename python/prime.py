def is_prime(num):
    if num > 1:
        if len(check_prime_list) == 0:
            return True
        return False

while 1:
    num = int(input("please enter a number: "))

    # check_prime_list is empty if num is a prime number
    # otherwise, check_prime_list contains a list of divisors divisible by num
    check_prime_list = [x for x in range(2, num) if num % x == 0]
    if is_prime(num):
        prime = ""
    else:
        prime = "not "
    print(str(num) + " is " + prime + "a prime number")

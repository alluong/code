# generate a sequence of fibonnaci numbers
num = int(input("please enter number of fibonnacci numbers: "))

def fib(num):
    list = []
    cur = 1
    prev = 0
    while num != 0:
        list.append(cur)
        save = cur
        cur = cur + prev
        prev = save
        num -= 1
    return list

fib = fib(num)
print(fib)

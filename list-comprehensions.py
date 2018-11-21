a = [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
b = []

#for num in range(len(a)):
#    if (num % 2 == 0):
#        b.append(a[num])
b = [a[num] for num in range(len(a)) if num % 2 == 0]

print(b)

s = input("Please enter a string: ")
palindrome = 1

for ii in range(int(len(s)/2)):
    if s[ii] != s[len(s) - ii - 1]:
        palindrome = 0
        break
if palindrome:
    print(s + " is a palindrome")
else:
    print(s + " is not a palindrome")

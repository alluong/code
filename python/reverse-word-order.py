# string to be reversed
s = "My name is Michelle"

# split with white spaces
s_list = s.split()

# reverse
s_list.reverse()

# join string with white spaces
result = " ".join(s_list)
print(result)

a = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
b = [1, 2, 3, 4, 5, 6, 7, 8, 8, 9, 10, 11, 12, 13]

def new_list(in_list):
    new_list = []
    for elem in in_list:
        if elem not in new_list:
            new_list.append(elem)
    return new_list
#   return list(set(in_list)) works also

unique_list = new_list(a)
print(unique_list)
unique_list = new_list(b)
print(unique_list)

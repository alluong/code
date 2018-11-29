# get number and append to list
def get_number(p_list, fname):
    with open(fname) as f:
        # read a line
        line = f.readline()
        while line:
            # append line to list
            p_list.append(int(line))
            line  = f.readline()

# return a list that is overlap of list1 and list2
def get_overlap(list1, list2):
    olist = [elem for elem in list1 if elem in list2]
    return olist
    
if __name__ == '__main__':
    h_list = []
    p_list = []
    get_number(h_list, 'happynumbers.txt')
    get_number(p_list, 'primenumbers.txt')
    overlap = get_overlap(h_list, p_list)
    print(overlap)

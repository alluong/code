# draw horizontal lines
def draw_horz(length):
    print("+---" * length, end="")
    print("+")
    
# draw vertical lines
def draw_vert(length):
    print("|   " * length, end="")
    print("|")
    
if __name__ == '__main__':
    # assuming square game board
    size = int(input("enter board size: "))
    for ii in range(size):
        draw_horz(size)
        draw_vert(size)
    draw_horz(size)




def surround_regions(board):
    row = len(board)
    col = len(board[0])
    for i in range(row):
        for j in range(col): 
            if board[i][j] == 'X':
                continue    
            else:
                if i != row - 1 and i != 0 and j != col - 1 and j != 0: #It is not a border cell 
                    if checkAdjacents(board, i, j): #Check the adjacent cells to see if valid or not, if valid then change current cell to a  O 
                        board[i][j] = 'X'
    return board 
def checkAdjacents(board, row, col):    
    Adjacents =  {'top' : [-1, 0], 'bottom' : [1, 0], 'left' : [0 ,- 1], 'right' : [0, 1]} #Positions of top, bottom, left  and right for subscripting 
    for cell in Adjacents: 
        x = row + Adjacents[cell][0] 
        y = col + Adjacents[cell][1]
        try:
            checkCell = board[x][y] #Check if it is a valid space, will throw an out of range if not
        except: #Catch out of range error 
            continue
        if checkCell == 'X': #If the adjacent space is just a X
            continue 
        elif x != len(board) - 1 and x != 0 and y != len(board[0]) - 1 and y != 0 and checkCell == 'O': #If the adjacent space is a O check if it is not a boarder space 
            continue 
        else:
            return False
    return True #No adjacent cells found where the adjacent cell is on the boarder and an X 

def print_board(board):
    for i in range(len(board)):
        for j in range(len(board[0])):
            print(board[i][j], end = ' ')
        print()
if __name__ == '__main__': 
    # expected =
    #        [["O","X","X","O","X"],
    #         ["X","X","X","X","O"],
    #         ["X","X","X","O","X"],
    #         ["O","X","O","O","O"],
    #         ["X","X","O","X","O"]]

    board =[["O","X","X","O","X"],
            ["X","O","O","X","O"],
            ["X","O","X","O","X"],
            ["O","X","O","O","O"],
            ["X","X","O","X","O"]]
    updated_board = surround_regions(board)
    print_board(updated_board)
    # print(updated_board)
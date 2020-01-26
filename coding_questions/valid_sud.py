import math 
def check_board(board): 
    col = len(board[0])
    row = len(board)
    if col % 3 != 0 or row % 3 != 0: #Invalid Spaced Board
        return False 
    x = 0 
    y = 0 
    iterations  = int(col / 3 * row / 3)
    for i  in range(iterations):
        sub_board = []
        for _ in range(3):
            y = i // 3 * 3
            for _ in range(3):
                print("x = ", x, " y = ", y, "point", board[y][x])
                if board[y][x] != ".":
                    sub_board.append(board[y][x])
                    up = 0 
                    for j in board[y]:
                        if board[y][x] == j:
                            up += 1 
                    down = 0 
                    for k in range(len(board)):
                        if board[y][x] == board[k][x]: 
                            down += 1 
                    if up == 2 or down == 2:
                        return False
                y += 1 
            x += 1
        if len(set(sub_board)) == len(sub_board):
            if x == col: #Check if  moving to bottom sub_boards 
                x = 0 
        else:
            return False
    return True 

if __name__ == '__main__':
    inpt = [[".",".","4",".",".",".","6","3","."],
     [".",".",".",".",".",".",".",".","."],
     ["5",".",".",".",".",".",".","9","."],
     [".",".",".","5","6",".",".",".","."],
     ["4",".","3",".",".",".",".",".","1"],
     [".",".",".","7",".",".",".",".","."],
     [".",".",".","5",".",".",".",".","."],
     [".",".",".",".",".",".",".",".","."],
     [".",".",".",".",".",".",".",".","."]]
    valid = check_board(inpt)
    print(valid)
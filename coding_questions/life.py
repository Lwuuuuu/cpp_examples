def GoL(board): 
    row = len(board)
    col = len(board[0])
    visited_board = [[0] * col for _ in range(row)]
    for i in range(row):
        for j in range(col):
            cell_status = board[i][j]
            alive = check_neighbors(board, i, j)
            if cell_status == 1 and alive < 2: 
                visited_board[i][j] = 1
            elif cell_status == 1 and alive > 3: 
                visited_board[i][j] = 1
            elif cell_status == 0 and alive == 3: 
                visited_board[i][j] = 1 
    for i in range(row):
        for j in range(col):
            if visited_board[i][j] == 1: 
                if board[i][j] == 0: 
                    board[i][j] = 1 
                else: 
                    board[i][j] = 0
    return board
    
                

def check_neighbors(board, row, col): 
    neigh = {'t' : [-1, 0], 'b' : [1, 0], 'l' : [0, -1], 'r' : [0, 1], 'tl' : [-1, -1], 'tr' : [-1, 1], 'bl' : [1, -1], 'br' : [1, 1]}
    alive = 0 
    for key in neigh:  
        neighbor_row = row  + neigh[key][0]
        neighbor_col = col + neigh[key][1]
        if neighbor_row > len(board) - 1 or neighbor_row < 0 or neighbor_col > len(board[0]) - 1 or neighbor_col < 0: 
            continue 
        else:
            neighbor_cell = board[neighbor_row][neighbor_col]
            if neighbor_cell == 1:
                alive += 1 
    return alive

if __name__ == '__main__': 
    board = [[0,1,0],
            [0,0,1],
            [1,1,1],
            [0,0,0]
            ]
    res = GoL(board)
    for i in range(len(res)):
        print(res[i])
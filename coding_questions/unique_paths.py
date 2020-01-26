def uniquePaths(m, n):
    #m is number of rows, n is number of columns 
    if m == 1 or n == 1: return 1
    return sub_path(1, 1, m, n) 
    
def sub_path(x, y, m, n): 
    if n == x and m == y:
        return 1 
    if x > n or y >  m: 
        return 0
    return sub_path(x+1, y, m, n) + sub_path(x, y+1, m, n)

if __name__ == '__main__': 
    m = 3
    n = 2 
    print(uniquePaths(m, n))
def flight_booking(bookings, n): 
    res = [0] * n 
    for i in range(len(bookings)): 
        seats  = bookings[i][-1]
        start = bookings[i][0]
        end = bookings[i][1] 
        res[start - 1] += seats 
        if end < n: 
            res[end] -= seats
    print(res)
    for j in range(1, n):
        res[j] += res[j - 1] 
    return res 

if __name__ == '__main__': 
    bookings = [[1,2,10],[2,3,20],[2,5,25]]
    n = 5 
    print(flight_booking(bookings, n))
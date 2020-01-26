def circularArrayLoop(nums):
    if len(nums) < 2 or nums[0] == 0: return False 
    MAX_INDEX = len(nums) - 1
    current_index = 0 
    visited_index = [0]
    while 1: 
        if current_index + nums[current_index] > MAX_INDEX:
            current_index = current_index + nums[current_index] - MAX_INDEX - 1
        elif current_index + nums[current_index] < 0: 
            back = abs(current_index - abs(nums[current_index])) 
            current_index = MAX_INDEX - back + 1 
        else:
            current_index += nums[current_index]
        visited_index.append(current_index)
        if len(list(set(visited_index))) != len(visited_index): #Cycle may have occured check if forward or backwards moving
            cycled_index = visited_index[-1]
            del visited_index[-1]
            starting_index = visited_index.index(cycled_index)
            cycles = 0
            print("Visited Index", visited_index, "Starting Index", starting_index)
            if nums[starting_index] > 0: #Going Forward
                # print("going forward at starting point", starting_index)
                for i in range(starting_index, len(visited_index)):
                    cycles += 1 
                    if nums[visited_index[i]] < 0: #Index i s going backwards
                        return False 
                if cycles ==  1 : 
                    return False
                else:
                    return True 
            else:
                for i in range(starting_index, len(visited_index)):
                    cycles += 1 
                    if nums[visited_index[i]] > 0: 
                        return False 
                if cycles ==  1 : 
                    return False
                else:
                    return True  

                    
if __name__ == '__main__':
    inpt = [3,1,2]
    print(circularArrayLoop(inpt))

    # [-3, 2]
    # [3, 2]
    # [0, 2, 3, 1, 0]
    #
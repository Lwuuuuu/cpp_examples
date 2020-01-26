def hamming(nums): 
    bin_nums = [bin(val)[2:] for val in nums]
    sum = 0
    for i in range(len(nums)): 
        for j in range(i, len(nums)):
            if i != j:
                difference = len(bin_nums[i]) - len(bin_nums[j])
                if difference > 0: #bin_nums[i] bigger than big_nums[j]
                    for _ in range(difference): bin_nums[j] = '0' + bin_nums[j]
                elif difference < 0: 
                    for _ in range(abs(difference)): bin_nums[i] = '0' + bin_nums[i]
                for x, y in zip(bin_nums[i], bin_nums[j]): 
                    if x != y: 
                        sum += 1

    return sum 

            
                
if __name__ == '__main__': 
    inpt = [4, 14, 2]
    print(hamming(inpt))
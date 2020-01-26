def remove_adj(word, k): 
    notDone = True  
    while notDone: 
        print("New Iteration", word)
        searchChar = word[0] 
        counter = 0
        for i in range(len(word)):
            if word[i] == searchChar: 
                print("Matching", searchChar, word[i], i)
                counter += 1 
                if counter == k: 
                    word = word[:i -k + 1] + word[i + 1:]
                    break 
            else: 
                searchChar = word[i]
                counter = 1
            if i == len(word) - 1:
                notDone = False
    return word

    


if __name__ == '__main__': 
    inpt = "yfttttfbbbbnnnnffbgffffgbbbbgssssgthyyyy"
    k = 4
    print(remove_adj(inpt, k))
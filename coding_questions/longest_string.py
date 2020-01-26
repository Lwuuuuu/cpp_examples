from collections import defaultdict
def maxScore(A):
    string_dict = defaultdict(list)
    for string in A: 
        string_dict[len(string)].append(string)
    cur_max = 0 
    for i in range(len(A)): 
        string_chain = findChain(string_dict, A[i])
        if string_chain > cur_max: cur_max = string_chain 
    return cur_max + 1
def findChain(string_dict, word):
    word_length = len(word)
    if word_length == max(string_dict.keys()):
        return 0
    word_choices = string_dict[word_length + 1]
    high_length = 0 
    for pot_word in word_choices: 
        valid = False
        for i in range(len(pot_word)): 
            check = pot_word[:i] + pot_word[i+1:]
            if check == word: 
                valid = True
        if valid == True: 
            print(word, pot_word)
            word_max = 1 + findChain(string_dict, pot_word)
            if word_max > high_length:
                high_length = word_max 
    return high_length 
if __name__ == '__main__': 
    ipt = ["qyssedya","pabouk","mjwdrbqwp","vylodpmwp","nfyqeowa","pu","paboukc","qssedya","lopmw","nfyqowa","vlodpmw","mwdrqwp","opmw","qsda","neo","qyssedhyac","pmw","lodpmw","mjwdrqwp","eo","nfqwa","pabuk","nfyqwa","qssdya","qsdya","qyssedhya","pabu","nqwa","pabqoukc","pbu","mw","vlodpmwp","x","xr"]
    print(maxScore(ipt))
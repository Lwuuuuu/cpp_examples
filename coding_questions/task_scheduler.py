from collections import defaultdict 
from collections import deque 
def scheduler(tasks, n): 
    if len(tasks) == 0: return 0 
    if n == 0: return len(tasks)
    schedule_dict = defaultdict(int)
    res = [] 
    for i in range(len(tasks)):
        schedule_dict[tasks[i]] += 1 
    current = 0 
    cooldown = deque() 
    while current != len(tasks): 
        current_top = most_task(schedule_dict, cooldown) #Will output ['', 0] if could not find a task to put in 
        if current_top[0] == 'idle': 
            res.append(current_top[0])
        else:
            schedule_dict[current_top[0]] -= 1 
            res.append(current_top[0])
            current += 1 
        if len(cooldown) == n: 
            cooldown.pop()
        cooldown.appendleft(current_top[0])
    return len(res)
def most_task(schedule_dict, cooldown): 
    print(cooldown)
    most_task = ['idle', 0] 
    schedule_set = set(schedule_dict.keys()) - set(cooldown)
    for key in schedule_set: 
        if schedule_dict[key] > most_task[1]: 
            most_task = [key, schedule_dict[key]]
    return most_task


if __name__ == '__main__': 
    tasks = ["A","A","A","B","B","B"]
    n = 2
    print(scheduler(tasks, n))
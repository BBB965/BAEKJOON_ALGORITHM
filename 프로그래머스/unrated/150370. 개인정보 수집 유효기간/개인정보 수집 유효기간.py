def solution(today, terms, privacies):
    answer = []
    term = dict()
    
    for temp in terms:
        temp = temp.split()
        term[temp[0]] = int(temp[1]) * 28
    
    year, month, day = map(int, today.split("."))
    days = year * 12 * 28 + month * 28 + day
    
    for i in range(len(privacies)):
        privacy = privacies[i].split()
        year, month, day = map(int, privacy[0].split("."))
        if days >= year * 12 * 28 + month * 28 + day + term[privacy[1]]:
            answer.append(i+1)
        
    return answer
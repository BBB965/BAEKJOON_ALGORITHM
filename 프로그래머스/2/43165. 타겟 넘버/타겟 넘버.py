def solution(numbers, target):
    global answer
    answer = 0
    def dfs(n,o):
        global answer
        if n == len(numbers):
            if (o == target):
                answer += 1
            return
        
        dfs(n+1, o + numbers[n])
        dfs(n+1, o - numbers[n])
        return
    
    dfs(0,0)
    return answer
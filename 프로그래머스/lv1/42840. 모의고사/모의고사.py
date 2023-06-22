def solution(answers):
    answer = []
    shoot = [[1,2,3,4,5],[2,1,2,3,2,4,2,5],[3,3,1,1,2,2,4,4,5,5]]
    idx = [0] * 3
    score = {0 : 0, 1 : 0, 2 : 0}
    for ans in answers:
        for i in range(3):
            if idx[i] >= len(shoot[i]):
                idx[i] = 0
            if shoot[i][idx[i]] == ans:
                score[i] += 1
            idx[i] += 1
    dic = sorted(score.items(), key = lambda x: (-x[1], x[0]))
    score_max = dic[0][1]
    for i in dic:
        if i[1] == score_max:
            answer.append(i[0] + 1)
        else:
            break
    answer.sort()
    return answer
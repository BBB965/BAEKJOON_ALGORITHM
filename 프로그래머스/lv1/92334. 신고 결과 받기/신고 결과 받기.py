def solution(id_list, report, k):
    answer = []
    name = dict()
    check = dict()
    report = list(set(report))
    
    for userId in id_list:
        name[userId] = 0
        check[userId] = 0
    
    for users in report:
        reporter, reported = users.split(" ")
        name[reported] += 1
    
    for userss in report:
        reporter, reported = userss.split(" ")
        if name[reported] >= k:
            check[reporter] += 1
    
    for usee in id_list :
        answer.append(check[usee])
    
    return answer
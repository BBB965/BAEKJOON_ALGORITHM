import heapq

def solution(operations):
    answer = []
    pq = []
    for oper in operations:
        N, M = oper.split()
        M = int(M)
        if N == 'I':
            heapq.heappush(pq, M)
        elif M == 1 and len(pq) != 0:
            pq.pop(-1)
        elif M == -1 and len(pq) != 0:
            heapq.heappop(pq)
    
    if len(pq) == 0:
        answer = [0,0]
    else:
        maxx = max(pq)
        answer = [maxx, pq[0]]
    return answer
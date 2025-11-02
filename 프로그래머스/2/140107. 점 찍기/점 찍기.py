import math

def solution(k, d):
    summ = 0

    for y in range(0, d + 1, k):
        x = d ** 2 - y ** 2
        cnt = math.sqrt(x) // k + 1
        summ += cnt

    return summ
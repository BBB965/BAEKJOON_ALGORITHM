def solution(nums):
    answer = 0
    mon = len(set(nums))
    N = len(nums) // 2
    if N > mon:
        answer = mon
    else:
        answer = N
    return answer
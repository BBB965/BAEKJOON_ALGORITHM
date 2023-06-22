def solution(brown, yellow):
    answer = []
    height = 1
    width = yellow
    while height <= width:
        while yellow % height != 0:
            height += 1
        width = yellow // height
        temp = 2 * (width + height + 2)
        if temp == brown :
            break
        height += 1
        
    answer.append(width + 2)
    answer.append(height + 2)
    return answer
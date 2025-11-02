def solution(video_len, pos, op_start, op_end, commands):
    answer = ''
    vm, vs = video_len.split(':')
    v = int(vm) * 60 + int(vs)
    
    pm, ps = pos.split(':')
    p = int(pm) * 60 + int(ps)
    
    opsm, opss = op_start.split(':')
    ops = int(opsm) * 60 + int(opss)
    
    opem, opes = op_end.split(':')
    ope = int(opem) * 60 + int(opes)
    
    if p >= ops and p < ope:
        p = ope
    
    for i in commands:
        if i == "next":
            if p + 10 <= v:
                p += 10
            else:
                p = v
        else:
            if p - 10 >= 0:
                p -= 10
            else:
                p = 0
        
        if p >= ops and p < ope:
            p = ope
    
    m = p//60
    if m < 10:
        answer += '0' + str(m) + ':'
    else:
        answer += str(m) + ':'
    s = p%60
    if s < 10:
        answer += '0' + str(s)
    else:
        answer += str(s)
    
    return answer
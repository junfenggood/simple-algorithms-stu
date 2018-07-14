#coding=utf-8
import sys
def cal_7_pluse(x,y, last=0):
    x = int(x)
    y = int(y)
    sum = x + y + last
    if sum > 6:
        tail = sum % 7
        return 1, tail
    else:
        return 0, sum

def array_plus(first, last):
    temp = []
    last_value = 0
    temp_list = zip(first, last)
    for i in xrange(len(temp_list)-1, -1, -1):
        x, y = temp_list[i]
        x = int(x)
        y = int(y)
        last_value,result=cal_7_pluse(x,y,last_value)
        temp.insert(0, result)
    return temp, last_value

if __name__ == "__main__":
    # 读取第一行的n
    n = sys.stdin.readline().strip()
    if "7" in n or "8" in n or "9" in n:
        sys.exit(-1)
    temp = n.split(' ')
    first = temp[0]
    second = temp[1]
    len_a = len(first)
    len_b = len(second)
    min_len = min(len_a, len_b)

    if len_b == len_a:
        temp, last_value = array_plus(list(first), list(second))
        if last_value == 1:
            temp.insert(0,1)


    elif len_a == min_len:
        temp, last_value = array_plus(list(first),list(second[len_b-min_len:]))
        if last_value == 1:
            last_value, result=cal_7_pluse(int(second[len_b-min_len-1]),1)
            temp.insert(0,result)
            if last_value == 1:
                if len_b-min_len-2 < 0:
                    temp.insert(0, 1)
                else:
                    for i in range(len_b-min_len-2, -1, -1):
                        temp.insert(0, int(second[i]))
            else:
                for i in range(len_b-min_len-2, -1, -1):
                    temp.insert(0, int(second[i]))
        else:
            for i in range(len_b-min_len-1, -1, -1):
                temp.insert(0, int(second[i]))

    else:
        temp, last_value = array_plus(list(first[len_a-min_len:]),list(second))
        if last_value == 1:
            last_value, result=cal_7_pluse(int(first[len_a-min_len-1]),1)
            temp.insert(0,result)
            if last_value == 1:
                if len_a-min_len-2 < 0:
                    temp.insert(0, 1)
                else:
                    for i in range(len_a-min_len-2, -1, -1):
                        temp.insert(0, int(first[i]))
            else:
                for i in range(len_a-min_len-2, -1, -1):
                    temp.insert(0, int(first[i]))
        else:
            for i in range(len_a-min_len-1, -1, -1):
                temp.insert(0, int(first[i]))
    we = [str(x) for x in temp]
    print ''.join(we)

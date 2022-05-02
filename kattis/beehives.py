import math


def distance(x1, y1, x2, y2):
    val = (x2-x1)**2 + (y2-y1)**2
    return math.sqrt(val)


def beehives(d, N):
    points = {}
    is_sour = {}
    sweet = sour = 0
    itr = N
    while itr > 0:
        x, y = [float(x) for x in input().split()]
        idx1 = str(x)+str(y)
        if idx1 not in is_sour.keys():
            is_sour[idx1] = False
        for x2, y2 in points.items():
            dist = distance(x, y, x2, y2)
            idx2 = str(x2)+str(y2)
            if idx1 == idx2:
                sour += 1
                break
            if idx2 not in is_sour.keys():
                is_sour[idx2] = False
            if dist < d and dist != 0:
                if not is_sour[idx1]:
                    sour += 1
                    is_sour[idx1] = True
                if not is_sour[idx2]:
                    sour += 1
                    is_sour[idx2] = True
        if not is_sour[idx1] and points:
            sweet += 1
        points[x] = y
        itr -= 1
    return str(sour) + " sour, " + str(sweet) + " sweet\n"


def main():
    d, N = [float(x) for x in input().split()]
    ret_str = ''
    while d != 0 and N != 0:
        ret_str += beehives(d, N)
        d, N = [float(x) for x in input().split()]
    print(ret_str[:len(ret_str)-1])


if __name__ == "__main__":
    main()

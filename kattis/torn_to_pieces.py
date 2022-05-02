def main():
    N = int(input())
    stations = {}
    while N > 0:
        vals = input().split()
        stations[vals[0]] = []
        for i in range(1, len(vals)):
            stations[vals[0]].append(vals[i])
        N -= 1
    start, end = input().split()
    print(stations)
    print("-----------")
    if end in stations[start]:
        print(stations[start], stations[end], 'here')
        return
    else:
        temp = [start]
        for val in stations[start]:
            if val == end:
                print(start, end)
            if val not in temp:
                temp.append(val)
            for val_2 in stations[val]:
                if val_2 == end:
                    temp.append(val_2)
                    break
        if len(temp) == 1:
            print("no route found")
        else:
            for val in temp:
                print("here")
                print(val, end=" ")
        print()


if __name__ == "__main__":
    main()

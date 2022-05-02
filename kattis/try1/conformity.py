def main():
    n = int(input())
    values = {}
    itr = n
    while itr > 0:
        temp = input().split()
        temp.sort()
        value = str(temp)
        if value not in values.keys():
            values[value] = 1
        else:
            values[value] += 1
        itr -= 1
    if values:
        if max(values.values()) <= 1:
            print(n)
        else:
            print(max(values.values()))


if __name__ == "__main__":
    main()

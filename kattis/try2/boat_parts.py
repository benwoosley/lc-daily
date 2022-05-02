def main():
    num_parts, num_days = [int(x) for x in input().split()]
    values = []
    itr = num_days
    val = 0
    temp_val = num_parts
    while itr > 0:
        if num_parts == 0:
            val = num_days - itr
        temp = input()
        if temp not in values:
            values.append(temp)
            num_parts -= 1
            values.append(temp)
        itr -= 1

    if num_parts > 0:
        print('paradox avoided')
        return
    if val > 0:
        print(val)
    elif val == 0:
        print(temp_val)


if __name__ == "__main__":
    main()

def main():
    N = int(input())
    people = []
    while N > 0:
        people.append(input())
        N -= 1

    test_list = people[:]
    test_list.sort()
    if test_list == people:
        print('INCREASING')
    elif test_list == people[::-1]:
        print("DECREASING")
    else:
        print("NEITHER")


if __name__ == "__main__":
    main()

def main():
    S = int(input())
    print("%d:" % S)
    # values
    # 0, 0
    # 1, 0
    # 1, 1
    #
    has_printed = []
    for i in range(2, S):
        for j in range(i-1, i+1):
            val_1 = 1
            val_2 = 1
            while i*val_1 + j*val_2 <= S:
                for val_1 in range(1, S):
                    for val_2 in range(val_1-1, val_1+1):
                        if i*val_1 + j*val_2 == S and not str(i) + str(j) in has_printed:
                            if i == 2 and j == 1:
                                print("%d,%d" % (i, j))
                                print(val_1, val_2)
                            has_printed.append(str(i)+str(j))
                            break


if __name__ == "__main__":
    main()

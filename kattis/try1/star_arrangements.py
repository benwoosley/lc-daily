def main():
    S = 100000
    print("%d:" % S)
    for i in range(2, (S//2)+2):
        for j in range(i-1, i+1):
            if i + j == S:
                print("%d,%d" % (i, j))
                break
            else:
                for k in range(1, (S//2)+1):
                    if i*k + j*(k-1) == S or i*k + j*k == S:
                        print("%d,%d" % (i, j))
                        break
                    elif i*k + j*k > S:
                        break


if __name__ == "__main__":
    main()

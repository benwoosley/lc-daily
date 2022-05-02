def main():
    N = int(input())
    count = 1
    blocks = [int(x) for x in input().split()]
    for i in range(0, len(blocks)-1):
        if blocks[i] < blocks[i+1]:
            count += 1
    print(count)


if __name__ == "__main__":
    main()

def main():
    n, m, k = [int(x) for x in input().split()]
    applicants = []
    for x in input().split():
        applicants.append(int(x))
    apartments = []
    for x in input().split():
        apartments.append(int(x))
    apartments.sort()
    applicants.sort()

    count = 0
    p1 = p2 = 0
    while p1 < m and p2 < n:
        if apartments[p1] in range(applicants[p2]-k, applicants[p2]+(k+1)):
            count += 1
            p1 += 1
            p2 += 1
        elif apartments[p1] < applicants[p2]-k:
            p1 += 1
        else:
            p2 += 1
    print(count)


if __name__ == "__main__":
    main()

import math


def estimate_area(r, m, c):
    print(math.pi*r**2, (c/m)*4*r**2)


def main():
    r, m, c = [float(x) for x in input().split()]
    while r != 0 and m != 0 and c != 0:
        estimate_area(r, m, c)
        r, m, c = [float(x) for x in input().split()]


if __name__ == "__main__":
    main()

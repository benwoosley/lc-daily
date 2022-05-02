def fizz_buzz(x, y, n):
    for i in range(1, n+1):
        if i % x == 0 and i % y == 0:
            print("FizzBuzz")
        elif i % x == 0:
            print("Fizz")
        elif i % y == 0:
            print("Buzz")
        else:
            print(i)


def main():
    x, y, n = map(int, input().split())
    fizz_buzz(x, y, n)


if __name__ == "__main__":
    main()

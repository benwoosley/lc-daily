def babelfish_2(values, N):
    for _ in range(0, N):
        try:
            val = input()
            if val in values.keys():
                print(values[val])
            else:
                print('eh')
        except EOFError:
            return


def babelfish():
    try:
        in_val = input()
        values = {}
        N = 0
        while in_val != "":
            value, key = in_val.split()
            values[key] = value
            in_val = input()
            N += 1
        babelfish_2(values, N)
    except EOFError:
        return


def main():
    try:
        babelfish()
    except EOFError:
        return


if __name__ == "__main__":
    main()

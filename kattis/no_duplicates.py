def no_duplicates(words):
    for i, word in enumerate(words):
        if word in words[i+1:]:
            print("no")
            return
    print("yes")


def main():
    vals = input().split()
    no_duplicates(vals)


if __name__ == "__main__":
    main()

def hangman(characters, guesses):
    i = 0
    while characters:
        for guess in guesses:
            if i >= 10 and characters:
                print("LOSE")
                return
            if guess not in characters:
                i += 1
            while guess in characters:
                characters.remove(guess)
    print("WIN")


def main():
    line_1 = input()
    characters = []
    for c in line_1:
        characters.append(c)

    line_2 = input()
    guesses = []
    for c in line_2:
        guesses.append(c)

    hangman(characters, guesses)

    pass


if __name__ == "__main__":
    main()

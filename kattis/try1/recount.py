def main():
    candidate = input()
    votes = {}
    while candidate != "***":
        if candidate not in votes.keys():
            votes[candidate] = 1
        else:
            votes[candidate] += 1
        candidate = input()

    if list(votes.values()).count(max(votes.values())) > 1:
        print("Runoff!")
    else:
        maximum = 0
        winner = ''
        for vote in votes:
            if votes[vote] > maximum:
                winner = vote
                maximum = votes[vote]
        print(winner)


if __name__ == "__main__":
    main()

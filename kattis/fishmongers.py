def main():
    fish_to_sell, fishmongers = [int(x) for x in input().split()]
    weights = []
    for x in input().split():
        weights.append(int(x))
    while fishmongers > 0:
        num_fish, price_per_kg = [int(x) for x in input().split()]
        fishmongers -= 1


if __name__ == "__main__":
    main()

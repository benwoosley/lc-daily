def main():
    num_instruments, num_notes = [int(x) for x in input().split()]
    num_notes -= 1
    instrument_dict = {}
    for i in range(0, num_instruments):
        instrument_dict[i] = []
        for x in input().split():
            instrument_dict[i].append(int(x))
        instrument_dict[i].pop(0)
    curr = 0
    swaps = 0
    for x in input().split():
        has_visited = False
        while int(x) not in instrument_dict[curr]:
            has_visited = True
            if curr >= len(instrument_dict)-1:
                curr = 0
            else:
                curr += 1
        if has_visited:
            swaps += 1
    print(swaps)


if __name__ == "__main__":
    main()

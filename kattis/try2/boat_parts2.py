def main():
    num_parts, num_days = [int(x) for x in input().split()]
    parts = []
    for i in range(0, num_days):
        part = input()
        if part not in parts:
            parts.append(part)
        if len(parts) == num_parts:
            print(i+1)
            return

    if len(parts) == num_parts:
        print(num_parts)
    else:
        print("paradox avoided")


if __name__ == "__main__":
    main()

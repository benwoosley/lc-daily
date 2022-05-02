def main():
    num_testcases = int(input())
    while num_testcases > 0:
        num_candidates = int(input())
        total_votes = 0
        max_val = 0
        max_candidates = []
        values = []
        for i in range(1, num_candidates+1):
            num_votes = int(input())
            total_votes += num_votes
            if num_votes > max_val:
                max_val = num_votes
                max_candidates.append(i)
            if num_votes == max_val:
                values.append(num_votes)
        values.remove(max_val)
        if max_val in values:
            print("no winner")
        elif max_val > total_votes // 2:
            print("majority winner", max_candidates[len(max_candidates)-1])
        elif max_val == total_votes // 2:
            print("minority winner", max_candidates[len(max_candidates)-1])
        num_testcases -= 1


if __name__ == "__main__":
    main()

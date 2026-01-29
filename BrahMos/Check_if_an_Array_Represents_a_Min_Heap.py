def solver(arr) -> bool:
    n = len(arr)

    for i in range(n//2):
        L_child = 2*i + 1
        R_child = 2*i + 2

        if L_child < n and arr[L_child] > arr[i]:
            return False

        if R_child < n and arr[R_child] > arr[i]:
            return False

    return True


if __name__ == "__main__":
    arr = [50, 30, 40, 10, 20, 35, 37]
    print(solver(arr))   # True

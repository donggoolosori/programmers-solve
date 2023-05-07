def solution(park, routes):
    n, m = len(park), len(park[0])
    y, x = get_start(park, n, m)
    # 방위에 따른 방향벡터 정의
    dirs = ["N", "E", "S", "W"]
    dy, dx = [-1, 0, 1, 0], [0, 1, 0, -1]
    dir_to_vec = {dirs[i]: vec for i, vec in enumerate(zip(dy, dx))}

    for route in routes:
        op, d = route.split()
        d = int(d)
        dy, dx = dir_to_vec[op]
        ny, nx = y + dy * d, x + dx * d
        if ny < 0 or nx < 0 or ny >= n or nx >= m or park[ny][nx] == "X":
            continue
        flag = False
        for i in range(1, d + 1):
            if park[y + dy * i][x + dx * i] == "X":
                flag = True
                break
        if flag:
            continue
        y, x = ny, nx

    return [y, x]


def get_start(park, n, m):
    for i in range(n):
        for j in range(m):
            if park[i][j] == "S":
                return i, j
    return 0, 0

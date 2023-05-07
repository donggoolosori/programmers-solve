class Dog:
    def __init__(self, y, x):
        self.y, self.x = y, x
        self.dy, self.dx = [-1, 0, 1, 0], [0, 1, 0, -1]
        self.dirs = ["N", "E", "S", "W"]
        self.dir_to_vec = {
            self.dirs[i]: vec for i, vec in enumerate(zip(self.dy, self.dx))
        }

    def get_pos(self):
        return self.y, self.x

    def move(self, park, op, d):
        dy, dx = self.dir_to_vec[op]

        if not self.can_go(park, dy, dx, d):
            return

        self.y, self.x = self.next_pos(dy, dx, d)

    def can_go(self, park, dy, dx, d):
        ny, nx = self.next_pos(dy, dx, d)
        n, m = len(park), len(park[0])

        if ny < 0 or nx < 0 or ny >= n or nx >= m or park[ny][nx] == "X":
            return False
        for i in range(1, d + 1):
            if park[self.y + dy * i][self.x + dx * i] == "X":
                return False

        return True

    def next_pos(self, dy, dx, d):
        return self.y + dy * d, self.x + dx * d


def get_start_pos(park):
    n, m = len(park), len(park[0])
    for i in range(n):
        for j in range(m):
            if park[i][j] == "S":
                return i, j
    return 0, 0


def solution(park, routes):
    y, x = get_start_pos(park)
    dog = Dog(y, x)

    for route in routes:
        op, d = route.split()
        d = int(d)

        dog.move(park, op, d)

    return list(dog.get_pos())

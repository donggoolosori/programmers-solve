function solution(grid) {
  const dy = [-1, 0, 1, 0],
    dx = [0, 1, 0, -1];
  const r = grid.length,
    c = grid[0].length;

  const check = Array.from({ length: r }, () =>
    Array.from({ length: c }, () => [0, 0, 0, 0])
  );

  const ans = [];

  for (let i = 0; i < r; i++) {
    for (let j = 0; j < c; j++) {
      for (let k = 0; k < 4; k++) {
        if (check[i][j][k]) continue;

        let y = i,
          x = j,
          d = k,
          dist = 0;
        while (true) {
          if (check[y][x][d] === 1) break;

          check[y][x][d] = 1;

          let ny = y + dy[d],
            nx = x + dx[d];

          if (ny < 0) ny = r - 1;
          if (nx < 0) nx = c - 1;
          if (ny >= r) ny = 0;
          if (nx >= c) nx = 0;

          (y = ny), (x = nx);
          d = getNextDirection(grid[ny][nx], d);

          dist++;
        }
        ans.push(dist);
      }
    }
  }

  return ans.sort((a, b) => a - b);
}

function getNextDirection(grid, d) {
  switch (grid) {
    case 'L':
      return d - 1 < 0 ? 3 : d - 1;
    case 'R':
      return (d + 1) % 4;
    default:
      return d;
  }
}

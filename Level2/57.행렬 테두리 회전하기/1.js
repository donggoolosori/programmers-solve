function solution(rows, columns, queries) {
  const matrix = Array.from({ length: rows + 1 }, () =>
    Array.from({ length: columns + 1 }, () => 0)
  );

  const ans = [];

  for (let i = 1; i <= rows; i++) {
    for (let j = 1; j <= columns; j++) {
      matrix[i][j] = (i - 1) * columns + j;
    }
  }

  function rotate(sy, sx, ey, ex) {
    let next = matrix[sy][sx];
    let ret = next;
    // top
    for (let x = sx + 1; x <= ex; x++) {
      const temp = matrix[sy][x];
      matrix[sy][x] = next;
      next = temp;
      ret = Math.min(ret, next);
    }
    // right
    for (let y = sy + 1; y <= ey; y++) {
      const temp = matrix[y][ex];
      matrix[y][ex] = next;
      next = temp;
      ret = Math.min(ret, next);
    }
    // bottom
    for (let x = ex - 1; x >= sx; x--) {
      const temp = matrix[ey][x];
      matrix[ey][x] = next;
      next = temp;
      ret = Math.min(ret, next);
    }
    // left
    for (let y = ey - 1; y >= sy; y--) {
      const temp = matrix[y][sx];
      matrix[y][sx] = next;
      next = temp;
      ret = Math.min(ret, next);
    }

    return ret;
  }

  queries.forEach((query) => {
    ans.push(rotate(...query));
  });

  return ans;
}

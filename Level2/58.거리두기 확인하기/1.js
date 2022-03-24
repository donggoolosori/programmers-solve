function solution(places) {
  return places.map((place) => {
    return isGoodDist(place);
  });
}

function isGoodDist(place) {
  for (let i = 0; i < 5; i++) {
    for (let j = 0; j < 5; j++) {
      if (place[i][j] !== 'P') continue;

      if (closeDist(place, i, j)) {
        return 0;
      }
    }
  }

  return 1;
}

function closeDist(place, y, x) {
  const dy = [-1, 0, 0, 1],
    dx = [0, -1, 1, 0];

  const visit = Array.from({ length: 5 }, () =>
    Array.from({ length: 5 }, () => false)
  );

  const q = [{ y, x, dist: -1 }];
  visit[y][x] = true;

  while (q.length > 0) {
    const { y, x, dist } = q[0];
    q.shift();

    if (dist >= 2) continue;

    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i],
        nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
      if (visit[ny][nx] || place[ny][nx] === 'X') continue;
      visit[ny][nx] = true;

      if (place[ny][nx] === 'P') {
        if (dist + 1 < 2) return true;
      } else {
        q.push({ y: ny, x: nx, dist: dist + 1 });
      }
    }
  }

  return false;
}

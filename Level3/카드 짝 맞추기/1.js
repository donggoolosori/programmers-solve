// 75점
function getFriendsAndPos(board) {
  const friends = [];
  const posMap = {};

  for (let i = 0; i < 4; i++) {
    for (let j = 0; j < 4; j++) {
      if (board[i][j] === 0) continue;
      if (friends.includes(board[i][j])) {
        posMap[board[i][j]].push({ y: i, x: j });
        continue;
      }
      friends.push(board[i][j]);
      posMap[board[i][j]] = [{ y: i, x: j }];
    }
  }

  return { posMap, friends };
}

function isValidPos(y, x) {
  return y >= 0 && x >= 0 && y < 4 && x < 4;
}

function ctrlMove(y, x, dy, dx, board) {
  let ny = y,
    nx = x;
  while (true) {
    const nny = ny + dy;
    const nnx = nx + dx;

    if (!isValidPos(nny, nnx)) return [ny, nx];

    if (board[nny][nnx]) return [nny, nnx];

    ny = nny;
    nx = nnx;
  }
}

function copyBoard(board) {
  const newBoard = Array.from({ length: 4 }, () =>
    Array.from({ length: 4 }, () => 0)
  );
  for (let i = 0; i < 4; i++) {
    for (let j = 0; j < 4; j++) {
      newBoard[i][j] = board[i][j];
    }
  }
  return newBoard;
}

function solution(board, r, c) {
  const { friends, posMap } = getFriendsAndPos(board);
  const dy = [-1, 0, 0, 1],
    dx = [0, -1, 1, 0];

  let answer = 100,
    cy = r,
    cx = c;

  function bfs(ty, tx, newBoard) {
    newBoard[cy][cx] = 0;
    const q = [],
      visit = Array.from({ length: 4 }, () => [0, 0, 0, 0]);
    q.push({ y: cy, x: cx, count: 0 });
    visit[cy][cx] = true;

    while (q.length !== 0) {
      const { y, x, count } = q[0];
      q.shift();

      if (y === ty && x === tx) {
        (cy = ty), (cx = tx);

        return count + 1;
      }

      for (let i = 0; i < 4; i++) {
        let ny = y + dy[i],
          nx = x + dx[i];
        if (!isValidPos(ny, nx)) continue;
        if (visit[ny][nx]) continue;

        visit[ny][nx] = true;
        q.push({ y: ny, x: nx, count: count + 1 });

        const [nny, nnx] = ctrlMove(ny, nx, dy[i], dx[i], newBoard);

        if (!visit[nny][nnx]) {
          visit[nny][nnx] = true;
          q.push({ y: nny, x: nnx, count: count + 1 });
        }
      }
    }

    return 0;
  }

  function calcMinCtrl(positions) {
    (cy = r), (cx = c);
    const newBoard = copyBoard(board);
    return positions.reduce((acc, pos) => acc + bfs(pos.y, pos.x, newBoard), 0);
  }

  function permutation(made, bit, L) {
    if (L === friends.length) {
      answer = Math.min(answer, calcMinCtrl(made));
      return;
    }

    for (let i = 0; i < friends.length; i++) {
      if (bit & (1 << i)) continue;

      permutation(
        [...made, posMap[friends[i]][0], posMap[friends[i]][1]],
        bit | (1 << i),
        L + 1
      );
      permutation(
        [...made, posMap[friends[i]][1], posMap[friends[i]][0]],
        bit | (1 << i),
        L + 1
      );
    }
  }

  permutation([], 0, 0);

  return answer;
}

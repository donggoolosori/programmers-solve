const dy = [0, 0, 1, 1],
  dx = [0, 1, 0, 1];

function solution(m, n, board) {
  let cnt = 0;
  board = board.map((el) => el.split(''));

  while (true) {
    const delPos = [];
    for (let i = 0; i < m - 1; i++) {
      for (let j = 0; j < n - 1; j++) {
        if (board[i][j] === ' ') continue;

        let flag = true;
        const curr = board[i][j];
        for (let k = 1; k < 4; k++) {
          const ny = i + dy[k],
            nx = j + dx[k];
          if (curr !== board[ny][nx]) {
            flag = false;
            break;
          }
        }

        if (!flag) continue;

        for (let k = 0; k < 4; k++) {
          const ny = i + dy[k],
            nx = j + dx[k];

          delPos.push({ y: ny, x: nx });
        }
      }
    }

    if (delPos.length === 0) break;

    delPos.forEach(({ y, x }) => {
      if (board[y][x] === ' ') return;
      board[y][x] = ' ';
      cnt++;
    });

    for (let j = 0; j < n; j++) {
      for (let i = m - 1; i > 0; i--) {
        if (board[i][j] !== ' ') continue;

        for (let k = i - 1; k >= 0; k--) {
          if (board[k][j] !== ' ') {
            board[i][j] = board[k][j];
            board[k][j] = ' ';
            break;
          }
        }
      }
    }
  }

  return cnt;
}

function getPicked(board, col) {
  for (let i = 0; i < board.length; i++) {
    if (board[i][col] === 0) continue;

    return { row: i, picked: board[i][col] };
  }

  return { row: undefined, picked: 0 };
}

function solution(board, moves) {
  const N = board.length;

  const bucket = [];
  let poped = 0;
  moves.forEach((move) => {
    const col = move - 1;
    const { row, picked } = getPicked(board, col);

    if (!picked) return;

    board[row][col] = 0;

    if (bucket.length && bucket[bucket.length - 1] === picked) {
      poped += 2;
      bucket.pop();
    } else {
      bucket.push(picked);
    }
  });

  return poped;
}

function solution(n) {
  let ret = 0;
  const row = [];

  function promising(col) {
    for (let i = 0; i < col; i++) {
      if (row[i] === row[col]) {
        return false;
      }
      if (col - i === Math.abs(row[col] - row[i])) {
        return false;
      }
    }

    return true;
  }

  function nqueen(col = 0) {
    if (col === n) {
      ret++;
      return;
    }

    for (let i = 0; i < n; i++) {
      row[col] = i;
      if (promising(col)) {
        nqueen(col + 1);
      }
    }
  }

  nqueen();

  return ret;
}

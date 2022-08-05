function to124(n) {
  return n === 0 ? '' : to124(parseInt((n - 1) / 3)) + [1, 2, 4][(n - 1) % 3];
}

function solution(n) {
  return to124(n);
}

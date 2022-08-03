function solution(a, b) {
  return a.reduce((acc, num, idx) => acc + num * b[idx], 0);
}

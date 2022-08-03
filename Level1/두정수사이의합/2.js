function solution(a, b) {
  if (a === b) return a;

  const len = Math.abs(b - a) + 1;

  if (len % 2 === 0) {
    return (len / 2) * (a + b);
  }

  return (a + b) / 2 + Math.floor(len / 2) * (a + b);
}

function solution(n, s) {
  const base = (s / n) >> 0;

  if (base === 0) return [-1];

  const rest = s % n;

  const ret = Array.from({ length: n }, () => base);

  for (let i = 0; i < rest; i++) {
    ret[n - 1 - i]++;
  }

  return ret;
}

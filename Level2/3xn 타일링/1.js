function solution(n) {
  const MOD = 1e9 + 7;
  const cache = Array.from({ length: n + 1 }, () => -1);

  (cache[0] = 1), (cache[1] = 0), (cache[2] = 3);

  for (let i = 3; i <= n; i++) {
    cache[i] = 3 * cache[i - 2];
    for (let j = 4; j <= i; j += 2) {
      cache[i] += 2 * cache[i - j];
    }
    cache[i] %= MOD;
  }

  return cache[n];
}

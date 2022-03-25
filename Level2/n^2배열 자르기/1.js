function solution(n, left, right) {
  const ans = [];

  for (let i = left; i <= right; i++) {
    const y = parseInt(i / n),
      x = i % n;

    ans.push(Math.max(y + 1, x + 1));
  }

  return ans;
}

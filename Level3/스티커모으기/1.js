function solution(sticker) {
  const n = sticker.length;
  if (n === 1) return sticker[0];

  const dp1 = Array.from({ length: n }, () => 0);
  const dp2 = Array.from({ length: n }, () => 0);

  dp1[0] = sticker[0];
  dp1[1] = sticker[0];

  dp2[0] = 0;
  dp2[1] = sticker[1];

  let max1 = dp1[0],
    max2 = dp2[1];
  for (let i = 2; i < n - 1; i++) {
    dp1[i] = Math.max(dp1[i - 2] + sticker[i], dp1[i - 1]);
    max1 = Math.max(max1, dp1[i]);
  }

  for (let i = 2; i < n; i++) {
    dp2[i] = Math.max(dp2[i - 2] + sticker[i], dp2[i - 1]);
    max2 = Math.max(max2, dp2[i]);
  }

  return Math.max(max1, max2);
}

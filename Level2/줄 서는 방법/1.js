function solution(n, k) {
  const dp = Array.from({ length: 21 }, () => -1);

  function factorial(n) {
    if (n === 1) return 1;

    if (dp[n] !== -1) return dp[n];

    return (dp[n] = n * factorial(n - 1));
  }

  const nums = Array.from({ length: n }, (_, idx) => idx + 1);
  const ret = [];

  let nth = k - 1;
  for (let i = n; i >= 1; i--) {
    if (k === 1) {
      ret.push(...nums);
      break;
    }
    const idx = (nth / factorial(i - 1)) >> 0;
    nth %= factorial(i - 1);
    ret.push(nums[idx]);
    nums.splice(idx, 1);
  }

  return ret;
}

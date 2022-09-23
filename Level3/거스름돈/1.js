function solution(n, money) {
  const MOD = 1e9 + 7;

  const dp = Array.from({ length: n + 1 }, () => 0);

  dp[0] = 1;

  for (let i = 0; i < money.length; i++) {
    for (let j = money[i]; j <= n; j++) {
      dp[j] += dp[j - money[i]];
    }
  }

  return dp[n];
}

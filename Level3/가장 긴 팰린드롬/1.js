function solution(s) {
  const n = s.length;
  const dp = Array.from({ length: n }, () =>
    Array.from({ length: n }, () => -1)
  );

  function palindrome(l, r) {
    if (l > r) return 0;
    if (l === r) return 1;
    if (r - l === 1 && s[l] === s[r]) return 2;

    if (dp[l][r] !== -1) return dp[l][r];

    if (s[l] === s[r] && palindrome(l + 1, r - 1) === r - l - 1) {
      return (dp[l][r] = r - l + 1);
    }

    return (dp[l][r] = Math.max(
      palindrome(l + 1, r - 1),
      palindrome(l, r - 1),
      palindrome(l + 1, r)
    ));
  }

  return palindrome(0, s.length - 1);
}

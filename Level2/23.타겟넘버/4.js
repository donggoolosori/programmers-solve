function solution(numbers, target) {
  function dfs(L, sum) {
    if (L === numbers.length) {
      return sum === target ? 1 : 0;
    }

    return dfs(L + 1, sum + numbers[L]) + dfs(L + 1, sum - numbers[L]);
  }

  return dfs(0, 0);
}

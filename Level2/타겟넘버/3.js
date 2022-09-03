function dfs(numbers, target, idx, acc) {
  if (idx === numbers.length) {
    if (acc === target) return 1;
    return 0;
  }

  return (
    dfs(numbers, target, idx + 1, acc + numbers[idx]) +
    dfs(numbers, target, idx + 1, acc - numbers[idx])
  );
}

function solution(numbers, target) {
  return dfs(numbers, target, 0, 0);
}

function solution(n, results) {
  const graph = Array.from({ length: n + 1 }, () =>
    Array.from({ length: n + 1 }, () => false)
  );

  results.forEach(([winner, loser]) => {
    graph[winner][loser] = true;
  });

  for (let k = 1; k <= n; k++) {
    for (let i = 1; i <= n; i++) {
      for (let j = 1; j <= n; j++) {
        if (graph[i][k] && graph[k][j]) {
          graph[i][j] = true;
        }
      }
    }
  }

  let answer = 0;
  for (let i = 1; i <= n; i++) {
    let cnt = 0;
    for (let j = 1; j <= n; j++) {
      if (graph[i][j] || graph[j][i]) {
        cnt++;
      }
    }
    if (cnt === n - 1) answer++;
  }
  return answer;
}

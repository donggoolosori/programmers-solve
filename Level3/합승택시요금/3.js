function solution(n, s, a, b, fares) {
  const INF = 987654321;
  const graph = [[]];

  for (let i = 1; i <= n; i++) {
    graph[i] = [0];
    for (let j = 1; j <= n; j++) {
      if (i === j) graph[i][j] = 0;
      else graph[i][j] = INF;
    }
  }

  fares.forEach(([c, d, f]) => {
    graph[c][d] = f;
    graph[d][c] = f;
  });

  for (let k = 1; k <= n; k++) {
    for (let i = 1; i <= n; i++) {
      for (let j = 1; j <= n; j++) {
        graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }

  let answer = graph[s][a] + graph[s][b];

  for (let i = 1; i <= n; i++) {
    answer = Math.min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
  }

  return answer;
}

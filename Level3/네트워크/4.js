function solution(n, computers) {
  const visit = {};

  function dfs(curr) {
    visit[curr] = true;

    for (let i = 0; i < n; i++) {
      if (computers[curr][i] === 0 || visit[i]) continue;

      dfs(i);
    }
  }

  let network = 0;
  for (let i = 0; i < n; i++) {
    if (visit[i]) continue;

    network++;
    dfs(i);
  }
  return network;
}

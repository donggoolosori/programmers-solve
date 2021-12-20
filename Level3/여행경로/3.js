function solution(tickets) {
  const candidates = [];
  const visit = {};

  function dfs(L, path, curr) {
    if (L === tickets.length) {
      candidates.push(path);
      return;
    }

    for (let i = 0; i < tickets.length; i++) {
      const [start, end] = tickets[i];
      if (visit[i] || start !== curr) continue;

      visit[i] = true;
      dfs(L + 1, path + end + ',', end);
      visit[i] = false;
    }
  }

  dfs(0, 'ICN,', 'ICN');

  return candidates.sort()[0].split(',').slice(0, -1);
}

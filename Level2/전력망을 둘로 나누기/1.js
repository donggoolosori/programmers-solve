function solution(n, wires) {
  const tree = Array.from({ length: n + 1 }, () =>
    Array.from({ length: n + 1 }, () => false)
  );

  wires.forEach(([a, b]) => {
    tree[a][b] = true;
    tree[b][a] = true;
  });

  let ans = 2e9;

  wires.forEach(([a, b]) => {
    tree[a][b] = false;
    tree[b][a] = false;

    const visit = {};

    const cnt = [];

    for (let i = 1; i <= n; i++) {
      if (visit[i]) continue;
      visit[i] = true;
      cnt.push(dfs(i));
    }

    const diff = Math.abs(cnt[0] - cnt[1]);

    ans = Math.min(ans, diff);

    tree[a][b] = true;
    tree[b][a] = true;

    function dfs(curr) {
      let ret = 1;

      for (let i = 1; i <= n; i++) {
        if (visit[i] || !tree[curr][i]) continue;
        visit[i] = true;
        ret += dfs(i);
      }

      return ret;
    }
  });

  return ans;
}

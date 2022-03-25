function solution(k, dungeons) {
  let visit = {},
    ans = 0;

  function findMaxDungeon(fuel, L) {
    ans = Math.max(ans, L);

    for (let i = 0; i < dungeons.length; i++) {
      if (visit[i]) continue;
      if (dungeons[i][0] > fuel) continue;
      visit[i] = true;
      findMaxDungeon(fuel - dungeons[i][1], L + 1);
      visit[i] = false;
    }
  }

  findMaxDungeon(k, 0);

  return ans;
}

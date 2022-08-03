function solution(N, stages) {
  const challenge = {},
    reach = {};
  for (let i = 1; i <= N + 1; i++) (challenge[i] = 0), (reach[i] = 0);

  stages.forEach((stage) => {
    reach[stage]++;
    for (let i = 1; i <= stage; i++) {
      challenge[i]++;
    }
  });

  return [...Array(N)]
    .map((_, idx) => {
      const stage = idx + 1;
      const failRate = reach[stage] / challenge[stage];
      return { stage, failRate };
    })
    .sort((a, b) => b.failRate - a.failRate)
    .map((el) => el.stage);
}

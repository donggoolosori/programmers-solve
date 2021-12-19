function solution(routes) {
  routes.sort((a, b) => a[0] - b[0]);
  let start = -30000,
    end = 30000;

  let answer = 1;
  for (const [s, e] of routes) {
    if (s >= start && s <= end) {
      start = s;
      end = Math.min(end, e);
      continue;
    }
    answer++;
    (start = s), (end = e);
  }
  return answer;
}

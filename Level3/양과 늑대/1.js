function solution(info, edges) {
  const graph = Array.from({ length: info.length }, () => []);
  edges.forEach(([a, b]) => graph[a].push(b));

  let answer = 0;

  function travel(curr, sheep, wolf, nexts) {
    sheep += !info[curr];
    wolf += info[curr];

    answer = Math.max(answer, sheep);

    if (sheep === wolf) return;

    nexts ^= 1 << curr;

    for (let i = 0; i < graph[curr].length; i++) {
      const next = graph[curr][i];
      nexts |= 1 << next;
    }

    for (let next = 0; next < info.length; next++) {
      if (nexts & (1 << next)) {
        travel(next, sheep, wolf, nexts);
      }
    }
  }

  travel(0, 0, 0, 1 << 0);

  return answer;
}

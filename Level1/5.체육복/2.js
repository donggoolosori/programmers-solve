function solution(n, lost, reserve) {
  const map = {};

  for (let i = 1; i <= n; i++) map[i] = 1;

  reserve.forEach((id) => map[id]++);

  return lost
    .filter((id) => {
      if (--map[id] == 0) return id;
    })
    .sort((a, b) => a - b)
    .reduce((acc, id) => {
      if (map[id - 1] === 2) {
        map[id - 1] = 1;
        return acc;
      }
      if (map[id + 1] === 2) {
        map[id + 1] = 1;
        return acc;
      }
      return acc - 1;
    }, n);
}

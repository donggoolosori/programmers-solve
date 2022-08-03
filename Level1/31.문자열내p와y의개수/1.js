function solution(s) {
  const [numOfp, numOfy] = s
    .split('')
    .map((s) => s.toLowerCase())
    .reduce(
      ([p, y], s) => {
        if (s === 'p') {
          return [p + 1, y];
        } else if (s === 'y') {
          return [p, y + 1];
        }
        return [p, y];
      },
      [0, 0]
    );

  return numOfp === numOfy;
}

function solution(line) {
  const intersections = [];
  let sy = undefined,
    sx = undefined,
    ey = undefined,
    ex = undefined;

  for (let i = 0; i < line.length; i++) {
    for (let j = i + 1; j < line.length; j++) {
      const [a, b, e] = line[i];
      const [c, d, f] = line[j];

      const x = (b * f - e * d) / (a * d - b * c);
      const y = (e * c - a * f) / (a * d - b * c);

      if (x === parseInt(x) && y === parseInt(y)) {
        intersections.push({ x, y: -y });

        if (sy === undefined || sy > -y) {
          sy = -y;
        }
        if (sx === undefined || sx > x) {
          sx = x;
        }
        if (ey === undefined || ey < -y) {
          ey = -y;
        }
        if (ex === undefined || ex < x) {
          ex = x;
        }
      }
    }
  }

  const arr = Array.from({ length: ey - sy + 1 }, () =>
    Array.from({ length: ex - sx + 1 }, () => '.')
  );

  intersections.forEach(({ y, x }) => {
    arr[y - sy][x - sx] = '*';
  });

  return arr.map((str) => str.join(''));
}

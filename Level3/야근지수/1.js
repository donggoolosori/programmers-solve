function solution(n, works) {
  works.sort((a, b) => b - a);

  let worked = 0;
  for (let target = works[0]; target >= 1; target--) {
    if (worked >= n) break;

    for (let i = 0; i < works.length && worked < n; i++) {
      if (works[i] !== target) break;

      works[i]--;
      worked++;
    }
  }

  return works.reduce((acc, val) => acc + val ** 2, 0);
}

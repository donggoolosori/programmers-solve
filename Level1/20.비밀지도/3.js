function solution(n, arr1, arr2) {
  return arr1.map((val, idx) =>
    (val | arr2[idx])
      .toString(2)
      .replace(/[01]/g, (s) => (s === '0' ? ' ' : '#'))
      .padStart(n)
  );
}

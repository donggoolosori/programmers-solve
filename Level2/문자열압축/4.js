function solution(s) {
  let ret = s.length;

  for (let i = 1; i <= s.length / 2; i++) {
    ret = Math.min(ret, compress(divide(s, i), i).length);
  }

  return ret;
}

function divide(s, unit) {
  if (s.length <= unit) return [s];
  return [s.slice(0, unit), ...divide(s.slice(unit), unit)];
}

function compress(arr, unit) {
  let count = 0,
    curr = arr[0],
    ret = '';

  arr.forEach((s) => {
    if (s === curr) {
      count++;
    } else {
      ret += count === 1 ? curr : `${count}${curr}`;
      count = 1;
      curr = s;
    }
  });

  ret += count === 1 ? curr : `${count}${curr}`;

  return ret;
}

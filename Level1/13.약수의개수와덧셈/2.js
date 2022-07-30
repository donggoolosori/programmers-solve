function solution(left, right) {
  let ret = 0;

  for (let i = left; i <= right; i++) {
    if (Math.sqrt(i) === parseInt(Math.sqrt(i))) {
      ret -= i;
    } else {
      ret += i;
    }
  }

  return ret;
}

function decToStr(n, len) {
  let ret = '';

  while (n != 0) {
    let code;
    n % 2 == 0 ? (code = ' ') : (code = '#');
    n = parseInt(n / 2);
    ret = code + ret;
  }

  return ret.padStart(len);
}

function solution(n, arr1, arr2) {
  return [...Array(n)].map((_, idx) => decToStr(arr1[idx] | arr2[idx], n));
}

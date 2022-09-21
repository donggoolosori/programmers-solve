function solution(n, stations, w) {
  const coverage = w * 2 + 1;

  let ret = 0;

  const endpoint = stations.reduce((from, cur) => {
    const apts = cur - w - from;

    ret += apts > 0 ? Math.ceil(apts / coverage) : 0;

    return cur + w + 1;
  }, 1);

  if (endpoint <= n) {
    const apts = n - endpoint + 1;

    ret += Math.ceil(apts / coverage);
  }

  return ret;
}

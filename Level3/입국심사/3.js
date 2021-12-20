function solution(n, times) {
  times.sort((a, b) => a - b);

  let low = times[0],
    high = times[times.length - 1] * n;

  while (low < high) {
    const mid = parseInt((low + high) / 2);

    let cnt = 0;

    times.forEach((time) => (cnt += parseInt(mid / time)));

    if (cnt >= n) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return high;
}

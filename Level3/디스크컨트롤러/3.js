function solution(jobs) {
  const pq = [];

  jobs.sort((a, b) => a[0] - b[0]);

  let idx = 0,
    time = 0,
    sum = 0;

  while (idx < jobs.length || pq.length !== 0) {
    if (idx < jobs.length && jobs[idx][0] <= time) {
      pq.push(jobs[idx++]);
      continue;
    }

    if (pq.length !== 0) {
      const minRunTime = Math.min.apply(
        null,
        pq.map((el) => el[1])
      );
      const nextIndex = pq.findIndex((el) => el[1] === minRunTime);
      const nextReqTime = pq[nextIndex][0];

      time += minRunTime;
      sum += time - nextReqTime;
      pq.splice(nextIndex, 1);
    } else {
      time = jobs[idx][0];
    }
  }
  return (sum / jobs.length) >> 0;
}

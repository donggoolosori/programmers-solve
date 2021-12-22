//시간초과
function timeToSecond(time) {
  const regex = /(?<h>\d+):(?<m>\d+):(?<s>\d+)/;
  const { h, m, s } = regex.exec(time).groups;
  return h * 3600 + m * 60 + s * 1;
}

function solution(play_time, adv_time, logs) {
  const playTime = timeToSecond(play_time);
  const advTime = timeToSecond(adv_time);
  const playTimes = Array.from({ length: playTime }, () => 0);

  for (let i = 0; i < logs.length; i++) {
    const start = timeToSecond(logs[i].slice(0, 8));
    const end = timeToSecond(logs[i].slice(9));

    for (let j = start; j < end; j++) {
      playTimes[j]++;
    }
  }

  let sum = 0;
  for (let i = 0; i < advTime; i++) {
    sum += playTimes[i];
  }
  let maxSum = sum,
    maxPlayTime = 0,
    low = 0,
    high = advTime;

  while (high < playTime) {
    sum += playTimes[high++];
    sum -= playTimes[low++];

    if (sum > maxSum) {
      maxSum = sum;
      maxPlayTime = low;
    }
  }

  const h = ((maxPlayTime / 3600) >> 0) + '',
    m = (((maxPlayTime % 3600) / 60) >> 0) + '',
    s = ((maxPlayTime % 3600) % 60) + '';
  return `${h.padStart(2, '0')}:${m.padStart(2, '0')}:${s.padStart(2, '0')}`;
}

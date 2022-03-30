function getTimeDiff(s, e) {
  const sh = Number(s.substr(0, 2)),
    eh = Number(e.substr(0, 2));
  const sm = Number(s.substr(3)),
    em = Number(e.substr(3));
  return eh * 60 + em - (sh * 60 + sm);
}

function solution(fees, records) {
  function getFee(t) {
    if (t <= fees[0]) return fees[1];

    return fees[1] + Math.ceil((t - fees[0]) / fees[2]) * fees[3];
  }

  // 차량번호별 누적 주차시간 구하기
  const buffer = {};
  const parkingTime = {};

  records.forEach((record) => {
    let [time, license, type] = record.split(' ');

    if (type === 'IN') {
      buffer[license] = { time, type };
    } else {
      const { time: inTime } = buffer[license];
      buffer[license] = { time, type };

      if (!parkingTime[license]) parkingTime[license] = 0;
      parkingTime[license] += getTimeDiff(inTime, time);
    }
  });

  Object.entries(buffer).forEach(([license, { time, type }]) => {
    if (type === 'OUT') return;
    if (!parkingTime[license]) parkingTime[license] = 0;
    parkingTime[license] += getTimeDiff(time, '23:59');
  });

  // 차량번호별 주차 요금 구하기
  return Object.entries(parkingTime)
    .map(([license, time]) => {
      return [Number(license), getFee(time)];
    })
    .sort((a, b) => a[0] - b[0])
    .map((v) => v[1]);
}

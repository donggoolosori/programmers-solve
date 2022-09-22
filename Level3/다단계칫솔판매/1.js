function solution(enroll, referral, seller, amount) {
  const n = enroll.length;

  const bossOf = {},
    indexOf = {};

  enroll.forEach((name, idx) => {
    bossOf[name] = referral[idx];
    indexOf[name] = idx;
  });

  const res = Array.from({ length: n }, () => 0);

  seller.forEach((name, idx) => {
    let profit = amount[idx] * 100;
    let me = name,
      boss = bossOf[name];

    while (bossOf[me] && profit > 0) {
      const commission = Math.floor(profit * 0.1);
      res[indexOf[me]] += profit - commission;
      profit = commission;
      me = bossOf[me];
    }
  });

  return res;
}

function solution(lottos, win_nums) {
  let zero = 0,
    rank = 6,
    correct = 0;

  lottos.forEach((num) => {
    if (num === 0) zero++;
    else if (win_nums.includes(num)) {
      correct++;
    }
  });

  return [Math.min(6, 6 - (zero + correct) + 1), Math.min(6, 6 - correct + 1)];
}

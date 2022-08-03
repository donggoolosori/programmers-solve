function solution(dartResult) {
  const regex = /[0-9]+/g;

  const bonusAndOption = dartResult.split(regex).slice(1);
  const scores = dartResult.match(regex).map((el) => parseInt(el));
  scores.forEach((score, idx) => {
    const [bonus, option] = bonusAndOption[idx];

    if (bonus === 'D') scores[idx] **= 2;
    else if (bonus === 'T') scores[idx] **= 3;

    if (option === '*') {
      scores[idx] *= 2;
      scores[idx - 1] ? (scores[idx - 1] *= 2) : undefined;
    } else if (option === '#') {
      scores[idx] = -scores[idx];
    }
  });

  return scores.reduce((acc, score) => acc + score, 0);
}

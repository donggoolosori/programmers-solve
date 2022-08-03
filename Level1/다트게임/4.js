function solution(dartResult) {
  const darts = dartResult.match(/(\d)+(S|D|T)(\*|#)?/g);

  const scores = [...Array(darts.length)];

  darts.forEach((dart, idx) => {
    let [score, bonus, option] = dart.match(/(\d+)|(S|D|T)|(\*|#)/g);
    score = parseInt(score);

    if (bonus === 'D') score **= 2;
    else if (bonus === 'T') score **= 3;

    scores[idx] = score;

    if (option === '*') {
      scores[idx] *= 2;
      scores[idx - 1] ? (scores[idx - 1] *= 2) : undefined;
    } else if (option === '#') {
      scores[idx] *= -1;
    }
  });

  return scores.reduce((acc, score) => acc + score, 0);
}

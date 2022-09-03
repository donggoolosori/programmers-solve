function solution(survey, choices) {
  const types = ['RT', 'CF', 'JM', 'AN'];
  const scores = types.reduce((acc, [t1, t2]) => ({ ...acc, [t1]: 0, [t2]: 0 }), {});

  choices.forEach((choice, idx) => {
    const [n, p] = survey[idx];

    scores[choice < 4 ? n : p] += Math.abs(4 - choice);
  });

  return types.reduce((res, [t1, t2]) => {
    return res + (scores[t1] >= scores[t2] ? t1 : t2);
  }, '');
}

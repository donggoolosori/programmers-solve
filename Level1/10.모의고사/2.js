function getScore(answers, solves) {
  const len = solves.length;

  return answers.reduce((prev, curr, idx) => {
    return prev + (curr === solves[idx % len] ? 1 : 0);
  }, 0);
}

function solution(answers) {
  const supo1 = [1, 2, 3, 4, 5],
    supo2 = [2, 1, 2, 3, 2, 4, 2, 5],
    supo3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];

  const scores = [
    getScore(answers, supo1),
    getScore(answers, supo2),
    getScore(answers, supo3),
  ];

  const maxValue = Math.max(...scores);

  return scores.reduce((prev, curr, idx) => {
    if (curr === maxValue) {
      return [...prev, idx + 1];
    }
    return prev;
  }, []);
}

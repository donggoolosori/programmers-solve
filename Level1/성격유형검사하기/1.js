function solution(survey, choices) {
  const typeScores = { R: 0, T: 0, C: 0, F: 0, J: 0, M: 0, A: 0, N: 0 };
  const score = [0, 3, 2, 1, 0, 1, 2, 3];

  survey.forEach((s, index) => {
    const [type1, type2] = s.split('');

    const choice = choices[index];
    let type;
    if (choice <= 4) {
      type = type1;
    } else {
      type = type2;
    }

    typeScores[type] += score[choice];
  });

  let res = '';

  res += typeScores['R'] >= typeScores['T'] ? 'R' : 'T';
  res += typeScores['C'] >= typeScores['F'] ? 'C' : 'F';
  res += typeScores['J'] >= typeScores['M'] ? 'J' : 'M';
  res += typeScores['A'] >= typeScores['N'] ? 'A' : 'N';

  return res;
}

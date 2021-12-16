function solution(n, t, m, p) {
  let answer = '',
    sheet = '',
    num = 0;

  while (sheet.length < m * t) {
    sheet += (num++).toString(n);
  }

  for (let i = p - 1; i < sheet.length && answer.length < t; i += m) {
    answer += sheet[i].toUpperCase();
  }

  return answer;
}

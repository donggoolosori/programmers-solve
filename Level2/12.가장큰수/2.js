function compare(a, b) {
  return (b + a) * 1 - (a + b) * 1;
}

function solution(numbers) {
  const answer = numbers
    .map((v) => v + '')
    .sort(compare)
    .join('');
  return answer[0] === '0' ? '0' : answer;
}

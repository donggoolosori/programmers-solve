function solution(number, k) {
  const answer = [];
  const numLen = number.length;
  let head = 0;
  let del = k;

  answer.push(number[head++]);
  while (answer.length < numLen - k || head < numLen) {
    if (del && answer[answer.length - 1] < number[head]) {
      del--;
      answer.pop();
      continue;
    }
    answer.push(number[head++]);
  }

  return answer.slice(0, numLen - k).join('');
}

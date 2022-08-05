function solution(progresses, speeds) {
  const completionDays = progresses.map((pr, idx) =>
    Math.ceil((100 - pr) / speeds[idx])
  );

  let answer = [],
    stack = [];

  completionDays.forEach((day) => {
    if (stack.length === 0 || Math.max(...stack) >= day) {
      stack.push(day);
    } else {
      answer.push(stack.length);
      stack = [day];
    }
  });

  if (stack.length !== 0) answer.push(stack.length);

  return answer;
}

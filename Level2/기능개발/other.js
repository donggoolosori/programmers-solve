function solution(progresses, speeds) {
  const completionDays = progresses.map((pr, idx) =>
    Math.ceil((100 - pr) / speeds[idx])
  );

  let answer = [0];
  let maxDay = completionDays[0];

  for (let i = 0, j = 0; i < completionDays.length; i++) {
    if (completionDays[i] <= maxDay) {
      answer[j] += 1;
    } else {
      maxDay = completionDays[i];
      answer[++j] = 1;
    }
  }

  return answer;
}

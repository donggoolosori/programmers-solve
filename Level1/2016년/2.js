function solution(a, b) {
  const dateDiff =
    (new Date(2016, a - 1, b) - new Date(2016, 0, 1)) / 1000 / 60 / 60 / 24;
  const days = ['FRI', 'SAT', 'SUN', 'MON', 'TUE', 'WED', 'THU'];
  return days[dateDiff % 7];
}

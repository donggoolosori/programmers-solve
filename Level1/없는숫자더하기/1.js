function solution(numbers) {
  const SUM_FROM_ONE_TO_NINE = 45;

  return (
    SUM_FROM_ONE_TO_NINE -
    [...new Set(numbers)].reduce((acc, num) => acc + num, 0)
  );
}

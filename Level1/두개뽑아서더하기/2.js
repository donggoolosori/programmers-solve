function solution(numbers) {
  const ret = new Set();

  for (let i = 0; i < numbers.length; i++) {
    for (let j = i + 1; j < numbers.length; j++) {
      ret.add(numbers[i] + numbers[j]);
    }
  }

  return [...ret].sort((a, b) => a - b);
}

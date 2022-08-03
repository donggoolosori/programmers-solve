function solution(d, budget) {
  let ret = 0;

  const sortedD = [...d].sort((a, b) => a - b);

  let sum = 0;
  for (let i = 0; i < sortedD.length; i++) {
    if (sum + sortedD[i] <= budget) {
      ret++;
      sum += sortedD[i];
    } else {
      return ret;
    }
  }
  return ret;
}

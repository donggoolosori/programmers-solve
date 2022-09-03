function solution(arr, divisor) {
  const filteredArr = arr
    .filter((val) => val % divisor === 0)
    .sort((a, b) => a - b);
  return filteredArr.length === 0 ? [-1] : filteredArr;
}

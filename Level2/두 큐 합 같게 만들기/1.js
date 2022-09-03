function solution(queue1, queue2) {
  const arr = [...queue1, ...queue2];
  const total = arr.reduce((acc, num) => acc + num);

  if (total % 2 !== 0) return -1;

  const target = total / 2;

  let l = 0,
    r = queue1.length - 1,
    count = 0,
    sum = queue1.reduce((acc, num) => acc + num);

  while (l <= r && r < arr.length) {
    if (sum === target) return count;

    if (sum < target) {
      sum += arr[++r];
    } else {
      sum -= arr[l++];
    }
    count++;
  }

  return -1;
}

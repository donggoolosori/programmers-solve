function solution(A, B) {
  B.sort((a, b) => a - b);
  A.sort((a, b) => a - b);

  let aIdx = 0,
    ret = 0;
  for (let bIdx = 0; bIdx < B.length; bIdx++) {
    if (B[bIdx] <= A[aIdx]) continue;

    ret++;
    aIdx++;
  }

  return ret;
}

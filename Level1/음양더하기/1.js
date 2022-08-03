function solution(absolutes, signs) {
  return absolutes.reduce((acc, num, idx) => {
    const signedNum = signs[idx] ? num : -num;

    return acc + signedNum;
  }, 0);
}

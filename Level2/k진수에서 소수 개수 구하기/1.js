function solution(n, k) {
  let kNum = n.toString(k);

  kNum = '0' + kNum + '0';

  const cands = [];

  let num = '';
  for (let i = 0; i < kNum.length; i++) {
    if (kNum[i] === '0') {
      if (num !== '') {
        cands.push(Number(num));
      }
      num = '';
    } else {
      num += kNum[i];
    }
  }

  function isPrime(num) {
    if (num <= 1) return false;

    for (let i = 2; i <= Math.sqrt(num); i++) {
      if (num % i === 0) return false;
    }
    return true;
  }

  return cands.reduce((sum, num) => (isPrime(num) ? sum + 1 : sum), 0);
}

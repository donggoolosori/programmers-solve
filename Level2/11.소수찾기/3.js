function chkPrime(num) {
  if (num < 2) return false;
  if (num === 2) return true;
  for (var i = 2; i <= Math.sqrt(num); i++) {
    if (num % i === 0) return false;
  }
  return true;
}

function solution(numbers) {
  const visit = [...Array(numbers.length)].map((el) => 0);
  const map = {};
  function findNum(L, num) {
    if (L === numbers.length) {
      if (num.length > 0 && chkPrime(parseInt(num))) {
        map[parseInt(num)] = 1;
      }
      return;
    }

    for (let i = 0; i < numbers.length; i++) {
      if (visit[i]) continue;
      visit[i] = 1;
      findNum(L + 1, num + numbers[i]);
      visit[i] = 0;
    }
    findNum(L + 1, num);
  }
  findNum(0, '');
  return Object.keys(map).length;
}

// 효율성 체크에서 마지막 4개 시간초과
// 배열 사용
// 삭제를 state 값만 0으로 변경해주는 것으로 처리. 실제 배열에서 삭제는 안함
function solution(n, k, cmd) {
  const db = Array.from({ length: n }, () => 1);
  const delStack = [];

  let curr = k,
    lastIdx = n - 1;

  cmd.forEach((c) => {
    let [type, m] = c.split(' ');
    m = Number(m);

    if (type === 'D') {
      while (m) {
        curr++;
        if (db[curr] === 1) m--;
      }
    } else if (type === 'U') {
      while (m) {
        curr--;
        if (db[curr] === 1) m--;
      }
    } else if (type === 'C') {
      db[curr] = 0;
      delStack.push(curr);

      if (curr === lastIdx) {
        while (db[curr] === 0) {
          curr--;
          lastIdx--;
        }
      } else {
        while (db[curr] === 0) {
          curr++;
        }
      }
    } else if (type === 'Z') {
      const restoreIdx = delStack[delStack.length - 1];
      delStack.pop();

      db[restoreIdx] = 1;
      if (restoreIdx > lastIdx) lastIdx = restoreIdx;
    }
  });

  return db.map((state) => (state === 1 ? 'O' : 'X')).join('');
}

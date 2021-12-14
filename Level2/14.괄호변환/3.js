function isRight(s) {
  const stack = [];
  for (let i = 0; i < s.length; i++) {
    if (s[i] === '(') {
      stack.push(s[i]);
    } else if (s[i] === ')') {
      if (stack.length === 0) return false;
      stack.pop();
    }
  }
  return stack.length === 0;
}

function convertToRight(p) {
  if (p === '') return '';

  let l = 0,
    r = 0,
    u,
    v;
  for (let i = 0; i < p.length; i++) {
    if (p[i] === '(') l++;
    else if (p[i] === ')') r++;

    if (l !== 0 && l === r) {
      u = p.substring(0, i + 1);
      v = p.substring(i + 1);
      break;
    }
  }

  if (!isRight(u)) {
    return (
      '(' +
      convertToRight(v) +
      ')' +
      u.slice(1, -1).replace(/[\(\)]/g, (s) => (s === '(' ? ')' : '('))
    );
  }
  return u + convertToRight(v);
}

function solution(p) {
  if (isRight(p)) return p;

  return convertToRight(p);
}

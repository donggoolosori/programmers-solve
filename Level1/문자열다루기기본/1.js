function solution(s) {
  return (s.length === 4 || s.length === 6) && /\d+/.exec(s)[0] === s;
}

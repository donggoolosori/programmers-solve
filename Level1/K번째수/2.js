function compare(a, b) {
  return a - b;
}

function solution(array, commands) {
  return commands.map((command) => {
    const [i, j, k] = command;
    return array.slice(i - 1, j).sort(compare)[k - 1];
  });
}

function solution(operations) {
  const q = [];
  operations.forEach((operation) => {
    let [command, number] = operation.split(' ');
    number = Number(number);

    if (command === 'I') {
      q.push(number);
    } else if (command === 'D') {
      if (q.length === 0) return;

      const target =
        number === 1 ? Math.max.apply(null, q) : Math.min.apply(null, q);
      const delIdx = q.indexOf(target);

      q.splice(delIdx, 1);
    }
  });

  if (q.length === 0) return [0, 0];
  return [Math.max.apply(null, q), Math.min.apply(null, q)];
}

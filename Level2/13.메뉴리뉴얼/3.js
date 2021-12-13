function solution(orders, course) {
  orders = orders.map((order) => order.split('').sort().join(''));
  const answer = [];

  course.forEach((courseLen) => {
    const counter = {};

    orders.forEach((order) => {
      comb(0, '');

      function comb(idx, curr) {
        if (curr.length === courseLen) {
          counter[curr] ? counter[curr]++ : (counter[curr] = 1);
          return;
        }
        for (let i = idx; i < order.length; i++) {
          comb(i + 1, curr + order[i]);
        }
      }
    });

    const arr = Object.entries(counter).sort((a, b) => b[1] - a[1]);

    if (Object.keys(counter).length === 0) return;

    const maxCount = arr[0][1];
    if (maxCount < 2) return;

    for (let i = 0; i < arr.length; i++) {
      if (arr[i][1] < maxCount) break;
      answer.push(arr[i][0]);
    }
  });

  return answer.sort();
}

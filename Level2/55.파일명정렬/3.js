function compare(a, b) {
  if (a.head !== b.head) {
    return a.head.localeCompare(b.head);
  }
  if (a.number !== b.number) {
    return a.number - b.number;
  }
  return 0;
}

function solution(files) {
  return files
    .map((file) => {
      const regex = /(?<head>\D+)(?<number>\d*)/g;

      const { head, number, tail } = regex.exec(file).groups;

      return {
        name: file,
        head: head.toLowerCase(),
        number: Number(number),
      };
    })
    .sort(compare)
    .map((el) => el.name);
}

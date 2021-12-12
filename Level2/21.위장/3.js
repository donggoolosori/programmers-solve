function solution(clothes) {
  const clotheMap = {};

  clothes.forEach(([name, kind]) =>
    clotheMap[kind] ? clotheMap[kind]++ : (clotheMap[kind] = 1)
  );

  return (
    Object.values(clotheMap).reduce((acc, curr) => {
      return acc * (curr + 1);
    }, 1) - 1
  );
}

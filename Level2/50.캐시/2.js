function solution(cacheSize, cities) {
  const cache = [];

  if (cacheSize === 0) {
    return cities.length * 5;
  }

  return cities.reduce((runTime, city) => {
    city = city.toLowerCase();
    const cacheIndex = cache.indexOf(city);

    if (cacheIndex !== -1) {
      cache.push(...cache.splice(cacheIndex, 1));
      return runTime + 1;
    }

    if (cache.length === cacheSize) {
      cache.shift();
    }

    cache.push(city);
    return runTime + 5;
  }, 0);
}

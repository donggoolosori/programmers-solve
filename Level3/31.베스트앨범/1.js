function solution(genres, plays) {
  const n = genres.length;

  const myMap = {}; // map:{genre:{total:0, music:[]}

  for (let i = 0; i < n; i++) {
    const genre = genres[i],
      play = plays[i];

    if (!myMap[genre]) {
      myMap[genre] = { total: 0, music: [] };
    }
    myMap[genre].total += play;
    myMap[genre].music.push({ id: i, play });
  }

  const answer = [];
  [...new Set(genres)]
    .sort((a, b) => myMap[b].total - myMap[a].total)
    .forEach((genre) => {
      answer.push(
        ...myMap[genre].music
          .sort((a, b) => b.play - a.play)
          .slice(0, 2)
          .map((el) => el.id)
      );
    });
  return answer;
}

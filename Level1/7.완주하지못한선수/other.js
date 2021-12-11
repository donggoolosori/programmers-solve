const solution = (participant, completion) => {
  return participant.find(
    (name) => !completion[name]--,
    completion.forEach(
      (name) => (completion[name] = (completion[name] | 0) + 1)
    )
  );
};

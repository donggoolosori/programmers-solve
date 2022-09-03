function getReportMap(id_list) {
  return id_list.reduce((obj, id) => {
    return {
      ...obj,
      [id]: {
        reportedCount: 0,
        reportList: [],
      },
    };
  }, {});
}
function solution(id_list, report, k) {
  const reportMap = getReportMap(id_list);

  [...new Set(report)].forEach((r) => {
    const [reporter, abuser] = r.split(' ');

    reportMap[abuser].reportedCount++;
    reportMap[reporter].reportList.push(abuser);
  });

  return id_list.map((id) =>
    reportMap[id].reportList.reduce(
      (acc, abuser) => (reportMap[abuser].reportedCount >= k ? acc + 1 : acc),
      0
    )
  );
}

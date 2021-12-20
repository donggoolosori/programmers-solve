#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct PageInfo {
  double base;
  int idx, numOfExLink;
  vector<string> ex_links;
};

struct Node {
  double match;
  int idx;
};

// 정렬 조건
bool compare(Node a, Node b) {
  if (a.match == b.match) return a.idx < b.idx;
  return a.match > b.match;
}

int solution(string word, vector<string> pages) {
  unordered_map<string, PageInfo> info;
  vector<string> addresses;
  // 검색어 소문자로 변환
  transform(word.begin(), word.end(), word.begin(), ::tolower);

  int idx = 0;
  for (auto &page : pages) {
    // page 소문자로 변환
    transform(page.begin(), page.end(), page.begin(), ::tolower);
    // page의 링크 추출
    string keyword = "<meta property=\"og:url\" content=\"https://";
    int address_idx = page.find(keyword) + keyword.length();
    string address = "";
    while (page[address_idx] != '\"') {
      address += page[address_idx++];
    }
    addresses.push_back(address);

    PageInfo pageInfo;
    // page idx 설정
    pageInfo.idx = idx++;

    // page 기본점수 계산
    double base = 0;
    string s = "";
    for (int i = 0; i < page.length(); i++) {
      if (!(page[i] >= 'a' && page[i] <= 'z')) {
        s = "";
        continue;
      }
      s += page[i];
      if (s == word &&
          (i == page.length() - 1 || (page[i + 1] < 'a' || page[i + 1] > 'z')))
        base++;
    }
    pageInfo.base = base;

    // pageInfo 저장
    info[address] = pageInfo;
  }

  // page의 외부 링크 추출
  for (int i = 0; i < addresses.size(); i++) {
    string address = addresses[i];
    string page = pages[i];

    int start = 0, cnt = 0;
    string keyword = "<a href=\"https://";
    while (true) {
      start = page.find(keyword, start);
      if (start == string::npos) break;
      start += keyword.length();
      string link = "";
      while (page[start] != '\"') {
        link += page[start++];
      }
      cnt++;
      info[link].ex_links.push_back(address);
    }
    info[address].numOfExLink = cnt;
  }

  vector<Node> vec;
  // 매칭 점수 계산
  for (const auto &address : addresses) {
    // page 링크점수 계산
    double link = 0;
    for (const auto &ex_link : info[address].ex_links) {
      int numOfExLink = info[ex_link].numOfExLink;
      if (numOfExLink == 0) continue;
      link += info[ex_link].base / numOfExLink;
    }

    double match = info[address].base + link;
    vec.push_back({match, info[address].idx});
  }
  // 정렬
  sort(vec.begin(), vec.end(), compare);

  return vec[0].idx;
}
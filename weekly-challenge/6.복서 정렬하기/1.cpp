#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Profile {
  int win = 0, match = 0, win_heavier = 0, weight, number;
};

float getWinningRate(Profile a) {
  int win = a.win, match = a.match;
  if (match == 0) return 0;
  return (float)win / match;
}

bool compare(Profile a, Profile b) {
  float winning_rate_a = getWinningRate(a), winning_rate_b = getWinningRate(b);

  if (winning_rate_a == winning_rate_b) {
    if (a.win_heavier == b.win_heavier) {
      if (a.weight == b.weight) return a.number < b.number;

      return a.weight > b.weight;
    }
    return a.win_heavier > b.win_heavier;
  }
  return winning_rate_a > winning_rate_b;
}

vector<Profile> getProfiles(vector<int> &weights, vector<string> &head2head) {
  int n = weights.size();
  vector<Profile> profiles(n);

  for (int i = 0; i < n; i++) {
    profiles[i].weight = weights[i];
    profiles[i].number = i + 1;

    string result = head2head[i];

    for (int j = 0; j < n; j++) {
      if (result[j] == 'N') continue;

      if (result[j] == 'W') {
        profiles[i].win++;
        if (weights[i] < weights[j]) profiles[i].win_heavier++;
      }
      profiles[i].match++;
    }
  }
  return profiles;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
  vector<int> answer;

  vector<Profile> profiles = getProfiles(weights, head2head);

  sort(profiles.begin(), profiles.end(), compare);

  for (const auto &profile : profiles) {
    answer.push_back(profile.number);
  }

  return answer;
}
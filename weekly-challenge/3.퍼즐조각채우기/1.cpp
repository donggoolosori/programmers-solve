#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int len;

void getBlock(vector<vector<int>> &table, vector<vector<bool>> &visit,
              vector<vector<int>> &block, int y, int x) {
  queue<vector<int>> q;
  q.push({y, x});
  visit[y][x] = true;

  while (!q.empty()) {
    vector<int> curr = q.front();
    int cur_y = curr[0], cur_x = curr[1];
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cur_y + dy[i], nx = cur_x + dx[i];
      if (ny < 0 || nx < 0 || ny >= len || nx >= len) continue;
      if (visit[ny][nx] || table[ny][nx] == 0) continue;
      visit[ny][nx] = true;
      block.push_back({ny, nx});
      q.push({ny, nx});
    }
  }
}

vector<vector<vector<int>>> getBlocks(vector<vector<int>> &table) {
  vector<vector<vector<int>>> blocks;
  vector<vector<bool>> visit(len, vector<bool>(len));

  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (table[i][j] == 0 || visit[i][j]) continue;
      vector<vector<int>> block;
      block.push_back({i, j});

      getBlock(table, visit, block, i, j);
      for (auto &pos : block) {
        pos[0] -= i;
        pos[1] -= j;
      }
      blocks.push_back(block);
    }
  }

  return blocks;
}

vector<vector<int>> rotateBlock(vector<vector<int>> &block) {
  for (auto &piece : block) {
    int temp = piece[0];
    piece[0] = piece[1];
    piece[1] = -temp;
  }
  return block;
}

int countFill(vector<vector<int>> &game_board) {
  int ret = 0;
  for (int i = 0; i < len; i++)
    for (int j = 0; j < len; j++)
      if (game_board[i][j] == 1) ret++;

  return ret;
}

bool canInsertBlock(vector<vector<int>> &game_board, vector<vector<int>> &block,
                    int y, int x) {
  for (const auto &piece : block) {
    int ny = y + piece[0], nx = x + piece[1];
    if (ny < 0 || nx < 0 || ny >= len || nx >= len) return false;
    if (game_board[ny][nx] != 0) return false;
  }
  return true;
}

bool checkAround(vector<vector<int>> &game_board, vector<vector<int>> &block,
                 int y, int x) {
  for (const auto &piece : block) {
    int ny = y + piece[0], nx = x + piece[1];
    for (int i = 0; i < 4; i++) {
      int ay = ny + dy[i], ax = nx + dx[i];
      if (ay < 0 || ax < 0 || ay >= len || ax >= len) continue;
      if (game_board[ay][ax] == 0) return false;
    }
  }
  return true;
}

void insertBlock(vector<vector<int>> &game_board, vector<vector<int>> &block,
                 int y, int x) {
  for (const auto &piece : block) {
    int ny = y + piece[0], nx = x + piece[1];
    game_board[ny][nx] = 1;
  }
}

void removeBlock(vector<vector<int>> &game_board, vector<vector<int>> &block,
                 int y, int x) {
  for (const auto &piece : block) {
    int ny = y + piece[0], nx = x + piece[1];
    game_board[ny][nx] = 0;
  }
}

void doPuzzle(vector<vector<int>> &game_board,
              vector<vector<vector<int>>> &blocks) {
  for (auto &block : blocks) {
    bool flag = true;
    for (int r = 0; r < 4; r++) {
      if (!flag) break;
      if (r != 0) rotateBlock(block);

      for (int i = 0; i < len; i++) {
        if (!flag) break;

        for (int j = 0; j < len; j++) {
          if (game_board[i][j] == 1) continue;
          if (!canInsertBlock(game_board, block, i, j)) continue;

          insertBlock(game_board, block, i, j);
          if (!checkAround(game_board, block, i, j))
            removeBlock(game_board, block, i, j);
          else {
            flag = false;
            break;
          }
        }
      }
    }
  }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
  len = game_board.size();
  vector<vector<vector<int>>> blocks = getBlocks(table);
  int initialFill = countFill(game_board);
  doPuzzle(game_board, blocks);

  return countFill(game_board) - initialFill;
}
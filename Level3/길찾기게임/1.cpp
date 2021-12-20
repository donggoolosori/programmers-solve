// bst 구현 해서 풀이
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int x, y, idx;
};

class Tree {
  Node data;
  Tree *left, *right;

 public:
  Tree() : left(NULL), right(NULL) {}

  Tree(Node data) : data(data), left(NULL), right(NULL) {}

  Tree* insert(Tree* root, Node newData) {
    if (root == NULL) return new Tree(newData);

    if (newData.x > root->data.x) {
      root->right = insert(root->right, newData);
    } else {
      root->left = insert(root->left, newData);
    }
    return root;
  }

  void preorder(Tree* root, vector<int>& pre) {
    if (root == NULL) return;

    pre.push_back(root->data.idx);
    preorder(root->left, pre);
    preorder(root->right, pre);
  }

  void postorder(Tree* root, vector<int>& post) {
    if (root == NULL) return;

    postorder(root->left, post);
    postorder(root->right, post);
    post.push_back(root->data.idx);
  }
};

bool compare(Node a, Node b) { return a.y > b.y; }

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
  // nodes 벡터 생성 및 정렬
  vector<Node> nodes;
  for (int i = 0; i < nodeinfo.size(); i++) {
    nodes.push_back({nodeinfo[i][0], nodeinfo[i][1], i + 1});
  }
  sort(nodes.begin(), nodes.end(), compare);

  // Tree에 node 삽입
  Tree tree, *root = NULL;
  root = tree.insert(root, nodes[0]);
  for (int i = 1; i < nodes.size(); i++) {
    tree.insert(root, nodes[i]);
  }
  // 전위순회, 후위순회 vector 구하기
  vector<int> pre, post;
  tree.preorder(root, pre);
  tree.postorder(root, post);

  vector<vector<int>> answer = {pre, post};
  return answer;
}
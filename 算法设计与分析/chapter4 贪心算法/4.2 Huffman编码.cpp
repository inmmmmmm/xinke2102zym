//测试案例：6 a 5 b 9 c 12 d 13 e 16 f 45 输出： a: 1100 b: 1101 c: 100 d: 101 e: 111 f: 0 
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
 
/* Huffman树的节点 */
struct Node {
  Node() {}
  Node(int frequency, char ch, Node* left, Node* right) {
    this->frequency = frequency;
    this->ch = ch;
    this->left = left;
    this->right = right;
  }
  int frequency;
  char ch;
  Node* left;
  Node* right;
};
 
class HuffmanCode {
public:
  HuffmanCode() {}
  ~HuffmanCode() {
    if (nvec.size() > 0)
      clear(nvec[0]);
  }
 
  /* 建树 */
  void buildTree(const char* ch, const int* fq, const int& size) {
    for (int i = 0; i < size; ++i) {
      Node* node = new Node(fq[i], ch[i], NULL, NULL);
      nvec.push_back(node);
    }
    while (nvec.size() != 1) {
      Node* x = getMinNodeAndRemoveIt();
      Node* y = getMinNodeAndRemoveIt();
      Node* z = new Node(x->frequency + y->frequency, '\0', x, y);
      nvec.push_back(z);
    }
  }
 
  /* 编码 */
  void buildCode() {
    buildCodeByDFS(nvec[0], "");
  }
 
  /* 获取特定字符的编码 */
  string getCode(char ch) { return code[ch]; }
private:
  /* 清空Huffman树，释放资源 */
  void clear(Node* root) {
    if (root != NULL) {
      clear(root->left);
      clear(root->right);
      delete root;
    }
  }
 
  /* 获取结点集中频率最小的结点并将其移出结点集 */
  Node* getMinNodeAndRemoveIt() {
    int min = 0;
    for (int i = 1; i < nvec.size(); ++i) {
      if (nvec[i]->frequency < nvec[min]->frequency) {
        min = i;
      }
    }
    Node* tmp = nvec[nvec.size() - 1];
    nvec[nvec.size() - 1] = nvec[min];
    nvec[min] = tmp;
    tmp = nvec[nvec.size() - 1];
    nvec.pop_back();
    return tmp;
  }
 
  /* 遍历Huffman树进行编码 */
  void buildCodeByDFS(Node* r, string str) {
    if (r->left == NULL && r->right == NULL)
      code[r->ch] = str;
    if (r->left != NULL)
      buildCodeByDFS(r->left, str + "0");
    if (r->right != NULL)
      buildCodeByDFS(r->right, str + "1");
  }
 
  vector<Node*> nvec; // 结点集
  map<char, string> code; // 字符编码
};
 
int main() {
  char ch[100];
  int fq[100], size;
  cin >> size;
  if (size <= 0 || size > 100) {
    cout << "字符集大小不合适" << endl;
    return -1;
  }
 
  for (int i = 0; i < size; ++i) {
    cin >> ch[i] >> fq[i];
  }
 
  HuffmanCode hfmc;
  hfmc.buildTree(ch, fq, size);
  hfmc.buildCode();
 
  string code;
  for (int i = 0; i < size; ++i) {
    code = hfmc.getCode(ch[i]);
    cout << ch[i] << ": " << code << endl;
  }
 
  return 0;
}

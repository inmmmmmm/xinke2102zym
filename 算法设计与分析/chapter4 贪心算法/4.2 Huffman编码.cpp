//���԰�����6 a 5 b 9 c 12 d 13 e 16 f 45 ����� a: 1100 b: 1101 c: 100 d: 101 e: 111 f: 0 
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
 
/* Huffman���Ľڵ� */
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
 
  /* ���� */
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
 
  /* ���� */
  void buildCode() {
    buildCodeByDFS(nvec[0], "");
  }
 
  /* ��ȡ�ض��ַ��ı��� */
  string getCode(char ch) { return code[ch]; }
private:
  /* ���Huffman�����ͷ���Դ */
  void clear(Node* root) {
    if (root != NULL) {
      clear(root->left);
      clear(root->right);
      delete root;
    }
  }
 
  /* ��ȡ��㼯��Ƶ����С�Ľ�㲢�����Ƴ���㼯 */
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
 
  /* ����Huffman�����б��� */
  void buildCodeByDFS(Node* r, string str) {
    if (r->left == NULL && r->right == NULL)
      code[r->ch] = str;
    if (r->left != NULL)
      buildCodeByDFS(r->left, str + "0");
    if (r->right != NULL)
      buildCodeByDFS(r->right, str + "1");
  }
 
  vector<Node*> nvec; // ��㼯
  map<char, string> code; // �ַ�����
};
 
int main() {
  char ch[100];
  int fq[100], size;
  cin >> size;
  if (size <= 0 || size > 100) {
    cout << "�ַ�����С������" << endl;
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

//5
//8
//3 5 1 2 2
//4 5 2 1 3
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
double cw;//当前重量
double cp;//当前价值
double bestp;//当前最优价值
int n;//物品数量
double c;//背包容量
const int N = 105;
struct Bag {
	double w, v;
	int id, x;
};
int bestx[N];
Bag bag[N];
struct BBnode {
	BBnode *parent;
	bool leftChild;
	BBnode(BBnode* par, bool ch) {
		parent = par;
		leftChild = ch;
	}
};
struct heapnode {
	BBnode* livenode;
	double upperprofit;//价值上界
	double profit;//结点价值
	double weight;//结点重量
	int level;//层序号
	bool operator<(const heapnode& b) const {
		return this->upperprofit < b.upperprofit;
	}
	heapnode(BBnode *node,double up, double pp, double ww, int lev) {
		livenode = node;
		upperprofit = up;
		profit = pp;
		weight = ww;
		level = lev;
	}
};

bool cmp(Bag a, Bag b) {
	return (a.v / a.w) > (b.v / b.w);
}
bool cmpbound(heapnode a, heapnode b) {
	return a.upperprofit < b.upperprofit;
}
priority_queue<heapnode, vector<heapnode>,less<heapnode> > q;
void addlivenode(double up, double pp, double ww, int lev, BBnode* par, bool ch) {
	BBnode* b = new BBnode(par, ch);
	heapnode node(b, up, pp, ww, lev);
	q.push(node);
}
double bound(int i) {
	double cleft = c - cw;
	double bd = cp;
	while (i <= n && bag[i].w <= cleft) {
		cleft -= bag[i].w;
		bd += bag[i].v;
		i++;
	}
	if (i <= n)
		bd += bag[i].v * cleft / bag[i].w;
	return bd;
}
void bfs() {
	BBnode *enode = NULL;
	int i = 1;
	bestp = 0;
	double up = bound(1);
	while (i != n + 1) {
		double wt = cw + bag[i].w;
		if (wt <= c) {
			if (cp + bag[i].v > bestp)
				bestp = cp + bag[i].v;
			addlivenode(up, cp + bag[i].v, cw + bag[i].w, i + 1, enode, true);
		}
		up = bound(i + 1);
		if (up > bestp)
			addlivenode(up, cp, cw, i + 1, enode, false);
		heapnode node = q.top();
		q.pop();
		enode = node.livenode;
		cw = node.weight;
		cp = node.profit;
		up = node.upperprofit;
		i = node.level;
	}
	for (int j = n; j > 0; j--) {
		bag[j].x = (enode->leftChild!=NULL) ? 1 : 0;
		enode = enode->parent;
	}
	for (int i = 1; i <= n; i++)
		bestx[bag[i].id] = bag[i].x;
	return;
}
int main() {
	cout<<"请输入物品数量和背包容量："<<endl; 
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
		cin >> bag[i].w;
	for (int i = 1; i <= n; i++)
		cin >> bag[i].v;
	for (int i = 1; i <= n; i++)
		bag[i].id = i;
	sort(bag + 1, bag + 1 + n, cmp);
	bfs();
	cout << bestp << endl;
	for (int i = 1; i <= n; i++)
		cout << bestx[i] << " ";
	return 0;
}


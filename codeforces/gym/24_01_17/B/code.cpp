#include <algorithm>
#include <iostream>
#include <assert.h>
#include <cmath>
#include <map> 
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX = 1e9+7;
const int MIN = -1e9+7;

struct node{
	int key = 0;
	int p = 0; //priority
	int size = 1; //number of nodes in subtree
	int cost = (int) MIN;
	node *left = NULL;
	node *right = NULL;
	node *parent = NULL;
	node(): left(NULL), right(NULL), parent(NULL){
		p = rand() % (int)MAX;
	}	
	node(int key): key(key), left(NULL), right(NULL), parent(NULL){
		p = rand() % (int)MAX;
	}
	node(int key, int cost): key(key), cost(cost), left(NULL), right(NULL), parent(NULL){
		p = rand() % (int)MAX;
	}
	static void set_right_parent(node *child, node *parent){
		if (parent == NULL) return;
		parent->right = child;
		if (child != NULL) child->parent = parent;
	}	
	static void set_left_parent(node *child, node *parent){
		if (parent == NULL) return;
		parent->left = child;
		if (child != NULL) child->parent = parent;
	}
	static void recalc(node *n){
		if (n == NULL) return;
		int total = 1;
		if (n->left != NULL){ 
			total += n->left->size;
		}
		if (n->right != NULL){ 
			total += n->right->size;
		}
		n->size = total;
	}
	static int sizeOf(node *n){
		if (n == NULL) return 0;
		else return n->size;
	}
};

class Treap{
public:
	Treap():root(NULL) {
	}
	Treap(node *root): root(root) {
	}
	~Treap() { }
	void insert(int x, int cost){
		node *l;
		node *r;
		Treap::split(root, x, l, r);
		node *n = new node(x, cost);
		root = Treap::merge(l, n);
		root = Treap::merge(root, r);
	}
	void remove(int x){
		node *l;
		node *r;
		Treap::split(root, x-1, l, r);
		node *ml;
		node *mr;
		Treap::split(r, x, ml, mr);
		root = Treap::merge(l, mr);
	}
	node* find_kth(int k){
		node *cur = root;
		while(cur != NULL){
			int size = node::sizeOf(cur->left);
			if (size == k){
				break;
			}
			else if (size > k){
				cur = cur->left;
			} else {
				cur = cur->right;
				k -= size + 1;
			}
		}
		return cur;
	}
private:
	node *root = NULL;
	static void split(node *cur, int key, node* &l, node* &r){
		if (cur == NULL) {
			l = NULL;
			r = NULL;
			return;
		}
		if (cur->key > key){
			node *newr = NULL;
			if (cur->left == NULL){
				l = NULL;
			}
			else {
				Treap::split(cur->left, key, l, newr);
			}	
			node::set_left_parent(newr, cur);
			r = cur;
			node::recalc(r);
		}
		else {
			node *newl = NULL;
			if (cur->right == NULL){
				r = NULL;
			}
			else {
				Treap::split(cur->right, key, newl, r);
			}
			node::set_right_parent(newl, cur);
			l = cur;
			node::recalc(l);
		}
	}
	static node* merge(node *l, node *r){
		if (l == NULL) return r;
		if (r == NULL) return l;
		if (l->key > r->key) swap(l, r);
		if (l->p > r->p){
			node *right = Treap::merge(l->right, r);
			node::set_right_parent(right, l);
			node::recalc(l);
			return l;
		}
		else {
			node *left = Treap::merge(l, r->left);
			node::set_left_parent(left, r);
			node::recalc(r);
			return r;
		}
		return NULL;
	}
};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int j = 0; j < t; j++){
		cout << "Case " << (j+1) << ":" << endl;
		int n;
		cin >> n;
		map<int, int> idmap;
		Treap t;
		int start = 0;
		int end = 1;
		for(int i = 0; i < n; i++){
			int type; char val;
			cin >> type;
			if (type == 1){
				int id;
				cin >> val;
				cin >> id;
				if (val == 'B'){
					t.insert(end, id);
					idmap[id] = end;
					end++;
				}
				if (val == 'F'){
					t.insert(start, id);
					idmap[id] = start;
					start--;
				}
			}
			if (type == 2){
				cin >> val;
				if (val == 'B'){
					end--;
					t.remove(end);
				}
				if (val == 'F'){
					start++;
					t.remove(start);
				}
			}
			if (type == 3){
				cin >> val;
				int k;
				cin >> k;
				if (val == 'D'){
					cout << t.find_kth(k-1)->cost << endl;
				}
				if (val == 'P'){
					cout << (idmap[k]-start) << endl;
				}
			}
		}
	}
	return 0;
}

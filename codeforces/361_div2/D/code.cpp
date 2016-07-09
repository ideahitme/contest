#include <algorithm>
#include <iostream>
#include <assert.h>
#include <cmath>

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
	ll total_cost = (ll) MIN; //total of costs in subtree
	int max_cost = (int) MIN;
	int min_cost = (int) MAX;
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
		total_cost = (ll)cost;
		max_cost = cost;
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
		int total_cost = (ll)n->cost;
		int max_cost = n->cost;
		int min_cost = n->cost;
		if (n->left != NULL){ 
			total += n->left->size;
			total_cost += n->left->total_cost;
			max_cost = max({max_cost, n->left->max_cost});
			min_cost = min({min_cost, n->left->min_cost});
		}
		if (n->right != NULL){ 
			total += n->right->size;
			total_cost += n->right->total_cost;
			max_cost = max({max_cost, n->right->max_cost});
			min_cost = min({min_cost, n->right->min_cost});
		}
		n->size = total;
		n->total_cost = total_cost;
		n->max_cost = max_cost;
		n->min_cost = min_cost;
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
	ll total_cost(int l, int r){
		node *fl;
		node *fr;
		Treap::split(root, l-1, fl, fr);
		node *ml;
		node *mr;
		Treap::split(fr, r, ml, mr);
		ll res = ml->total_cost;
		root = Treap::merge(ml, mr);
		root = Treap::merge(root, fl);
		return res;
	}	
	int max_cost(int l, int r){
		node *fl;
		node *fr;
		Treap::split(root, l-1, fl, fr);
		node *ml;
		node *mr;
		Treap::split(fr, r, ml, mr);
		ll res = ml->max_cost;
		root = Treap::merge(ml, mr);
		root = Treap::merge(root, fl);
		return res;
	}	
	int min_cost(int l, int r){
		node *fl;
		node *fr;
		Treap::split(root, l-1, fl, fr);
		node *ml;
		node *mr;
		Treap::split(fr, r, ml, mr);
		ll res = ml->min_cost;
		root = Treap::merge(ml, mr);
		root = Treap::merge(root, fl);
		return res;
	}
	void traverse(){
		inorder(root);
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
			else Treap::split(cur->right, key, newl, r);
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
	void inorder(node *cur){
		if (cur == NULL) return;
		inorder(cur->left);
		inorder(cur->right);
	}
};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	Treap a;
	Treap b;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.insert(i, x);
	}
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		b.insert(i, x);
	}
	ll total = 0;
	for(int i = 0; i < n; i++){
		j=i;
		while (a.max_cost(i, j) == b.min_cost(i, j)){
			total++;
			j++;
		}
	}
	/* code */
	return 0;
}

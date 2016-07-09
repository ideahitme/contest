//------------------------------------------------------------------------------
// Author: Lukasz Janyst <lukasz@jany.st>
//------------------------------------------------------------------------------

#include <cstdio>
#include <string>
#include <iostream>
#include <cstdint>

//------------------------------------------------------------------------------
//! An implementatino of rope base on a splay tree
//------------------------------------------------------------------------------
class Rope {
  public:

    //--------------------------------------------------------------------------
    //! Constructor
    //--------------------------------------------------------------------------
    Rope(const std::string &s) : pS(s)
    {
      pRoot = new Node();
      pRoot->length = pS.length();
      pRoot->total_length = pRoot->length;
    }

    //--------------------------------------------------------------------------
    //! Cut the part between i and j indices and paste it before k index
    //--------------------------------------------------------------------------
    void process(int i, int j, int k)
    {
      Node *n, *t, *left, *right = 0;
      STSplit(left, n, i, pRoot);
      if(j+1 < pS.length())
        STSplit(n, right, j+1-i, n);
      t = STMerge(left, right);
      if(k < (t->offset + t->total_length))
        STSplit(left, right, k, t);
      else {
        right = 0;
        left = t;
      }
      pRoot = STMerge(left, n);
      pRoot = STMerge(pRoot, right);
    }

    //--------------------------------------------------------------------------
    //! Return the resulting string
    //--------------------------------------------------------------------------
    std::string result()
    {
      std::string result;
      STTraverse(pRoot, result, pS);
      return result;
    }

  private:

    //--------------------------------------------------------------------------
    //! Tree node
    //--------------------------------------------------------------------------
    struct Node {
      Node(): start(0), offset(0), length(0), parent(0), left(0), right(0) {}
      uint32_t start;          //!< Start position in the original string
      uint32_t offset;         //!< Offset from the leftmost child of the
                               //!< sub-tree
      uint32_t length;         //!< Length of the chunk represented by the node
      uint32_t total_length;   //!< Sum of length of the chunk and all the
                               //!< right-hand children
      Node *parent;            //!< parent
      Node *left;              //!< left child
      Node *right;             //!< rigth child
    };

    //--------------------------------------------------------------------------
    //! Find the node at given offset in the current tree
    //--------------------------------------------------------------------------
    static Node *Find(uint32_t offset, Node *root)
    {
      if(!root)
        return 0;
      if(offset >= root->offset && offset < (root->offset + root->length))
        return root;
      if(offset < root->offset)
        return Find(offset, root->left);
      return Find(offset-root->offset-root->length, root->right);
    }

    //--------------------------------------------------------------------------
    //! Find a node containing the offset, split it if it does not start
    //! with the offset and splay it to the top of the tree
    //--------------------------------------------------------------------------
    static Node *STFind(uint32_t offset, Node *root)
    {
      Node *n = Find(offset, root);
      Splay(n);

      if(n->offset < offset) {
        Node *newNode = new Node();
        newNode->start  = n->start;
        newNode->length = offset - n->offset;
        n->start  = newNode->start + newNode->length;
        n->length -= newNode->length;
        newNode->left = n->left;
        update(newNode);
        n->left = newNode;
        update(n);
      }
      return n;
    }

    //--------------------------------------------------------------------------
    //! Split the tree such that the left subtree contains the part of the
    //! string prior to the current offset and the right sub-tree represent
    //! the string starting with the offset
    //--------------------------------------------------------------------------
    static void STSplit(Node *&left, Node *&right, uint32_t offset, Node *root)
    {
      if(!root) {
        left = 0;
        right = 0;
        return;
      }
      Node *n = STFind(offset, root);
      left = n->left;
      if(left)
        left->parent = 0;
      right = n;
      right->left = 0;
      update(right);
    }

    //--------------------------------------------------------------------------
    //! Merge two trees
    //--------------------------------------------------------------------------
    static Node *STMerge(Node *left, Node *right)
    {
      if(!left)
        return right;
      Node *root = FindLast(left);
      Splay(root);
      root->right = right;
      update(root);
      return root;
    }

    //--------------------------------------------------------------------------
    //! Find the node representing the last chunk of the string
    //--------------------------------------------------------------------------
    static Node *FindLast(Node *root)
    {
      if(!root)
        return 0;
      Node *ret = root;
      while(root) {
        ret = root;
        root = root->right;
      }
      return ret;
    }

    //--------------------------------------------------------------------------
    //! Compute new offset and total length of the current node based on the
    //! values stored in its children
    //--------------------------------------------------------------------------
    static void update(Node *n) {
      if(!n)
        return;
      n->offset = 0;
      n->total_length = n->length;

      if(n->left) {
        n->left->parent = n;
        n->offset = n->left->offset + n->left->total_length;
      }

      if(n->right) {
        n->right->parent = n;
        n->total_length  += n->right->total_length + n->right->offset;
      }
    }

    //--------------------------------------------------------------------------
    //! Zig
    //--------------------------------------------------------------------------
    static void zig(Node *n)
    {
      if(!n->parent)
        return;

      Node *parent = n->parent;
      Node *grandparent = n->parent->parent ? n->parent->parent : 0;
      Node *tmp;
      if(parent->left == n) {
        tmp = n->right;
        n->right = parent;
        parent->left = tmp;
      }
      else {
        tmp = n->left;
        n->left = parent;
        parent->right = tmp;
      }

      update(parent);
      update(n);

      if(grandparent) {
        if(grandparent->left == parent)
          grandparent->left = n;
        else
          grandparent->right = n;
      }
      n->parent = grandparent;
      update(grandparent);
    }

    //--------------------------------------------------------------------------
    //! Either Zig-Zig or Zig-Zag, depending on the case
    //--------------------------------------------------------------------------
    static void zigZigZag(Node *n)
    {
      if((n->parent->left == n && n->parent->parent->left == n->parent) ||
         (n->parent->right == n && n->parent->parent->right == n->parent)) {
        zig(n->parent);
        zig(n);
      }
      else {
        zig(n);
        zig(n);
      }
    }

    //--------------------------------------------------------------------------
    //! Splay the node to the root of the tree
    //--------------------------------------------------------------------------
    static void Splay(Node *n)
    {
      if(!n)
        return;
      while(n->parent) {
        if(!n->parent->parent) {
          zig(n);
          break;
        }
        zigZigZag(n);
      }
    }

    //--------------------------------------------------------------------------
    //! Traverse the tree in-order to reconstruct the resulting string
    //--------------------------------------------------------------------------
    static void STTraverse(Node *root, std::string &result,
      const std::string &source)
    {
      if(!root)
        return;
      STTraverse(root->left, result, source);
      result += source.substr(root->start, root->length);
      STTraverse(root->right, result, source);
    }

    Node        *pRoot;      //!< Root of the tree
    std::string  pS;         //!< The source string
};

//------------------------------------------------------------------------------
// Start the show
//------------------------------------------------------------------------------
int main()
{
  std::ios_base::sync_with_stdio(0);
  int len;
  std::cin >> len;
  std::string s(len, 'a');
  for(int i = 0; i < len; i++){
  	char x;
  	std::cin >> x;
  	s[i] = x;
  }
  Rope rope(s);
  int actions;
  std::cin >> actions;
  for(int action_index = 0; action_index < actions; ++action_index) {
  	std::cout << action_index << " ";
    int i, j;
    std::cin >> i >> j;
    rope.process(i-1, j-1, 0);
  }
  std::string res = rope.result();
  for(int i = 0; i < res.length(); i++){
  	std::cout << res[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}

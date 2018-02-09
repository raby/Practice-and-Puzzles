#include <iostream>

using namespace std;

class sbt {
  private:
    struct node {
      int val;
      node* left;
      node* right;
      int h;
      node(int v_) : val(v_),left(NULL),right(NULL),h(0) {}
    };
    void printTree(node* node) {
      if(node->left)
         printTree(node->left);
      cout<<"{v:"<< node->val<<", h: "<<node->h<<"}"<<endl;
      if(node->right)
         printTree(node->right);
    }
    node* root;

    public:
      void addNode(int v_) {
        if(!root)
          root = new node(v_);
        else {
          node* temp = new node(v_);
          node* cur = root;
          node* prev = NULL;
          node* prevprev = NULL;
          while(cur) {
            if(prev)
                prevprev = prev;
            temp->h = temp->h + 1;
            if(temp->val < cur->val) {
              prev = cur;
              cur = cur->left;
            }
            else if(temp->val >= cur->val) {
              prev = cur;
              cur = cur->right;
            }
          }
          (temp->val < prev->val) ? prev->left = temp : prev->right = temp;
          //now rebalance tree//
          if(prevprev && (prevprev->left==NULL || prevprev->right==NULL) && ((temp->h - prevprev->h) >= 2) ) {
            cout<<"Namaste, balance the tree."<<endl;
            //case 1: smaller smaller
            if(!prevprev->right && !prev->right) {
              //balance
              prevprev->right = new node(prevprev->val);
              prevprev->right->h = prevprev->h + 1;
              prevprev->val = prev->val;
              prev->val = temp->val;
              //prune
              temp = prev->left;
              prev->left = NULL;
              delete temp;
            }
            //case 2: larger larger
            else if(!prevprev->left && !prev->left) {
              prevprev->left = new node(prevprev->val);
              prevprev->left->h = prevprev->h + 1;
              prevprev->val = prev->val;
              prev->val = temp->val;
              temp = prev->right;
              prev->right = NULL;
              delete temp;
            }
            //case 3: larger smaller
            else if(!prevprev->left && !prev->right) {
              prevprev->left = new node(prevprev->val);
              prevprev->left->h = prevprev->h + 1;
              prevprev->val = temp->val;
              prev->left = NULL;
              delete temp;
            }
            //case 4: smaller larger
            else if(!prevprev->right && !prev->left) {
              prevprev->right = new node(prevprev->val);
              prevprev->right->h = prevprev->h + 1;
              prevprev->val = temp->val;
              prev->right = NULL;
              delete temp;
            }
          }
        }
      }
      void print() {
         printTree(root);
      }
};

int main() {
  sbt test;
  test.addNode(10); //0
  test.addNode(5); //1
  test.addNode(15);  //1
  test.addNode(3);  //2
  test.addNode(8);  //2
  test.addNode(20);  //2
  test.addNode(12);  //2
  cout<<"case 1: smaller smaller."<<endl;
  test.addNode(2); //3
  test.addNode(1); //4
  cin.get();
  cout<<"case 2: larger larger."<<endl;
  test.addNode(21); //3
  test.addNode(22); //4
  cin.get();
  cout<<"case 3: larger smaller."<<endl;
  test.addNode(14);  //3
  test.addNode(13);  //4
  cin.get();
  cout<<"case 4: smaller larger."<<endl;
  test.addNode(6);  //3
  test.addNode(7);  //4
  cin.get();

  test.print();
  return 0;
}

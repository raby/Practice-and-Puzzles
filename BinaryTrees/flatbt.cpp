#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
   struct node {
      int v;
      node* l;
      node* r;
      node(int v_) : v(v_),l(NULL),r(NULL) {};
   };

class bt {
 private:
   void proutine(node* n) {
      if(n->l)
        proutine(n->l);
      cout<<n->v<<" ";
      if(n->r)
        proutine(n->r);
   }
   node* aroutine(const int& v_,node* n) {
     if( n->l && (v_ < n->v) ) {
       aroutine(v_, n->l);
     }
     else if( n->r && (v_ >= n->v) )
       aroutine(v_, n->r);
     else
       return n;
   }
  public:
    node* root;
    bt() {
      root = NULL;
    }
    void print() {
      cout<<"Printing tree: "<<endl;
      proutine(root);
      cout<<endl;
    }
    void add(int v_) {
      if(!root) {
        root = new node(v_);
      }
      else {
        node* t = aroutine(v_,root);
        (v_ < t->v) ? t->l = new node(v_) : t->r = new node(v_);
       }
    }
    void flat() {
      node* walker = root;
      node* s = NULL;
      node* f = NULL;
      node* ms = NULL;
      node* mf = NULL;
      while(walker) {
        s = walker;
        f = walker->r;
        if(walker->l) {
          ms = walker->l;
          mf = walker->l;
          while(mf->r) {
            mf = mf->r;
          }
          mf->r = f;
          s->r = ms;
          walker->l = NULL;
        }
        walker = walker->r;
      }
    }
};

int main() {

  bt b;
  srand(time(NULL));
//  for(int i=0; i<10; i++) {
//    b.add(rand()%100);
//  }
  b.add(10);
  b.add(5);
  b.add(15);
  b.add(17);
  b.add(12);
  b.add(7);
  b.add(6);

  b.print();
  b.flat();
  node* l = b.root;

  b.print();
  return 0;
}

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class bt {
  private:
    struct node {
       int v;
       node* l;
       node* r;
       node(int v_) : v(v_), l(NULL), r(NULL) {};
    };
    void btPrint(node* n) {
      if(n->l)
        btPrint(n->l);
      cout<<n->v<<" ";
      if(n->r)
        btPrint(n->r);
    }
  public:
   node* root;
   bt() { root = NULL; }
   void bt_rec_print(){
     cout<<"Printing tree recurssively: "<<endl;
     btPrint(root);
     cout<<endl;
   }
   void bt_left_print() {
     cout<<"Printing tree by left node: "<<endl;
     node* t = root;
     node* s = t;
     cout<<t->v<<" ";
     t = t->l;
     while(t != s) {
       cout<<t->v<<" ";
       t = t->l;
     }
     cout<<endl;
   }
   void bt_right_print() {
     cout<<"Printing tree by right node: "<<endl;
     node* t = root;
     node* s = t;
     cout<<t->v<<" ";
     t = t->r;
     while(t != s) {
       cout<<t->v<<" ";
       t = t->r;
     }
     cout<<endl;
   }
   void add(int v_) {
     if(!root)
       root = new node(v_);
     else {
       node* r = root;
       while(r) {
         if(r->l && v_ < r->v ) {
           r = r->l;
         }
         else if( v_ < r->v ) {
           r->l = new node(v_);
           break;
         }
         else if(r->r && v_ >= r->v ) {
           r = r->r;
         }
         else if( v_ >= r->v ) {
           r->r = new node(v_);
           break;
         }
       }
     }
   }
   void flatten2dll() {
     node* wp = NULL;
     node* w = root;
     node* ms = NULL;
     node* mf = NULL;
     while(w) {
      if(w->r) {
        ms = w->r;
        mf = w->r;
        while(mf->l) {
          mf = mf->l;
        }
        mf->l = w;
        if(wp) {
          wp->l = ms;
        }
        else if(!wp) {
          root = ms;
        }
        w->r = NULL;
        w = ms;
      }
      wp = w;
      w = w->l;
     }
   }
};

int main() {
  srand(time(NULL));
  bt b;
//  for(int i=0;i<10;i++) {
//    b.add(rand()%100);
//  }
  b.add(10);
  b.add(15);
  b.add(5);
  b.add(7);
  b.add(6);
  b.add(12);
  b.add(17);
  b.bt_rec_print();
  b.flatten2dll();
  b.bt_rec_print();
  return 0;
}

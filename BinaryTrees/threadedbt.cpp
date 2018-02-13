#include <iostream>
#include <vector>

using namespace std;

struct node {
    node* l;
    node* r;
    int v;
    bool t;
    node(int v_) : v(v_), l(NULL), r(NULL), t(0) {};
};

class queue {
  private:
    struct item {
       node* val;
       item* next;
       item* prev;
       item(node* v_) : val(v_), next(NULL), prev(NULL) {};
    };
    item* front;
    item* rear;
  public:
    queue() {
      front = NULL;
      rear = NULL;
    }
    void push(node* n) {
      item* temp = new item(n);
      if(!front) {
        front = temp;
        rear = temp;
      }
      else {
        temp->next = rear;
        rear->prev = temp;
        rear = temp;
      }
    }
    bool empty() {
      return (!front && !rear) ? 1 : 0;
    }
    void pop() {
      item* temp = front;
      if(rear == front) {
        rear = NULL;
        front = NULL;
      }
      else {
        front = front->prev;
        front->next = NULL;
      }
      if(temp)
        delete temp;
    }
    node* top() {
      return front->val;
    }
    void print_next() {
       cout<<"Printing next via front: "<<endl<<"[ ";
       item* temp = front;
       while(temp) {
         cout<<temp->val->v<< " ";
         temp = temp->next;
       }
       cout<<"]"<<endl;
       temp = rear;
       cout<<"Printing next via rear: "<<endl<<"[ ";
       while(temp) {
         cout<<temp->val->v<< " ";
         temp = temp->next;
       }
       cout<<"]"<<endl;
    }
    void print_prev() {
       cout<<"Printing prev via front: "<<endl<<"[ ";
       item* temp = front;
       while(temp) {
         cout<<temp->val->v<< " ";
         temp = temp->prev;
       }
       cout<<"]"<<endl;
       cout<<"Printing prev via rear: "<<endl<<"[ ";
       temp = rear;
       while(temp) {
         cout<<temp->val->v<< " ";
         temp = temp->prev;
       }
       cout<<"]"<<endl;
    }
};


class bt {
  private:
    void hp(node* n) {
      if(n->l)
        hp(n->l);
      cout<<n->v<<" ";
      if(n->r)
        hp(n->r);
    }
  public:
    node* root;
    bt() {
      root = NULL;
    }
    void add(int v_) {
      if(!root) {
        root = new node(v_);
      }
      else {
        node* w = root;
        node* p = NULL;
        while(w) {
          p = w;
          (v_ < w->v) ? w = w->l : w = w->r;
        }
        ( v_ < p->v) ? p->l = new node(v_) : p->r = new node(v_);
      }
    }
    void print() {
      cout<<"Printing tree:"<<endl<<"[ ";
      hp(root);
      cout<<"]"<<endl;
    }
    void thread() {
      queue q;
      q.push(root);
      node* rw = root;
      while(!q.empty()) {
        node* t = q.top();
        q.pop();
        if(t->l) {
          q.push(t->l);
          node* w = t->l;
          while(w->r) {
            if(w->l && w!=t->l) {
              q.push(w);
            }
            w = w->r;
          }
          w->r = t;
          w->t = 1;
        }
        if(q.empty() && rw->r) {
          rw = rw->r;
          q.push(rw);
        }
      }
    }
    void print_thread() {
      node* w = root;
       cout<<"Printing threaded binary tree:"<<endl<<"[ ";
      while(w) {
         while(w->l)
          w = w->l;
         cout<<w->v<<" ";
         if(w->t == 1) {
           w = w->r;
           cout<<w->v<<" ";
           w = w->r;
         }
         else
           w = w->r;
      }
      cout<<"]"<<endl;
    }
};

int main() {
  bt b;
  b.add(10);
  b.add(15);
  b.add(13);
  b.add(12);
  b.add(14);
  b.add(7);
  b.add(8);
  b.add(2);
  b.add(1);
  b.add(4);
  b.add(3);
  b.add(5);
  b.add(6);
  b.print();

  b.thread();
  b.print_thread();

  return 0;
}

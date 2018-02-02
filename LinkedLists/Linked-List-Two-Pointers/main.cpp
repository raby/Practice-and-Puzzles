#include <iostream>

using namespace std;

class LinkedList {
  struct node {
    int val;
    node* next;
    node(int v_) : val(v_), next(NULL) {};
  };

  node* front;
  node* back;

  public:
  void insertFront(int v_) {
    if(!front) {
      front = new node(v_);
      back = front;
    }
    else {
      node* temp = new node(v_);
      temp->next = front;
      front = temp;
    }
  }

  void insertBack(int v_) {
    if(!back) {
      back = new node(v_);
      front = back;
    }
    else {
      node* temp = new node(v_);
      back->next = temp;
      back = back->next;
    }
  }

  void print() {
    node* temp = front;
    cout<<"list: [";
    while(temp->next) {
      cout<<temp->val<<", ";
      temp = temp->next;
   }
   cout<<temp->val<<"]"<<endl;
  }

};

int main() {
  LinkedList ll;
  ll.insertFront(1);
  ll.insertFront(2);
  ll.insertBack(3);
  ll.insertBack(4);
  ll.insertFront(5);
  ll.print();
  return 0;
}

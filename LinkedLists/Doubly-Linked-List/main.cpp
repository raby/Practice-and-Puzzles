#include <iostream>

using namespace std;

class DoubleLinkedList {

  struct node {
    int val;
    node* next;
    node* prev;
    node(int v_) : val(v_), next(NULL), prev(NULL) {};
  };

  node* head;

  public:

    void insertOrderedNode(int v_) {
      if(!head) {
        head = new node(v_);
      }
      else {
        node* runner = head;
	node* prev_runner = NULL;
        while(runner) {
          if( v_ < runner->val )
            break;
          prev_runner = runner;
          runner = runner->next;
        }
        node* temp = new node(v_);
        if(!runner) {//case when v_ has the greatest value in the list
	  prev_runner->next = temp;
        }
        else {//case when v_ has the lowest or middle value in the list
          temp->next = runner;
	  runner->prev = temp;
        }
        if(!prev_runner) {
           head = temp;//case that v_ is the lowest value
        }
        else {
           prev_runner->next = temp; //case that v_ is a middle value
        }
        temp->prev = prev_runner;
      }
    }

    void print() {
      node* temp = head;
      cout<<"Printing list via next pointers: "<<endl<<"[";
      while(temp->next) {
        cout<<temp->val<< ", ";
        temp = temp->next;
      }
      cout<<temp->val<<"]"<<endl;
      cout<<"Printing list via prev pointers: "<<endl<<"[";
      while(temp->prev) {
        cout<<temp->val<<", ";
        temp = temp->prev;
      }
      cout<<temp->val<<"]"<<endl;
    }

};

int main() {
  DoubleLinkedList dll;
  dll.insertOrderedNode(5); //create list
  dll.insertOrderedNode(4); //insert smallest value
  dll.insertOrderedNode(6); //insert greatest value
  dll.insertOrderedNode(8); //prep to insert middle value
  dll.insertOrderedNode(7); //insert a middle value
  dll.print();

  return 0;
}

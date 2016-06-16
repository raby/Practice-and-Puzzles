/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
 NOTE : If you are using your own declared global variables, make sure to clear them out in the 
 */

 vector<int> m;
vector<int> stck;
int i;
int j;

MinStack::MinStack() {
    m.clear();
    stck.clear();
    i = -1;
    j = -1;
}

void MinStack::push(int x) {
    m.push_back(x);
    i++;
    
    if(!stck.empty() && x<stck[j] )
    {
        stck.push_back(x);
        j++;
    }
    else if(stck.empty())
    {
        stck.push_back(x);
        j++;
    }
}

void MinStack::pop() {
    if(!stck.empty() && m[i]==stck[j])
    {
        stck.pop_back();
        j--;
    }
    if(!m.empty())
    {
        m.pop_back();
        i--;
    }
}

int MinStack::top() {
    if(!m.empty())
        return m[i];
    else if(m.empty())
        return i;
}

int MinStack::getMin() {
    if(!stck.empty())
        return stck[j];
    else if(stck.empty())
        return j;
}


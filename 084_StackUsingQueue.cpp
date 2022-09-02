#include<bits/stdc++.h>

// Method 1 : Implementing stack using one queue

class Stack {
	// Define the data members.
    queue<int> q;
    int siz;
   public:
    Stack() {
        // Implement the Constructor.
        siz = -1;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return (q.empty());
    }

    void push(int element) {
        // Implement the push() function.
        siz++;
        q.push(element);
        for(int i=0; i<siz; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        if(!q.empty())
        {
            int popped = q.front();
            q.pop();
            siz--;
            return popped;
        }
        else 
            return -1;
    }

    int top() {
        // Implement the top() function.
        if(!q.empty())
        {
            return q.front();
        }
        else 
            return -1;
    }
};



/*
// Mathod 2 : Implementing stack using two queues
1. When the queue size becomes 1 thats the last element of 
queue means top element of stack
*/
#include<bits/stdc++.h>
class Stack {
    // Define the data members.
    queue<int> q1;
    queue<int> q2;

   public:
    Stack() {
        // Implement the Constructor.      
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q1.empty();
    }

    void push(int element) {
        // Implement the push() function.
        q1.push(element);
    }

    int pop() {
        // Implement the pop() function.
        if(q1.empty())
        {
            return -1;
        }
        
        while(q1.size() != 1) // last element of queue uptill then keep pushing in q2.
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        int ans = q1.front(); //this is the top of stack (last of queue).
        q1.pop();  // popped remove and dont add in q2.

        while(!q2.empty())
        {
            q1.push(q2.front()); //refill the q1
            q2.pop();
        }

        return ans;
    }

    int top() {
        // Implement the top() function.
        if(q1.empty())
            return -1;
        
        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(q1.front());
        q1.pop();
        
        while(!q2.empty())
        {
            q1.push(q2.front()); //refill q1.
            q2.pop();
        }
        
        return ans;
    }
};

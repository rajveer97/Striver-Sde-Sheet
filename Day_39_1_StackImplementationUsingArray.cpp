// Stack class.
class Stack {
    int *arr;
    int topp;
    int size;
public:
    
    Stack(int capacity) 
    {
        // Write your code here.
        this->size = capacity;
        arr = new int[size];
        topp = -1;
    }

    void push(int num) 
    {
        // Write your code here.
        if(size - topp != 1) 
        {
            topp++;
        }
        arr[topp] = num;
    }

    int pop() 
    {
        // Write your code here.
        if(topp != -1)
        {
            int x = arr[topp];
            topp--;
            return x;
        }
        else
            return -1;
    }
    
    int top() 
    {
        // Write your code here.
        if(topp != -1)
        {
            int x = arr[topp];
            return x;
        }
        else 
            return -1;
    }
    
    int isEmpty() 
    {
        // Write your code here.
        if(topp == -1)
            return 1;
        else
            return 0;
    }
    
    int isFull() 
    {
        // Write your code here.
        if(size - topp == 1)
            return 1;
        else 
            return 0;
    }  
};
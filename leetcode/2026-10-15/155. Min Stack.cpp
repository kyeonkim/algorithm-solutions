/*
목적은 getMin 메서드를 호출했을때 0(1)로 현재 최소값을 반환하는 것

예를 들어, 최솟값이 -2 > -3으로 바뀐 상태에서 -3을 pop할 경우 다시 -2가 최솟값으로 반환되어야한다
따라서, 실제 값을 저장하는 스택과 최솟값을 저장하는 스택 2개를 만든다
실제 값을 저장하는 스택에 push할 때 최솟값 스택 top과 비교하여 작거나 같으면 해당 스택에도 push한다
실제 값 스택에서 pop하기 전에 top이 최솟값 스택 top과 같다면 최솟값 스택을 먼저 pop해준다
getMin은 최솟값 스택의 top을 반환한다(문제에서 빈 스택에서는 부르지 않는다고 했으니 빈 값 처리는 따로하지 않는다) 
*/
class MinStack {
private:
    stack<int> newStack;
    stack<int> minStack;
public:
    MinStack() {}
    
    void push(int value) {
        newStack.push(value);
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }
    
    void pop() {
        if (newStack.top() == minStack.top()) {
            minStack.pop();
        }
        newStack.pop();
    }
    
    int top() {
        return newStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
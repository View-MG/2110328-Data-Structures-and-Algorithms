#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        CP::stack<T> tmp;
        while(!empty()){
            tmp.push(top());
            pop();
        }
        while(!s.empty()){
            tmp.push(s.top());
            s.pop();
        }
        while(!tmp.empty()){
            push(tmp.top());
            tmp.pop();
        }

    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        CP::stack<T> tmp,tmp2;
        while(!q.empty()){
            tmp.push(q.front());
            q.pop();
        }
        while(!this->empty()){
            tmp2.push(this->top());
            this->pop();
        }
        while(!tmp.empty()){
            this->push(tmp.top());
            tmp.pop();
        }
        while(!tmp2.empty()){
            this->push(tmp2.top());
            tmp2.pop();
        }
        
        
    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        ensureCapacity(mSize+s.size());
        while(!s.empty()){
            push(s.top());
            s.pop();
        }
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        while(!q.empty()){
            push(q.front());
            q.pop();
        }
    }
}

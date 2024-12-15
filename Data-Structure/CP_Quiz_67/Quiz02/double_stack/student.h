#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"


template <typename T>
void balanceStack(std::stack<T> &stack_a , std::stack<T> &stack_b){
	std::stack<T> tmp;
	if(stack_b.empty()){
		for(int i{0}; i < stack_a.size()/2; i++){
			tmp.push(stack_a.top()); 
			stack_a.pop();
		}
		while(!stack_a.empty()){
			stack_b.push(stack_a.top()); 
			stack_a.pop();
		}
		while(!tmp.empty()){
			stack_a.push(tmp.top()); 
			tmp.pop();
		}
	}
}

void CP::stack<T>::pop() {
	balanceStack(stack_b, stack_a);
	stack_a.pop();
}
const T& CP::stack<T>::top() {
	balanceStack(stack_b, stack_a);
	return stack_a.top();
}
const T& CP::stack<T>::bottom() {
	balanceStack(stack_a, stack_b);
	return stack_b.top();
}
void CP::stack<T>::push_bottom(const T& element) {
	stack_b.push(element);
}
void CP::stack<T>::pop_bottom() {
	balanceStack(stack_a, stack_b);
	stack_b.pop();

}
#endif
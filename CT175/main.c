#include "stack.c"

int main(){
	Stack s;
	make_null_stack(&s);
	push(&s,5);
	printf("%d",s.data[0]);
}

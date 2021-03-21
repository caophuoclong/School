#include "stack.c"

int main(){
    Stack s;
    int x;
    make_null_stack(&s);
    push(&s,3);
    x = top(&s);
    printf("%d",x);
    return 0;
}
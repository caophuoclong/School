List readSet(){
    List L;
    makenullList(&L);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        if(!member(x,&L))
            addFrist(x,&L);
    }
    return L;
}
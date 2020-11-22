
int tim(char x[10],  List L){
    for (int i = 0; i < L.Last;i++){
        if (strcmp(x,L.SinhVien[i].MSSV) == 0)
            return i;
    }
    return L.Last+1;
}
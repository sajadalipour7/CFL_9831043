#include <stdio.h>
#include <stdlib.h>
int xchecker(int a[3][3]){
    if(a[0][0]==a[0][1] && a[0][1]==a[0][2] && a[0][0]==1)
        return 1;
    else if(a[0][0]==a[1][0] && a[1][0]==a[2][0] && a[0][0]==1)
        return 1;
    else if(a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[0][0]==1)
        return 1;
    else if(a[1][0]==a[1][1] && a[1][1]==a[1][2] && a[1][0]==1)
        return 1;
    else if(a[2][0]==a[2][1] && a[2][1]==a[2][2] && a[2][0]==1)
        return 1;
    else if(a[0][1]==a[1][1] && a[1][1]==a[2][1] && a[0][1]==1)
        return 1;
    else if(a[0][2]==a[1][2] && a[1][2]==a[2][2] && a[0][2]==1)
        return 1;
    else if(a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[0][2]==1)
        return 1;
    else
        return 0;
}
int ychecker(int a[3][3]){
    if(a[0][0]==a[0][1] && a[0][1]==a[0][2] && a[0][0]==2)
        return 1;
    else if(a[0][0]==a[1][0] && a[1][0]==a[2][0] && a[0][0]==2)
        return 1;
    else if(a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[0][0]==2)
        return 1;
    else if(a[1][0]==a[1][1] && a[1][1]==a[1][2] && a[1][0]==2)
        return 1;
    else if(a[2][0]==a[2][1] && a[2][1]==a[2][2] && a[2][0]==2)
        return 1;
    else if(a[0][1]==a[1][1] && a[1][1]==a[2][1] && a[0][1]==2)
        return 1;
    else if(a[0][2]==a[1][2] && a[1][2]==a[2][2] && a[0][2]==2)
        return 1;
    else if(a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[0][2]==2)
        return 1;
    else
        return 0;
}
int tiechecker(int a[3][3]){
    int i,j,s=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a[i][j]==1 || a[i][j]==2)
                s++;
        }
    }
    return (s==9)?1:0;
}
void Display(int a[3][3]){
    int i,j;
    char x[]="||\0";
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a[i][j]==1)
                printf("X %c ",x[j]);
            else if(a[i][j]==2)
                printf("O %c ",x[j]);
            else
                printf("  %c ",x[j]);
        }
        printf("\n");
    }
}
int main()
{
    //1 is for X
    //2 is for O
    //0 is for empty
    int a[3][3]={0};
    int n,i,j;
    while(!xchecker(a) && !ychecker(a) && !tiechecker(a)){
        printf("Player X:\n");
        scanf("%d",&n);
        n--;
        i=n/3;
        j=n%3;
        a[i][j]=1;
        Display(a);
        if(!xchecker(a) && !ychecker(a) && !tiechecker(a)){
            printf("Player O:\n");
            scanf("%d",&n);
            n--;
            i=n/3;
            j=n%3;
            a[i][j]=2;
            Display(a);
        }
    }
    if(tiechecker(a))
        printf("Tie !");
    else if(xchecker(a))
        printf("Player X Won !");
    else if(ychecker(a))
        printf("Player Y Won !");
    return 0;
}

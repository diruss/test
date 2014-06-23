#include <stdio.h>
#include <stdlib.h>

int ** Alloc_Init(int n)
{
    int **m,i,j;
    m=malloc(n*sizeof(int*));        //Allocation de mémoire
    for(i=0;i<n;i++)
        m[i]=malloc(n*sizeof(int));  //Allocation de mémoire

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            m[i][j]=0;                //Initialisation
    return m;
}

void remplir(int **t,int n)
{
    int i=n-1,j=n/2,k;
    t[i][j]=1;
    for(k=2;k<=n*n;k++)
    {
        if(t[(i+1)%n][(j+1)%n]==0)
        {
            i=(i+1)%n;
            j=(j+1)%n;
        }
        else
            if(i==0)
                i=n-1;
            else
                i=i-1;
        t[i][j]=k;
    }
}

void afficher(int **m,int n)
{
    int i,j;
    printf("le carre magique d'ordre %d\n\n",n);
    for(i=0;i<n;i++)
    {
        printf("\t");
        for(j=0;j<n;j++)
            printf("%d ",m[i][j]);
        printf("\n");
    }
}

main()
{
    int n,**carre;
    do
    {
        printf("entrer l'ordre de carre magique n\nn= ");
        scanf("%d",&n);
        if(n%2==0)
            printf("n n'est pas impair\n");
        printf("\n");
    }while(n%2==0);
    carre=Alloc_Init(n);
    remplir(carre,n);
    afficher(carre,n);
}

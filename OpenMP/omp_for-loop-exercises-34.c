#include <stdio.h>
#include <omp.h>

void main()
{
    int num,i,ctr,stno,enno;

    printf("Input starting number of range: ");
    scanf("%d",&stno);

    printf("Input ending number of range : ");
    scanf("%d",&enno);
    printf("The prime numbers between %d and %d are : \n",stno,enno);


    void es_primo(num)
    {
        int j = 2;
        for(j;j<=num/2;j++)
        {
            if(num%j==0){
                ctr++;
                break;
            }
        }
        if(ctr==0 && num!= 1)
            printf("%d ",num);
    }

    int p;
    p = omp_get_num_procs();
    omp_set_num_threads(p);
    #pragma omp parallel
    {
        #pragma omp for
        for(i=stno; i<=enno; i++)
        {
            ctr = 0;
            es_primo(i);
        }
    }
}



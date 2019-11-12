//
//  main.c
//  #assignment rod-cutting
//
//  Created by TSAR on 2019/11/11.
//  Copyright © 2019 TSAR. All rights reserved.
//

#include <stdio.h>
#define MAX 200
int max(int a,int b);
void cut_rod(int a[],int n);
void printLength(int n);

int ar[MAX] = {0,};
int length[MAX][2] = {0,};
int idx = 0;

int main(void ) {
    int line_cost[MAX],total_line;//input
   
    printf("input total line:");
    scanf("%d",&total_line);
    
    for(int i=0;i<total_line;i++){
        printf("Line %d :",i+1);
        scanf("%d",&line_cost[i]);
    }
    
    cut_rod(line_cost,total_line);
    for(int i = 1; i < total_line+1; i++)
    {
        printf("length[%d] = %d, %d\n", i, length[i][0], length[i][1]);
    }
    printf("-------------\n");
    
    printf("%d\n",ar[total_line]);
    printLength(total_line);

}

void cut_rod( int *p, int n)
{
    int i, j, q, r;

    for( i = 1 ; i <= n ; i ++)
    {
        q   = -MAX;

        for( j = 1 ; j <= i ; j ++)
        {
            if( j >= MAX)
                r   = MAX - 1;
            else
                r   = j - 1;
            
            int tmp = p[r] + ar[i-j];
            
            if(q < tmp)
            {
                length[i][0] = r + 1;
                length[i][1] = i - j;
                q = tmp;
            }
            
        }
        ar[i]   = q;
    }

    for(int k=1;k<n+1;k++){
        printf("ar[%d]: %d\n",k,ar[k]);
    }
 
    return;
}


void printLength(int n)
{
    if(n == 0)
    {
        return;
    }
    printf("%d\n", length[n][0]);
    printLength(length[n][1]);
    return;
}

int max(int a,int b){
    return a>b? a:b;
}

#include<stdio.h>

int main()
{
    int dizi[5];
    int i;
    
    printf("5 adet deger giriniz:");
    
    
    for(i=0;i<5;i++)
    {
        scanf("%d",&dizi[i]);
        
    }
    
    printf("\n Girilen degerler sunlardir. ");
    
    for(i=0;i<5;i++)
    {
        printf("\n %d,aaaaa \n",dizi[i]);
        
    }
    
    return 0;
}

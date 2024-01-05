
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int menzilOlc(int,int,int);

int main()
{
    int aci,hiz,sure;
    double sonuc;
    printf("Hiz giriniz: \n");
    scanf("%d",&hiz);
    printf("Aci giriniz: \n");
    scanf("%d",&aci);
    printf("Sure giriniz: \n");
    scanf("%d",&sure);
    
    sonuc = menzilOlc(hiz,aci,sure);
    
    printf("Menzil: %lf",sonuc);
    
    return 0;
    
}

int menzilOlc(int hiz, int aci, int sure)
{
    double menzil=hiz*aci*sure;
    
    return menzil;
}

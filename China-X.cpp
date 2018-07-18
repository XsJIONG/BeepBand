#include <cstdio>
#include <windows.h>
#define qdo 262
#define qre 294
#define qmi 330
#define qfa 349
#define qso 392
#define qla 440
#define qsi 494
#define do 523
#define re 578
#define mi 659
#define fa 698
#define so 784
#define la 880
#define si 988
#define do1 1046
#define re1 1175
#define mi1 1318
#define fa1 1480
#define so1 1568
#define la1 1760
#define si1 1976
#define sqdo 277
#define sqre 311
#define sqfa 370
#define sqso 415
#define sqla 466
#define sdo 554
#define sre 622
#define sfa 740
#define sso 831
#define sla 932
#define sdo1 1046
#define sre1 1245
#define sfa1 1480
#define sso1 1661
#define sla1 1865
const int q=250;
const int ALL[]={
0,1,qso,1,qla,1,do,1,re,2,mi,1,so,1,mi,1,do,1,re,3,do,1,so,1,mi,2,do,1,so,1,re,2,do,1,so,1,qsi,2,do,1,qsi,1,qso,2,qmi,1,qso,2,
0,1,qso,1,qla,1,do,1,re,2,mi,1,so,1,mi,1,do,1,re,3,do,1,so,1,mi,2,do,1,so,1,re,2,do,1,so,1,qsi,2,qso,1,qla,1,do,1,so,2,re,2,
mi,1,do,1,qso,1,re,2,mi,1,so,1,mi,2,do,1,qso,1,re,3,qsi,1,do,1,mi,1,do,1,qso,1,re,2,mi,1,so,1,mi,2,do,1,re,1,qsi,2,do,1,qso,2,mi,1,do,1,qso,1,re,2,mi,1,so,1,mi,2,
do,1,re,3,do,1,so,1,re,2,do,1,so,1,re,2,do,1,so,1,re,1,do,1,so,1,re,1,do,1,so,1,re,1,do,1,so,1,
mi,1,so,1,re,1,mi,-1,2,re,-5,2,do,1,re,1,mi,1,so,1,re,1,mi,-1,2,re,-3,2,do,1,re,1,do,1,mi,1,so,1,re,1,mi,-1,2,re,-5,2,do,1,re,1,mi,1,so,1,re,1,qso,-1,2,qla,-3,2,
do,1,re,1,do,1,mi,1,so,1,re,1,mi,-1,2,re,-5,2,do,1,re,1,do,1,mi,1,so,1,re,1,mi,-1,2,re,-3,2,do,1,re,1,do,1,mi,1,so,1,re,1,mi,-1,2,re,-3,2,do,1,re,1,do,1,mi,1,so,1,mi,1,so,1,mi,1,so,1,mi,1,so,1,
-1,2,//Change the Bit
mi,1,0,3,mi,1,0,2,mi,1,0,2,mi,1,0,1,mi,1,0,1,do,1,0,1,re,1,0,3,re,1,0,2,re,1,0,2,do,1,0,1,re,1,0,1,so,1,0,1,mi,1,0,3,mi,1,0,2,mi,1,0,2,so,2,la,1,so,1,re,1,0,1,mi,1,0,3,mi,1,0,2,mi,1,0,2,so,1,0,1,re,1,0,1,qso,1,0,1,
mi,1,0,3,mi,1,0,2,mi,1,0,2,mi,1,0,1,mi,1,0,1,do,1,0,1,re,1,0,3,re,1,0,2,re,1,0,2,do,1,0,1,re,1,0,1,so,1,0,1,mi,1,0,3,mi,1,0,2,mi,1,0,2,so,2,la,1,so,1,re,1,0,1,
mi,1,0,3,mi,1,0,2,mi,1,0,2,qso,1,0,1,qla,1,0,1,do,1,0,1,
mi,1,0,3,mi,1,0,2,mi,1,0,2,mi,1,0,1,mi,1,0,1,do,1,0,1,re,1,0,3,re,1,0,2,re,1,0,2,do,1,0,1,re,1,0,1,so,1,0,1,mi,1,0,3,mi,1,0,2,mi,1,0,2,so,2,la,1,so,1,re,1,0,1,mi,1,0,3,mi,1,0,2,mi,1,0,2,so,1,0,1,re,1,0,1,qso,1,0,1,
mi,1,0,3,mi,1,0,2,mi,1,0,2,mi,1,0,1,mi,1,0,1,do,1,0,1,re,1,0,3,re,1,0,2,re,1,0,2,do,1,0,1,re,1,0,1,so,1,0,1,mi,1,0,3,mi,1,0,2,mi,1,0,2,so,2,la,1,so,1,re,1,0,1,
mi,1,0,3,mi,1,0,2,mi,1,0,2,qso,1,0,1,do,1,0,1,re,1,0,1,-1,1,//Change to the normal bit
//Second repeat
0,1,qso,1,qla,1,do,1,re,2,mi,1,so,1,mi,1,do,1,re,3,do,1,so,1,mi,2,do,1,so,1,re,2,do,1,so,1,qsi,2,do,1,qsi,1,qso,2,qmi,1,qso,2,
0,1,qso,1,qla,1,do,1,re,2,mi,1,so,1,mi,1,do,1,re,3,do,1,so,1,mi,2,do,1,so,1,re,2,do,1,so,1,qsi,2,qso,1,qla,1,do,1,so,2,re,2,
mi,1,do,1,qso,1,re,2,mi,1,so,1,mi,2,do,1,qso,1,re,3,qsi,1,do,1,mi,1,do,1,qso,1,re,2,mi,1,so,1,mi,2,do,1,re,1,qsi,2,do,1,qso,2,mi,1,do,1,qso,1,re,2,mi,1,so,1,mi,2,
do,1,re,3,do,1,so,1,re,2,do,1,so,1,re,2,do,1,so,1,re,1,do,1,so,1,re,1,do,1,so,1,re,1,do,1,so,1,
mi,1,so,1,re,1,mi,-1,2,re,-5,2,do,1,re,1,mi,1,so,1,re,1,mi,-1,2,re,-3,2,do,1,re,1,do,1,mi,1,so,1,re,1,mi,-1,2,re,-5,2,do,1,re,1,mi,1,so,1,re,1,qso,-1,2,qla,-3,2,
do,1,re,1,do,1,mi,1,so,1,re,1,mi,-1,2,re,-5,2,do,1,re,1,do,1,mi,1,so,1,re,1,mi,-1,2,re,-3,2,do,1,re,1,do,1,mi,1,so,1,re,1,mi,-1,2,re,-3,2,do,1,re,1,do,1,mi,1,so,1,mi,1,so,1,mi,1,so,1,mi,1,so,1,
-1,2,//Change the Bit
mi,1,0,3,mi,1,0,2,mi,1,0,2,mi,1,0,1,mi,1,0,1,do,1,0,1,re,1,0,3,re,1,0,2,re,1,0,2,do,1,0,1,re,1,0,1,so,1,0,1,mi,1,0,3,mi,1,0,2,mi,1,0,2,so,2,la,1,so,1,re,1,0,1,mi,1,0,3,mi,1,0,2,mi,1,0,2,so,1,0,1,re,1,0,1,qso,1,0,1,
mi,1,0,3,mi,1,0,2,mi,1,0,2,mi,1,0,1,mi,1,0,1,do,1,0,1,re,1,0,3,re,1,0,2,re,1,0,2,do,1,0,1,re,1,0,1,so,1,0,1,mi,1,0,3,mi,1,0,2,mi,1,0,2,so,2,la,1,so,1,re,1,0,1,
mi,1,0,3,mi,1,0,2,mi,1,0,2,qso,1,0,1,qla,1,0,1,do,1,0,1,
mi,1,0,3,mi,1,0,2,mi,1,0,2,mi,1,0,1,mi,1,0,1,do,1,0,1,re,1,0,3,re,1,0,2,re,1,0,2,do,1,0,1,re,1,0,1,so,1,0,1,mi,1,0,3,mi,1,0,2,mi,1,0,2,so,2,la,1,so,1,re,1,0,1,mi,1,0,3,mi,1,0,2,mi,1,0,2,so,1,0,1,re,1,0,1,qso,1,0,1,
mi,1,0,3,mi,1,0,2,mi,1,0,2,mi,1,0,1,mi,1,0,1,do,1,0,1,re,1,0,3,re,1,0,2,re,1,0,2,do,1,0,1,re,1,0,1,so,1,0,1,mi,1,0,3,mi,1,0,2,mi,1,0,2,so,2,la,1,so,1,re,1,0,1,
mi,1,0,3,mi,1,0,2,mi,1,0,2,qso,1,0,1,do,1,0,1,re,1,0,1,-1,1,//Change to the normal bit
mi,1,do,1,qso,1,re,2,mi,1,so,1,mi,2,do,1,qso,1,re,2,qsi,1,do,1,mi,1,do,1,qso,1,re,1,re,1,mi,1,so,1,mi,2,do,1,re,1,qsi,2,do,1,qso,2,mi,1,do,1,qso,1,re,2,mi,1,so,1,mi,2,do,1,re,3,do,1,so,1,re,2,do,1,so,1,re,2,do,1,so,1,do,1,so,1,re,1,do,1,so,1,re,1,do,1,so,4
};
int main() {
	int a=sizeof(ALL)/sizeof(int);
	int C=q;
	for (int i=0;i<a;i+=2) if (ALL[i]==0) Sleep(C*ALL[i+1]); else if (ALL[i]<0) C=-q*ALL[i]/ALL[i+1]; else if (ALL[i+1]<0) Beep(ALL[i],-C*ALL[i+1]/ALL[i+2]),i++; else Beep(ALL[i],C*ALL[i+1]);
	return 0;
}

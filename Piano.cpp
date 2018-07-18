#include <stdio.h>
#include <windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
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
#define sqmi 355
#define sqfa 370
#define sqso 415
#define sqla 466
#define sqsi 500
#define sdo 554
#define sre 622
#define smi 688
#define sfa 740
#define sso 831
#define sla 932
#define ssi 998
#define sdo1 1046
#define sre1 1245
#define smi1 1360
#define sfa1 1480
#define sso1 1661
#define sla1 1865
#define ssi1 1950
const int Common[]={qdo,qre,qmi,qfa,qso,qla,qsi,do,re,mi,fa,so,la,si,do1,re1,mi1,fa1,so1,la1,si1,sqdo,sqre,sqmi,sqfa,sqso,sqla,sqsi,
sdo,sre,smi,sfa,sso,sla,ssi,sdo1,sre1,smi1,sfa1,sso1,sla1,ssi1};
bool pressed[1000];
int T=50;
int O=7;
bool check(char c) {
    if (KEY_DOWN(c)) {
        if (!pressed[c]) {pressed[c]=1;return 1;}
    } else pressed[c]=00;
    return 0;
}
int main() {
    int len=sizeof(Common)/sizeof(int);
    while (true) {
        for (int i='1';i<='8';i++) if (check(i)) Beep(Common[i-'1'+O],T);
        if (check('0')) if (O<len-6) O+=7,puts("ÉýÆß½×"); else puts("³¬ÏÞ£¡");
        if (check('9')) if (O>0) O-=7,puts("½µÆß½×"); else puts("³¬ÏÞ£¡");12
        Sleep(10);
    }
	return 0;
}

#include <stdio.h>
#include <windows.h>
#include <ctime>
#define THREAD DWORD WINAPI
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
	} else pressed[c]=0;
	return 0;
}
HANDLE LastThread=NULL;
THREAD UP(LPVOID para) {
	for (int i=500;i<=1000;i+=10) Beep(i,10);
	LastThread=NULL;
}
THREAD RING(LPVOID para) {
	for (int i=0;i<6;i++) Beep(1000,100),Sleep(100);
	LastThread=NULL;
}
THREAD DOWN(LPVOID para) {
	for (int i=1000;i>=500;i-=10) Beep(i,10);
	LastThread=NULL;
}
void RunThread(LPTHREAD_START_ROUTINE a) {
	if (LastThread!=NULL) CloseHandle(LastThread);
	LastThread=CreateThread(NULL,0,a,NULL,0,NULL);
}
bool special=0;
int main() {
	ShowWindow(GetForegroundWindow(),false);
	int len=sizeof(Common)/sizeof(int);
	bool a;
	srand(time(0));
	while (true) {
		a=0;
		for (int i='1';i<='8';i++) if (check(i)) Beep(Common[i-'1'+O],T),a=1;
		if (check('0')) {a=1;O+=7;if (O+7>=len) O=0;}
		else if (check('9')) {a=1;O-=7;if (O<0) O=len-7;}
		if (special) {
			if (check('D')) RunThread(DOWN),a=1;
			else if (check('R')) RunThread(RING),a=1;
			else if (check('Q')) Beep(1000,T),exit(0);
			else if (check('U')) RunThread(UP),a=1;
		}
		if (check(MOUSE_WHEELED)) special=!special,Beep(1000,T);
		if (!a) {
			for (int i='A';i<='Z';i++) if (check(i)) {a=1;break;}
			if (a&&((rand()%10)<4)) Beep(Common[rand()%(len-30)],T);
		}
		Sleep(10);
	}
	return 0;
}

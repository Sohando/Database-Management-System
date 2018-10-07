#include<bits/stdc++.h>
using namespace std;

char Factorial[25][100];
char f[100];

void multiply(int k) {
        int c, sum, i, j;

        int len = strlen(f);
        c = 0;
        i = 0;
        while(i < len) {
                sum = c + (f[i] - '0') * k;
                f[i] = (sum % 10) + '0';
                i++;
                c = sum / 10;
        }

        while(c > 0) {
                f[i++] = (c % 10) + '0';
                c /= 10;
        }
        f[i] = '\0';

        for(j=0; j<i; j++) {
                Factorial[k][j] = f[j];
        }
        Factorial[k][i] = '\0';
}

void print_factorial(int n) {
        int i;
        int len = strlen(Factorial[n]);

        for(i=len-1; i>=0; i--) {
                printf("%c", Factorial[n][i]);
        }
        printf("\n");
}
void call_factorial() {
        strcpy(f, "1");
        Factorial[0][0] = '1';
        Factorial[1][0] = '1';

        int k;
        for(k=2; k<=22; k++) {
                multiply(k);
        }
}

void Bhag_it(int N) {

        int sz = strlen(Factorial[N]);
        int i, bhagsesh, j, bhajok = 2;
        char Bhagfol[100];

        for(i=sz-1, j=0, bhagsesh=0; i>=0; i--, j++) {
                bhagsesh = bhagsesh * 10 + Factorial[N][i] - '0';

                Bhagfol[j] = bhagsesh / bhajok + '0';
                bhagsesh %= bhajok;
        }

        Bhagfol[j] = '\0';

        i = 0;
        while(Bhagfol[i]=='0') i++;

        for(i=i; i < Bhagfol[i] != '\0'; i++) {
                printf("%c", Bhagfol[i]);
        }
        printf("\n");
}

int main() {
        call_factorial();

        int n, cas = 1;
        char temp[100];
        scanf("%d", &n);
        getchar();
        while(n--) {
                printf("Data set %d: ", cas++);
                scanf("%s", &temp);

                int sz = strlen(temp);
                //print_factorial(sz);
                Bhag_it(sz);
        }


        return 0;
}

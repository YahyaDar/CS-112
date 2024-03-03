#include "iostream"
#include "cstring"
#include "cmath"
#include "unistd.h"
#include "cstdlib"
using namespace std;

#define PI 3.14 // we define the value of PI (like storing it in a variable)

class donut {
public:
    void print(float A, float B) {
        int buffersize = 1920;
        int loopindex;
        float f[buffersize], i, j, R1 = 1, R2 = 2, K1 = 15, K2 = 5;
        char *output = new char[buffersize];
        memset(output, ' ', buffersize);
        memset(f, '\0', buffersize * 4);


        for (j = 0; j < 2 * PI; j += 0.1) {
            for (i = 0; i < 2 * PI; i += 0.1) {
                	float 	z=sin(i)*(R2+cos(j))*(sin(A))+sin(j)*cos(A)+K2,
							
							ooz=1/(z),
							
							t=sin(i)*(R2+cos(j))*(cos(A))-(sin(j))*(sin(A));		
							
					int 	x=K1*ooz*(cos(i)*(R2+cos(j))*cos(B)-t*sin(B))*2+40,  					
							y=K1*ooz*(cos(i)*(R2+cos(j))*sin(B)+t*cos(B))+12,		
															
							o=x+80*y;
                float L = 8*((sin(j)*sin(A)-sin(i)*cos(j)*cos(A))*cos(B)-sin(i)*cos(j)*sin(A)-sin(j)*cos(A)-cos(i)*cos(j)*sin(B));
               if(y<24 && y>0 && x>0 && x<80 && ooz>f[o]) {
                    f[o]=ooz;
                    if(L>0){
                         output[o] = ",-~:;=!*#$@"[static_cast<int>(L)-1];
                    }
                    else{
                        output[o]='.';
                    }
                }
            }
        }

        for (int i = 0; i < buffersize; ++i) {
            if (i % 80 != 0) {
                cout << output[i];
            } else {
                cout << endl;
            }
        }
    }
};

int main() {
    float g = 0, h = 0;
    donut d;
    while (true) {
        d.print(g, h);
        g += 0.07;
        h += 0.03;
        usleep(60000); // freeze the frame in terminal for 30,000 ms
       
       system("cls"); // Clear the screen (for Windows systems only)
    }
    return 0;
}


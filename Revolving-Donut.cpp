#include<iostream>
#include <conio.h>
#include <cmath> 	
#include <tchar.h> 	//for memset
#include <windows.h>
 
#define PI 3.14 	//macro

using namespace std;
 
class Doghnut{
	
	//Screen Width is 80
	//Screen Height is 24
	//24x80=1920;
	
	
	public:
	
	void print( float A, float B ){
	   
		int size=1920;		// as of 24x80;
		int k;
	
	    float	f[size],	//for Buffer
				i,			//Theta
				j,			//Phi
				R=2,		//Taking R2 is R and R1=1, so no variable required of R1.
				k1=15,		//determine size: inccrease in value increases size
				k2=5;		//determine size: increase in value decreases size
				
		char c[size];		//Output Characters
		
		
		memset(c,' ',size);             //for declaring c array with ' ' .	
		memset(f,'\0',size*4);		    //for declaring f array with '\0' .			
		
		for(j=0;j<2*PI;j+=0.1)		    //for rotation along x axis.
			for(i=0;i<2*PI;i+=0.1)	    //for rotation along y axis.
			
				{			
				
					float 	z=sin(i)*(R+cos(j))*(sin(A))+sin(j)*cos(A)+k2,		//z as of formula
							
							ooz=1/(z),											//ooz is 1/z for simplification
							
							t=sin(i)*(R+cos(j))*(cos(A))-(sin(j))*(sin(A));		//for simplification
							
					int 	x=k1*ooz*(cos(i)*(R+cos(j))*cos(B)-t*sin(B))*2+40,		//Directly calculated x'					
							y=k1*ooz*(cos(i)*(R+cos(j))*sin(B)+t*cos(B))+12,		//Directly calculated y'
															
							o=x+80*y,											//o is index of character to output
							
					 		N=8*((sin(j)*sin(A)-sin(i)*cos(j)*cos(A))*cos(B)-sin(i)*cos(j)*sin(A)-sin(j)*cos(A)-cos(i)*cos(j)*sin(B));	//luminance 									
							
							
					if(y<24 && y>0 && x>0 && x<80 && ooz>f[o])	
						{
							f[o]=ooz;
							
							if(N>0)
							{
								c[o]=",-~:;=!*#$@"[N-1];
							}
							else
							{
								c[o]='.';
							}		
							
						}
						
				} 

	
		for(k=0;k<=size;k++)
		{
			if(k%80!=0)
			{
				cout<<c[k];
			}
			else
			{
				cout<<endl;
			}
		}
		
	}

}; 

int main()
{
	system("CLS");
	system("COLOR 0A");
	
	float g=0,h=0;
	Doghnut d;
	
	while(true){	
		
		d.print(g,h);
								
		g=g+0.07;			//spacing for theta or say angle i
		h=h+0.03;			//spacing for phi or say angle j
		
		cout<<"\x1b[H"<<flush;		//works like system("cls") but better than that;
		
//		system("cls");
	}		

 return 0;
}

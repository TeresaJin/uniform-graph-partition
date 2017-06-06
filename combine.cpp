#include<iostream>
#include<fstream>
using namespace std; 
#define MAXN 20
int temp[MAXN];  
int n,m;  
ofstream out;

void combine(int n, int m, int lev)//×éºÏÊý  
{  
    int i;  
    if(m == 0)  
    {  
        for(i=0; i<lev; ++i)  
            out<<temp[i]<<' ';
		out<<endl;
	}

    else  
    {  
        for(i=0; i<=n-m; ++i)  
        {  
            temp[lev++] = n-i;  
            combine(n-i-1, m-1, lev);  
            lev--;  
        }  
    }  
}  

int main()  
{  
	out.open("permutation.txt");
	if (! out.is_open())  
       { cout << "Error opening file"; exit (1); }  
	n = 10;
    combine(2*n,n,0);  
	out.close();
	return 0;
}
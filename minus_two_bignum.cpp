#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string minus_bignum( string a, string b)
{
    int n1 = a.size();
    int n2 = b.length();


    if( n2> n1)
    {
        swap( a,b);
        swap(n1, n2);

    }
    string res ="";
    int nho =0; 
    for ( int i = n1 -1; i>= n1- n2; i--)
    {
        int sub   = a[i] - b[i -n1+n2] - nho;
        if( sub < 0)
        {
            res+= (sub+10)%10 +'0';
            nho = 1;
        }
        else
        {   res+= sub+'0';
            nho = 0;
        }


    }

    for ( int i = n1 -n2-1; i>= 0; i--)
    {
        int sub = a[i] -'0' - nho;
        if( sub == -1)
        {
            res+= '9';
            nho =1;
        }
        else 
        {
            res+=sub+'0';
            nho =0;
        }


    }
    if( nho ==1)
    {   res +='9';
      
    }


    reverse( res.begin(), res.end());
    if( nho ==1)
    {
         string z(n1+1,'0');
        
         
       res = minus_bignum( "1"+z, res);cout<<"-";
    }
    
    return res;



}
// 100
// 101

int main()
{
        string a,b;
        cin >> a>>b;

        cout<< minus_bignum(a,b);
       
        
   

}
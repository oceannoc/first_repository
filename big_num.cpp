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
        swap(n1, n2);cout<<"-";

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
    
    while( res[0] =='0' && res.length()>1)
    {
        res.erase(0,1);
    }
   
    return res;



}
// 100
// 101

string add_bignum( string a, string b)
{
    int n1 = a.size();
    int n2 = b.length();
    if( n2>n1)
    {
        swap( a,b);
        swap(n1,n2);
    }
    string res ="";int nho =0;
    for ( int i =n1-1; i>= n1-n2; i--)
    {
        int sum= a[i]-'0' + b[i-n1+n2] -'0'+nho;
        res+= sum%10+'0';
        nho =sum /10;

    }
    for ( int i =n1-n2 -1; i>=0; i--)
    {
        int sum = a[i] -'0'+nho;
        res+= sum%10+'0';
        nho = sum/10;
    }
    if( nho)
    {
        res+='1';
    
    }
    reverse( res.begin(), res.end());
    return res;

}


string multi_bignum( string a, string b)
{
    int n1= a.length();
    int n2=b.length();
    vector<int> c ( n1+n2+1,0);

    for ( int i =n1-1; i>=0; i--)
    {
        for ( int j =n2-1; j>=0; j--)
        {
            c[i+j+1] +=(a[i] -'0')*(b[j] -'0');
            
        }
    }
    
    
    
    int nho =0;
    for( int i =n1+n2 -1; i>0; i--)
    {
        int sum =c[i];
        c[i] =(c[i]+nho)%10 ;

        nho =(sum +nho)/10;


    }
   
    int index =0;
    while( c[index] ==0)
    {
        index ++;
    }

    string res ="";

    for ( ;index <= n1+n2-1; index++)
    {
        res+= c[index] +'0';
    }

    return res;
}




int main()
{
        string a,b;
        cin >> a>>b;
        cout<< add_bignum(a,b)<<"\n";
        cout<< minus_bignum(a,b)<<"\n";
        cout<< multi_bignum(a,b);
        

}
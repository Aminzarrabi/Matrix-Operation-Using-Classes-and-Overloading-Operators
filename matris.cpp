//proje payanterm pishrafte 2022-16 june  9:57
//amalgar >> vorodi
//amalgar << khoroji
//amalgar + baraye (majmo do matris)
//amalgar - baraye (tafazol do matris)
//amalgar * baraye (zarb nazir do matris)
//amalgar / baraye (zarb matris dar matris)
//amalgar ^ baraye (zarb add dar matris) 
//tashkhis balamosalasi v payinmosalasi
//tashkil matris spars v tranahade 
//tashkhis spars 
#include<iostream>
using namespace std;
const int n=4,m=4;//moshakas kardan n va m//
int i,j;
class matris 
{   
    friend  ostream & operator <<(ostream & ostr,const matris &r);
    friend  istream & operator >>(istream & istr, matris &r);
    private:
    int k,a[n][m];
    public:
        matris  operator + (const matris r)//majmo do matris//
    {
        matris t;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                t.a[i][j]=a[i][j]+r.a[i][j];
        return t;
    }  
        matris  operator - (const matris r)//tafazol do matris//
    {
        matris t;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                t.a[i][j]=a[i][j]-r.a[i][j];
        return t;
    }
        matris operator * (const matris r)//zarb matris nazir be nazir//
    {
        matris t;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                t.a[i][j]=a[i][j]*r.a[i][j];
        return t;        
    }
    matris operator / (const matris r)//zarb matris dar matris//
    {
        int sum=0,c,g=0,l=0;
        matris t;
        for(int i=0;i<n;i++)
            {
                l=0;
                for(int j=0;j<m;j++,l++)
                {
                    for(int g=0;g<m;g++)
                    {
                        c=a[i][g]*r.a[g][l];
                        sum+=c;
                    }
                    t.a[i][j]=sum;
                    sum=0;
                }
            }
        return t;        
    }
        matris operator ^ (const int r)//zarb add dar matris//
    {
        matris t;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                t.a[i][j]=a[i][j]*r;
        return t;        
    }
    matris taranahade ()//taranahade matris//
    {
        matris b;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                b.a[i][j]=a[j][i];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<<b.a[i][j]<<" ";
            }
          cout<<"\n";
        }
    } 
    void balamosalasi()//tashkhis balamosalasi//
    {
        int flag=1;
        for(int i = 0 ; i < n ; i++)
        { 
            for(int j = 0 ; j < i ; j++){
                if(a[i][j]!=0)
                    {
                        flag=0;
                        break;
                    }
            }          
        }
        if(flag==1)
            cout<<"True";
        else
            cout<<"False";
    }
    void payinmosalasi()//tashkhis payinmosalasi//
    {
        int flag=1;
        for(int i = 0 ; i < n ; i++)
        { 
            for(int j = 0 ; j < i ; j++){
                if(a[j][i]!=0)
                    {
                        flag=0;
                        break;
                    }
            }          
        }
        if(flag==1)
            cout<<"True";
        else
            cout<<"False";
    }

    void tashkhis_spars()//tashkhis spars//
    {
        int c=0,v=0;
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)    
                {
                    if(a[i][j]==0)
                        c++;
                    else
                        v++;
                }
            }
        if(c>v)
            cout<<"True";
        else
            cout<<"False";
    }
    void spars ()
    {
        int k=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(a[i][j]!=0)
                    k++;
            }
        }        
        cout<<"\ni j k\n";
        cout<<i<<" "<<j<<" "<<k<<"\n";
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(a[i][j]!=0)
                    cout<<i<<" "<<j<<" "<<a[i][j]<<"\n";
            }
        }
    }
};
    ostream & operator <<(ostream & ostr,const matris &r)//amalgar jariyan khoroji//
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                ostr<<r.a[i][j]<<" ";
            }
            ostr<<"\n";
        }
        return ostr;
    }
    istream & operator >> (istream & istr,matris &r)//amalgar jariyan vorodi//
    {
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                istr>>r.a[i][j]; 
    }
int main(){
    matris a,b,c;
    int k;
    cout<<"N : "<<n<<"     M : "<<m<<"\n\n";
    cout<<"A : "<<"\n";cin>>a; cout<<"\n";
    cout<<"B : "<<"\n";cin>>b; cout<<"\n";
    cout<<"K : "<<"\n";cin>>k; cout<<"\n";
    cout<<"C = A + B :   (majmo do matris)"<<"\n";c=a+b; cout<<c<<"\n";
    cout<<"C = A - B :   (tafazol do matris)"<<"\n";c=a-b; cout<<c<<"\n";
    cout<<"C = A * B :   (zarb nazir do matris)"<<"\n";c=a*b; cout<<c<<"\n";
    cout<<"C = A * B :   (zarb matris dar matris)"<<"\n";c=a/b; cout<<c<<"\n";
    cout<<"C = A * K :   (zarb add dar matris)"<<"\n";c=a^k; cout<<c<<"\n"; 
    cout<<"Taranahade A :   (tashkil taranahade)\n"; a.taranahade();cout<<"\n";
    cout<<"\n"<<"Spars B :   (tashkhis spars)\n";b.tashkhis_spars();cout<<"\n";
    cout<<"\n"<<"Balamosalasi A :   (tashkhis balamosalasi)\n";a.balamosalasi();cout<<"\n";
    cout<<"\n"<<"Payinmosalasi B :   (tashkhis payinmosalasi)\n";b.payinmosalasi();cout<<"\n";
    cout<<"\n"<<"Spars A :   (matris spars)\n";a.spars();cout<<"\n";
    cout<<"\n"<<"Spars B :   (matris spars)\n";b.spars();cout<<"\n";
    return 0;
}
//test case A
// 1 4 8 5 
// 0 1 2 3
// 0 0 1 2  
// 0 0 0 1

//test case B
// 1 0 0 0
// 3 2 0 0 
// 9 5 1 0
// 1 1 1 8
#include <bits/stdc++.h>
using namespace std;
int pr=0;
void display(int n,long double **a,int f){
    for(int k=0;k<n;k++){
        int q=k;
        if(!a[k][k]){
            for(int h=k+1;h<n;h++)
            if(a[h][k]){
                q=h;
                break;
            }
            double b[n];
            for(int i=0;i<n+1 && q!=k;i++){
                b[i]=a[k][i];
                a[k][i]=a[q][i];
                a[q][i]=b[i];
            }
            pr+=1;
        }
        if(q==k && !a[k][k]){
            continue;
        }
        for(int i=0;i<n;i++){
            if((i<=k && !f)||(i>=k && f))
            continue;
            long double p=(a[i][k]/a[k][k]);
            long double l=a[i][k],m=a[k][k];
            for(int j=k;j<n+1;j++)
            a[i][j]=a[i][j]-p*a[k][j];
            if(!p)
            cout<<endl<<"No reduction for R"<<i+1<<endl;
            else if(p>=0){
                if(l<0){
                    l*=-1;
                    m*=-1;
                }
                cout<<endl<<"R"<<i+1<<" -> "<<"R"<<i+1<<" - ("<<l<<"/"<<m<<")*R"<<k+1<<endl;
            }
            else{
                if(l<0)
                l*=-1;
                else
                m*=-1;
                cout<<endl<<"R"<<i+1<<" -> "<<"R"<<i+1<<" + ("<<l<<"/"<<m<<")*R"<<k+1<<endl;
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n+1;j++)
                cout<< fixed <<setprecision(2) <<a[i][j]<<"\t";
                cout<<endl;
            }
            cout<<"-------------------------------------------------------------------------\n";
        }
    }
}
int main(){
    long int n,f=0;
    cout<<"Enter the size of matrix:";
    cin>>n;
    long double **a,z,mul=1;
    a = new long double *[n];
    for(int i = 0; i <n; i++)
    a[i] = new long double[n+1];
    cout<<"Enter an Augmented matrix:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n+1;j++)
        cin>>a[i][j];
    display(n,a,0);
    display(n,a,1);
    for(int i=0;i<n;i++)
        mul*=a[i][i];
    for(int i=0;i<n;i++){
        if(a[i][i]){
            for(int j=0;j<n+1;j++)
                if(i!=j && a[i][j])
                a[i][j]/=a[i][i];
            a[i][i]=1;
        }
    }
    cout<<endl<<"Reduced matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++)
        cout<<a[i][j]<<setprecision(2)<<"\t";
        cout<<endl;
    }
    cout<<"-------------------------------------------------------------------------\n";
    mul*=pow(-1,pr);
    cout<<endl<<"Determinant: "<<mul<<endl;
    int c=0,d=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]){
                c++;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            if(a[i][j]){
                d++;
                break;
            }
        }
    }
    if(c==d && c==n && mul){
        cout<<endl<<"Unique solution\n";
        for (int i=0;i<n;i++)
        cout<<"\nX"<<i+1<<": "<<a[i][n]<<"\t";
    }
    else if(c==d && c<n)
    cout<<endl<<"Infinite solution\n";
    else
    cout<<endl<<"No Solution\n";
    cout<<endl;
    return 0;
}

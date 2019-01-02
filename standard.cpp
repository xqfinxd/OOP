#include <iostream> 
using namespace std;
int main(){
    int a[30];
    int n ;
    int count=0;
    while(cin>>n&&n){
        a[count]=n;
        count++;
    }
    int sum=0;
    int num=1;
    for(int i=0;i<count;i++){
        if(a[i]==1){
            sum++;
            num=1;
        }
        else if(a[i]==2){
            sum+=2*num;
            num++;
        }
    }
    cout<<sum<<endl;
}

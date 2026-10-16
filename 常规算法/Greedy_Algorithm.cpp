#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
  int ExchangeMoney(float n,float *a,int c,float *r)
 {
    int m;
    // 零钱可以分解，且已经分解完毕，返回结果0
    if(n==0.0)
    {
        return 0;
    }
    // 无面额匹配找0，无法分解
    if(c == 0)
    {
        return -1;
    }
    // 假设零钱小于当前面额，去寻找合适面额
    if(n<*a)
    {
        return ExchangeMoney(n,a+1,c-1,r);
    }
    else{
        // 如果零钱大于当前面额，存入面额数字在新数组
        *r=*a;
        m=ExchangeMoney(n,a+1,c-1,r);
        if(m>=0)
        {
            return m+1;
        }
        return -1;
    }
 }
int main()
{   vector<float>rmb={100,50,20,10,5,2,1,0.5,0.2,0.1};
    int n = rmb.size(),k,i;//k,i是未定义行为
    int N=60;
    float change,r[N];
    cout<<"please input your want change: ";
    cin>>change;
    for(i=0;i<n;i++)
    {
        if(change>=rmb[i]);
        break;
    }
    k=ExchangeMoney(change,&rmb[i],n-i,r);
    if(k<=0)
        cout<<"can't give change";
    else
    {
        cout<<"the way of change is:"<<change;
        if(r[0]>=1.0)
        {
            cout<<r[0];
        }
        else{
            cout<<setprecision(2)<<fixed<<r[0];
        }
        for(i = 1;i<k;i++)
        {
            if(r[i]>=1.0)
            {
                cout<<"+"<<r[i];
            }
            else{
                 cout<<setprecision(2)<<fixed<<r[i];
            }
            cout<<endl;
        }
    }
    // 贪心算法目的；寻找当前最优解
    
    cin.get();
}
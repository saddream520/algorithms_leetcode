#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    vector<string>logs={"0:start:0","1:start:2","1:end:5","0:end:6"};
    // cout<<logs.size();
    int id, timestamp;
    char type[10];
    for(string&log:logs)
    {
    sscanf(log.c_str(), "%d:%[^:]:%d", &id, type, &timestamp);
    cout<<id<<" "<<type<<" "<<timestamp<<endl;
    }
    cin.get();
}
#include<iostream>
#include<vector>
#include<string>
class bucket_sort
{
public:
    struct index
    {
        int key;
        int start;
    }newIndex[3];
public:
int cmp(const void *a,const void* b){
    return (*(struct index*)a).key>(*(struct index*)b).key?1:-1;
}
    int search(int key,int*a)
    {
        int i ,startValue;
        i = 0;
        while(i<3&&key>newIndex[i].key)
        {
            i++;
        }
        // 找到目标索引块
        if(i>=3)
        {
            return -1;
        }
        // 查询结果大于表中数据，没有对应分块
        startValue = newIndex[i].start;
        while(startValue<=newIndex[i].start+5&&a[startValue]!=key)
        {
            startValue++;
            // 在找到的块内顺序查找
            // 接着在块内向后扫描
        }
        if(startValue>startValue+5)
        {
            return -1;
            // 没区块了
        }
        return startValue;
    }
    
};
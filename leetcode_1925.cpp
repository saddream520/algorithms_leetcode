class Solution {
public:
// 三元数大于1
    int countTriples(int n) {
        int count = 0;
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 1;j<n+1;j++)
            {
                int c = int(sqrt(i*i+j*j+1));
                if(i*i+j*j==c*c&&c<=n)
                {
                    count++;
                }
            }
        }
        return count;
    };
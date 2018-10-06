#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<string> > nums(9,vector<string>());
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        int index = abs(temp[0]-48-9);
        nums[index].push_back(temp);
    }

    for (int i = 0; i < 9; ++i) {
        if(nums[i].empty())
            continue;
        if(nums[i].size() == 1)
        {
            cout << nums[i][0];
            continue;
        }
        while (!nums[i].empty()){
            vector<string>::iterator it, max_it;
            max_it = it = nums[i].begin();
            string max_num = *max_it;
            for ( ++it;  it!=nums[i].end() ; ++it) {
                string temp = *it;
                if(temp.length() == max_num.length())
                {
                    if (temp > max_num){
                        max_num = temp;
                        max_it = it;
                    }
                    continue;
                } else{
                    string str1 = max_num + temp;
                    string str2 = temp + max_num;
                    if(str2 > str1)
                    {
                        max_num = temp;
                        max_it = it;
                    }
                }
            }
            cout << max_num;
            nums[i].erase(max_it);
        }
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


//class Solution {
//public:
//    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
//
//    }
//};
//

class Solution {
public:
    vector<int> getdone(int n,int m,int first,int second,vector<int> &nums1,vector<int> &nums2){
        multiset<int> s1;
        if (first != 0){
            s1 = multiset(nums1.begin(), nums1.begin() + (n - first + 1));
        }
        multiset<int> s2;
        if (second != 0){
            s2 = multiset(nums2.begin(), nums2.begin() + (m - second + 1));
        }
//    for (auto each : s1) cout << each << " " ;
//    cout << endl;
//    for (auto each : s2) cout << each << " " ;
//    cout << endl;
        vector<int> ans;
        int i = n - first + 1,j = m - second + 1;
        while (i <= n or j <= m){
//        cout << i << "(" << nums1[i] << ")" <<" <-> " << j << "(" << nums2[j] << ")" << endl;
            if (((i <= n and j <= m) and (*s1.rbegin() > *s2.rbegin())) or (i <= n and j == m + 1) or
                    (*s1.rbegin() == *s2.rbegin() and )){
                ans.push_back(*s1.rbegin());
//            s1.erase(ans.back());
//            cout << "first" << endl;
                auto pos = find(nums1.begin(), nums1.end(),ans.back());
                if (i != n){
                    s1 = multiset(pos + 1, nums1.begin() + i + 1);
                }
                ++i;
            } else if (((i <= n and j <= m) and *s1.rbegin() < *s2.rbegin()) or (i == n + 1 and j <= m)){
                ans.push_back(*s2.rbegin());
//            cout << "second" << endl;
                auto pos = find(nums2.begin(), nums2.end(),ans.back());
                if (j != m){
                    s2 = multiset(pos + 1, nums2.begin() + j + 1);
                }
                ++j;
            }
        }
        return ans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
//        cout << "get" << endl;
        int n = nums1.size(),m = nums2.size();
        vector<multiset<int>> proc1,proc2;
        int space = m + n - k;
        vector<int> final;
        for (int i = min(n,k);i >= 0;--i){
            if (k - i > m) break;
//            cout << "| " << i << " <-> " << k - i << " |" << endl;
            vector<int> res = getdone(n,m,i,k - i,nums1,nums2);
            final = max(final,res);
            for (auto j : res) cout << j << " ";
            cout << endl;
        }
        return final;
    }
};
//    if (k > n){
//        for (int i = n;i >= 0;--i){
//            if (k - i > m) break;
//            getdone(i,k - i,nums1,nums2);
//        }
//    } else {
//        for (int i = k;i >= 0;--i){
//            if (k - i > m)
//        }
//    }

int main(){
    Solution test;
    vector<int> eg3 = {3, 4, 6, 5};
    vector<int> eg4 = {9, 1, 2, 5, 8, 3};
    cout << "here" << endl;
    vector<int> res2 = test.maxNumber(eg3,eg4,5);
    for (auto k : res2) cout << k << " ";
    cout << endl << string(20,'-') << endl;
    vector<int> eg1 = {1,3,8,6,5,2,9};
    vector<int> eg2 = {7,6,8};
    vector<int> res1 = test.maxNumber(eg1,eg2,5);
    for (auto k : res1) cout << k << " ";
    cout << endl << string(20,'-') << endl;
    vector<int> eg5 = {6,7};
    vector<int> eg6 = {6,0,4};
    vector<int> res3 = test.maxNumber(eg5,eg6,5);
    for (auto k : res3) cout << k << " ";

}
// xv6 os
// Medicine
// Clion problem
//
// Created by ASUS on 2023/8/14.
//

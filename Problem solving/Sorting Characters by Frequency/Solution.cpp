#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Node{
    int freq;
    char val;
};


bool sortFunction(Node A, Node B){
    return A.freq>B.freq;
}
class Solution {
public:
    string frequencySort(string s) {
        int i;
        vector<Node> chars;
        for(i=0;s[i]!='\0';i++){
            vector<Node>::iterator it;
            for(it=chars.begin();it!=chars.end();++it){
                if(it->val==s[i]){
                    it->freq++;
                    break;
                }
            }
            if(it==chars.end()){
                Node node;
                node.freq=1;
                node.val=s[i];
                chars.push_back(node);
            }
        }
        sort(chars.begin(), chars.end(), sortFunction);
        char* result = new char[i+1];
        i=0;
        for(vector<Node>::iterator it = chars.begin();it!=chars.end();++it){
            Node node = *it;
            memset(result+i, node.val, node.freq);
            i+=node.freq;
        }
        result[i]='\0';
        return string(result);
    }
};
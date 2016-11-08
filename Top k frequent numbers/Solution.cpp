/*
 Solution contains merge sort, quick sort implementations too
*/


#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

struct Node{
    int val;
    int count;
};

bool sortVals(Node a, Node b){
	return a.count>b.count;
}

void quicksort(vector<Node>& vals, int size){
    int lo, hi, plo=0, phi=size-1;
    while(plo<phi){
        for(lo=plo+1;lo<=phi;lo++){
            if(vals[lo].count>vals[plo].count){
                Node temp = vals[lo];
                vals[lo]=vals[plo];
                vals[plo]=temp;
            }
        }
        for(hi=phi-1;hi>plo;hi--){
            if(vals[phi].count>vals[hi].count){
                Node temp=vals[hi];
                vals[hi]=vals[phi];
                vals[phi]=temp;
            }
            
        }
        plo++, phi--;
    }
}



void merge(vector<Node>& vals, int start, int end){
    int mid=(start+end+1)/2, i=start, j=mid, k=0;
    Node res[end-start+1];
    while(i<mid && j<=end){
        if(vals[i].count<vals[j].count) res[k++]=vals[j++];
        else res[k++]=vals[i++];
    }
    while(i<mid) res[k++]=vals[i++];
    while(j<=end) res[k++]=vals[j++];
    k=0;
    for(i=start; i<=end;i++) vals[i]=res[k++];
}

void mergesort(vector<Node>& vals, int start, int end){
    if(end<=start) return;
    int mid=(start+end+1)/2;
    mergesort(vals, start, mid-1);
    mergesort(vals, mid, end);
    merge(vals, start, end);
}



vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> freq;
    vector<Node> vals;
    for(vector<int>::iterator it = nums.begin(); it!=nums.end();++it){
        if(freq.find(*it)==freq.end()) freq[*it]=1;
        else freq[*it]++;
    }
    for(map<int, int>::iterator it = freq.begin(); it!=freq.end(); ++it){
        Node node;
        node.val=it->first;
        node.count=it->second;
        vals.push_back(node);
    }
   // mergesort(vals, 0, vals.size()-1);
   //sort(vals.begin(), vals.end(), sortVals);
   quicksort(vals, vals.size());
    vector<int> result;
    for(int i=0;i<k;i++){
        result.push_back(vals[i].val);
    }
    return result;
}

int main(){
	int n, k, x;
	scanf("%d%d", &n, &k);
	vector<int> arr;
	while(n--){
		scanf("%d",&x);
		arr.push_back(x);
	}
	arr = topKFrequent(arr, k);
	for(vector<int>::iterator it=arr.begin(); it!=arr.end();++it)
		printf("%d ",*it);
}

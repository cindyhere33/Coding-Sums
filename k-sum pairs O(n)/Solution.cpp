#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main() {
	int t, i, x, found, n, k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		map<int, int> needed;
		found=0;
		for(i=0;i<n;i++){
			scanf("%d",&x);
			if(needed.find(x)!=needed.end()) found+=needed[x]; 
			if(needed.find(k-x)!=needed.end())	needed[k-x]++;
			else needed[k-x]=1;
		}
		printf("%d\n", found);
	}
	return 0;
}
My submission link: https://www.codechef.com/viewsolution/11945590
#include <cstdio>

int main() {
	int t, i, curMax, n, x, ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n<1) {
			printf("0\n");
			return 0;
		}
		scanf("%d", &curMax);
		for(i=1, ans=1;i<n;i++){
			scanf("%d",&x);
			if(x<=curMax) curMax=x, ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
int n, _max, sum[100000];

class _time{
public:
	int t_come;
	int t_eat;
};

_time a[100000];

bool compare(const _time &x, const _time &y){
	return x.t_come < y.t_come;
}

void checkF(int x){
	int temp;
	temp = sum[x];
	a[x].t_come = 0;
	if(temp > _max)
		return;
	for(int i=x+1; i<n; i++){
			if(temp <= a[i].t_come){
				checkF(i);
				break;
			}
	}
}

void Res(){
	int count = 0;
	for(int i=0; i<n; i++)
		if(a[i].t_come != 0){
			count++;
			checkF(i);
		}
	cout << count;
}

int main(){
	cin >> n;

	for(int i=0; i<n; i++)
		cin >> a[i].t_come;
	for(int i=0; i<n; i++)	
		cin >> a[i].t_eat;	
		
	sort(a,a + n,compare);
	
	for(int i=0; i<n; i++)	
		sum[i] = a[i].t_come + a[i].t_eat;
		
	_max = a[n-1].t_come;
	
	Res();
	
	return 0;
}

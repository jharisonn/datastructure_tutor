#include <cstdio>
#include <queue>
using namespace std;

int main(){
	queue<int> q;
	q.push(5);
	q.push(10);
	
	while(!q.empty()){
		int data = q.front();
		printf("%d\n",data);
		q.pop();
	}
}

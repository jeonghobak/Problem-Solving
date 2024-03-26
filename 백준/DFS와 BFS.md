# DFS와 BFS

### 문제 출처
https://www.acmicpc.net/problem/1260

### Comment
제목 그대로 DFS와 BFS 를 사용하면 되는 문제.  
`정점 번호가 작은 것을 먼저 방문`해야한다는 제약이 있기에 탐색 전 인접 리스트의 연결 요소들을 오름차순으로 정렬해야 한다는 점을 주의 해야 한다.

### Code
```cpp
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<vector<int>> adj( 1001 );
vector<bool> isvisit( 1001, false );

int n;
int m;
int v;

void DFS( int curVtx )
{
	isvisit[ curVtx ] = true;
	cout << curVtx << " ";
	for ( const auto connected_Vtx : adj[ curVtx ] ) {
		if ( !isvisit[ connected_Vtx ] ) {
			DFS( connected_Vtx );
		}
	}
}

void BFS()
{
	queue<int> q;
	isvisit[ v ] = true;
	q.push( v );

	while ( !q.empty() ) {
		const auto curVtx = q.front();
		cout << curVtx << " ";
		q.pop();

		for ( const auto connected_Vtx : adj[ curVtx ] ) {
			if ( !isvisit[ connected_Vtx ] ) {
				isvisit[ connected_Vtx ] = true;
				q.push( connected_Vtx );
			}
		}
	}
}

int main()
{
	cin.tie( nullptr );
	cout.tie( nullptr );
	cin.sync_with_stdio( false );
	
	cin >> n >> m >> v;
	
	for ( int i = 1; i <= m; ++i ) {
		int a = 0;
		int b = 0;
		cin >> a >> b;
		adj[ a ].push_back( b );
		adj[ b ].push_back( a );
	}

	for ( int i = 1; i <= n; ++i ) {
		sort( adj[ i ].begin(), adj[ i ].end() );
	}

	DFS( v );
	std::cout << '\n';
	
	fill( isvisit.begin(), isvisit.end(), false );
	
	BFS();
	std::cout << '\n';

	return 0;
}
```

다시 풀어 보기
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj( 1001 );
vector<bool> isvisit( 1001, false );
queue<int> q;

void dfs( const int cur ) noexcept;
void bfs( const int start ) noexcept;

int main()
{
	int n = 0;
	int m = 0;
	int v = 0;
	
	cin >> n >> m >> v;
	
	for ( int i = 1; i <= m; ++i )
	{
		int s = 0;
		int e = 0;	

		cin >> s >> e;

		adj[ s ].push_back( e );
		adj[ e ].push_back( s );
	}

	for ( int i = 1; i <= n; ++i )
	{
		sort( adj[ i ].begin(), adj[ i ].end() );
	}

	// DFS
	dfs( v );
	cout << '\n';

	/// BFS
	fill( isvisit.begin(), isvisit.end(), false );
	bfs( v );
	cout << '\n';
}

void dfs( const int cur ) noexcept
{
	isvisit[ cur ] = true;
	
	cout << cur << " ";

	for ( int next : adj[ cur ] )
	{
		if ( ! isvisit[ next ] )
		{
			dfs( next );
		}
	}
}

void bfs( const int start ) noexcept
{
	q.push( start );

	isvisit[ start ] = true;

	while ( ! q.empty() )
	{
		const int cur = q.front();		
		q.pop();			
		cout << cur << " ";
		
		for ( int next : adj[ cur ] )
		{
			if ( ! isvisit[ next ] )
			{
				isvisit[ next ] = true;
				q.push( next );
			}
		}
	}
}

```

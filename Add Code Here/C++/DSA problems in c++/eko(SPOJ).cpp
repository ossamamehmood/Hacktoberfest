#include <iostream>
#define ll long long int
using namespace std;

bool isPossible(ll *arr, ll n, ll m, ll mid)
{
	ll sum = 0;

	for (ll i = 0; i < n; i++)
	{
		if (arr[i] > mid)
		{
			sum = sum + (arr[i] - mid);
		}
	}
	if (sum >= m)
		return true;
	else
		return false;
}

int main()
{
	// your code goes here
	ll n, m;
	cin >> n >> m;

	ll s = 0;
	ll arr[n];
	ll maxi = -1;

	for (ll i = 0; i < n; i++)
	{
		cin >> arr[i];
		maxi = max(maxi, arr[i]);
	}

		ll ans = -1;
		ll e = maxi;
		ll mid = s + (e - s) / 2;

		while (s <= e)
		{
			if (isPossible(arr, n, m, mid))
			{
				ans = mid;
				s = mid + 1;
			}
			else
				e = mid - 1;
			mid = s + (e - s) / 2;
		}

		cout << ans;

		return 0;
	}
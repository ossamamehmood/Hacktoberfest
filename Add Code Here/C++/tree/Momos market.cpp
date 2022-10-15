/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


/*
				PROBLEM STATEMENT
Shreya loves to eat momos. Her mother gives her money to buy vegetables but she 
manages to save some money out of it daily. After buying vegetables, she goes to 
"Momos Market", where there are ‘n’ number of shops of momos. Each of the shop of
momos has a rate per momo. She visits the market and starts buying momos (one from 
each shop) starting from the first shop. She will visit the market for ‘q’ days.
You have to tell that how many momos she can buy at each day if she starts buying 
from the first shop daily. She cannot use the remaining money of one day on some other 
day. But she will save them for other expenses in future, so, 
you also need to tell the sum of money left with her at the end of each day.
*/

#include <bits/stdc++.h>

using namespace std;
pair<int, int> go(vector<int> sum, int q){
	//cout << "q "<<q << '\n';
	
	//Getting just greater index
	int pos = lower_bound(sum.begin(), sum.end(), q)-sum.begin();
	if (pos>sum.size()-1)
	{
		pos--;
	}
	if (sum.at(pos) > q)
	{
		pos--;
	}
	//cout << "Position "<< pos << '\n';
	
	if (pos<0)
	{
		int momos = 0;
		int money_left = q;
		return {momos, money_left};	
	}
	

	int momos = pos+1;
	int money_left = q-sum.at(pos);
	return {momos, money_left};

}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;

	std::vector<int> v;
	std::vector<int> sum;
	int temp_sum = 0;

	while(n--){
		int a;
		cin>>a;
		v.push_back(a);
		temp_sum+=a;
		sum.push_back(temp_sum);
	}

	int q;
	cin>>q;
	while(q--){
	int total_money;
	cin>>total_money;
	
	pair<int, int> ans = {0,0};
	ans = go(sum, total_money);

	cout << ans.first<<" "<< ans.second << '\n';
	
	}

	return 0 ; 



}

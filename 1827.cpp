#include <bits/stdc++.h>

using namespace std;

void draw_main_diagonal(vector<vector<int> > &sqr)
{
	for ( int i = 0 ; i < sqr.size() ; i++ )
		sqr[i][i] = 2;
}

void draw_secundary_diagonal(vector<vector<int> > &sqr)
{
	for ( int i = 0 ; i < sqr.size() ; i++ )
		sqr[i][sqr.size() - i - 1] = 3;
}

void draw_four_in_middle(vector<vector<int> > &sqr)
{
	int locale = sqr.size()/2;
	sqr[locale][locale] = 4;
}

void draw_specified_square(vector<vector<int> > &sqr )
{
	int start = sqr.size()/3;
	int last = sqr.size() - start;
	draw_main_diagonal(sqr);
	draw_secundary_diagonal(sqr);
	for ( int i = start ; i < last ; i++ )
	{
		for ( int j = start ; j < last ; j++ )
			sqr[i][j] = 1;
	}
	draw_four_in_middle(sqr);
}

void print(vector<vector<int> > &sqr)
{
	for ( int i = 0 ; i < sqr.size() ; i++ )
	{
		for ( int j = 0 ; j < sqr.size() ; j++ )
		{
			cout << sqr[i][j];
		}
		cout << "\n";
	}
}

main()
{
	int n;
	while ( cin >> n )
	{
		vector<vector<int> > sqr (n, vector<int>(n, 0));
		draw_specified_square(sqr);
		print(sqr);
		cout << "\n";
	}
}

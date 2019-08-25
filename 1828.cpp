#include <bits/stdc++.h>

using namespace std;

/*
As regras do jogo proposto são:

a tesoura corta o papel;
o papel embrulha a pedra;
a pedra esmaga o lagarto;
o lagarto envenena Spock;
Spock destrói a tesoura;
a tesoura decapita o lagarto;
o lagarto come o papel;
o papel contesta Spock;
Spock vaporiza a pedra;
a pedra quebra a tesoura.
*/

int spock(string other)
{
	if ( other == "tesoura" )
		return -1;
	else if ( other == "pedra" )
		return -1;
	else if ( other == "lagarto" )
		return 1;
	else if ( other == "papel" )
		return 1;
	return 0;
}

int lizard(string other)
{
	if ( other == "Spock" )
		return -1;
	else if ( other == "papel" )
		return -1;
	else if ( other == "pedra" )
		return 1;
	else if ( other == "tesoura" )
		return 1;
	return 0;
}

int paper(string other)
{
	if ( other == "pedra" )
		return -1;
	else if ( other == "Spock" )
		return -1;
	else if ( other == "lagarto" )
		return 1;
	else if ( other == "tesoura" )
		return 1;
	return 0;
}

int rock(string other)
{
	if ( other == "lagarto" )
		return -1;
	else if ( other == "tesoura" )
		return -1;
	else if ( other == "papel" )
		return 1;
	else if ( other == "Spock" )
		return 1;
	return 0;
}

int scissor(string other)
{
	if ( other == "papel" )
		return -1;
	else if ( other == "lagarto" )
		return -1;
	else if ( other == "Spock" )
		return 1;
	else if ( other == "pedra" )
		return 1;
	return 0;
}

int solve(string & sheldon_choice, string & raj_choice)
{
	if ( sheldon_choice == "pedra" )
		return rock(raj_choice);
	else if ( sheldon_choice == "papel" )
		return paper(raj_choice);
	else if ( sheldon_choice == "tesoura" )
		return scissor(raj_choice);
	else if ( sheldon_choice == "lagarto" )
		return lizard(raj_choice);
	else if ( sheldon_choice == "Spock" )
		return spock(raj_choice);
}

main()
{
	int number_of_test_cases;
	cin >> number_of_test_cases;
	int case_number = 1;
	while ( number_of_test_cases-- != 0 )
	{
		string sheldon_choice, raj_choice;
		cin >> sheldon_choice >> raj_choice;
		int answer = solve(sheldon_choice, raj_choice);
		cout << "Caso #" << case_number++ << ": " 
			<< ( answer == -1 ? "Bazinga!" : 
				( answer == 1 ? "Raj trapaceou!" : "De novo!") )
			<< "\n";
	}
}

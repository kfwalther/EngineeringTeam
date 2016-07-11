
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "questions.h"
#include "parser.h"

using namespace std;

void main()
{
	queue <questions> Q;
	string c = "category1.csv";
	parser Parse;
	Parse.parseCategory(Q, c);
	cout << c << " " << Q.size() << endl;
}


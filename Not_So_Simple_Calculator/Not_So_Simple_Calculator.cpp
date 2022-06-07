#include <iostream>
#include <string>
#include <stack>
// #include <sstream>
#include <algorithm>

/* Used sources:
* https://eduinf.waw.pl/inf/utils/010_2010/0410.php
* https://www.algorytm.edu.pl/algorytmy-maturalne/onp
* https://www.szkolazpasja.pl/onp-np-notacja-infiksowa/
* https://www.youtube.com/watch?v=zla7ha0OORM
* https://www.youtube.com/watch?v=7ha78yWRDlE
* https://www.youtube.com/watch?v=qN8LPIcY6K4
* https://www.youtube.com/watch?v=pg4JpKdKcMw
*/

using std::cout;
using std::cin;
using std::endl;



std::string rpn{};
std::string infix{};


// juz_zmienione = convertInfix(do_skonwertowania);

std::string convertInfix(const std::string& input) //takes infix and convert it into RPN notation ----> (a+b)*c/d ---> ab+c*d/
{
	std::string operators("*/%+-");
	std::stack<char>stos2{};
	std::string result{};
	for (auto x : input)
	{
		if (x >= '0' && x <= '9')
			result += x;
		else if (x == '(')
			stos2.push(x);
		else if (operators.find(x) != std::string::npos)
		{
			if (!stos2.size() == 0 && operators.find(stos2.top()) != std::string::npos)
			{
				if (operators.find(x) < operators.find(stos2.top()))
				{
					result += stos2.top();
					stos2.pop();
					stos2.push(x);
				}
				else
					stos2.push(x);
			}
			else
				stos2.push(x);
		}
		else if (x == ')')
		{
			while (stos2.top() != '(')
			{
				result += stos2.top();
				stos2.pop();
			}
			stos2.pop();
		}
	}
	while (!stos2.empty())
	{
		result += stos2.top();
		stos2.pop();
	}
	return result;
}

std::string removeBlanks(std::string rpn_input) // remove space from RPN sequence
{
	rpn_input.erase(remove(rpn_input.begin(), rpn_input.end(), ' '), rpn_input.end());
	return rpn_input;
}

/*
std::string calculate(std::string rpn)
{
	std::stack<int>stos{};

	for (auto x : rpn)
	{
		int valA{}, valB{};
		if (x >= '0' && x <= '9')
			stos.push(x - 48); // push to stack and convert value from ASCII to int value
		else
		{
			valB = stos.top();
			stos.pop();

		}
	}
}
*/

int main()
{
	cout << "Welcome to the RPN Calculator\n" << endl;
	do {
		cout << "Write infix expression:\n" << endl;
		cin >> infix;
		rpn = convertInfix(infix);
		cout << "\nConverted infix expresion ---> " << infix << " <--- to RPN ---> " << rpn << " <---\n" << endl;


	} while (true);


}


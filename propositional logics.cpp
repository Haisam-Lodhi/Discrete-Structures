#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

// Function to determine precedence of operators
int precedence(const string &op) {
	if (op == "->" || op == "=")
		return 1; // -> (implication), = (biconditional) have lower precedence
	else if (op == "&" || op == "|")
		return 2; // & (and), | (or) have higher precedence
	else if (op == "!")
		return 3; // NOT (!) has highest precedence
	return 0;
}

// Function to evaluate binary operations
bool evalBinary(bool left, const string &op, bool right) {
	if (op == "&") return left && right;
	if (op == "|") return left || right;
	if (op == "->") return !left || right; // Implication (!p | q)
	if (op == "=") return (!left || right) && (!right || left); // Biconditional (!p | q) & (!q | p)
	return false;
}

// Function to evaluate unary operations
bool evalUnary(const string &op, bool value) {
	return op == "!" ? !value : value;
}

// Function to parse and evaluate logical expressions
bool evaluateExpression(const string &expr, int &index, const vector<bool> &varValues, const vector<char> &variables) {
	vector<bool> operands;
	vector<string> operators;

	auto applyOperator = [&]() {
		if (operators.empty() || operands.size() < 2) return;
		bool right = operands.back();
		operands.pop_back();
		bool left = operands.back();
		operands.pop_back();
		string op = operators.back();
		operators.pop_back();
		operands.push_back(evalBinary(left, op, right));
	};

	while (index < expr.size()) {
		if (expr[index] == ' ') {
			index++;
			continue;
		}

		if (expr[index] == '(') {
			index++;
			operands.push_back(evaluateExpression(expr, index, varValues, variables));
		}
		else if (expr[index] == ')') {
			index++;
			break;
		}
		else if (isalpha(expr[index])) {
			auto it = find(variables.begin(), variables.end(), expr[index]);
			if (it != variables.end()) {
				operands.push_back(varValues[it - variables.begin()]);
			}
			index++;
		}
		else if (expr[index] == '1' || expr[index] == '0') {
			operands.push_back(expr[index] == '1');
			index++;
		}
		else if (expr[index] == '!') {
			index++;
			bool value = evaluateExpression(expr, index, varValues, variables);
			operands.push_back(evalUnary("!", value));
		}
		else if (expr[index] == '-' && expr[index + 1] == '>') {
			operators.push_back("->");
			index += 2;
		}
		else if (expr[index] == '&' || expr[index] == '|' || expr[index] == '=') {
			while (!operators.empty() && precedence(string(1, expr[index])) <= precedence(operators.back())) {
				applyOperator();
			}
			operators.push_back(string(1, expr[index]));
			index++;
		}
	}

	while (!operators.empty()) {
		applyOperator();
	}

	return !operands.empty() ? operands.back() : false;
}

// Function to print the truth table for a logical expression
void printTruthTable(const string &expr, const vector<char> &variables) {
	int numVars = variables.size();
	int numRows = pow(2, numVars);

	// Print header
	for (char var : variables) {
		cout << var << " | ";
	}
	cout << "Result" << endl;

	// Print separator
	for (size_t i = 0; i < variables.size(); i++) {
		cout << "--- ";
	}
	cout << "-------" << endl;

	for (int i = 0; i < numRows; ++i) {
		vector<bool> varValues(numVars);

		// Assign values to variables based on binary representation of i
		for (int j = 0; j < numVars; ++j) {
			varValues[j] = (i & (1 << (numVars - 1 - j))) != 0;
			cout << (varValues[j] ? "T" : "F") << " | ";
		}

		int index = 0;
		bool result = evaluateExpression(expr, index, varValues, variables);
		cout << (result ? "T" : "F") << endl;
	}
}

// Function to check equivalence of two expressions
bool checkEquivalence(const string &expr1, const string &expr2) {
	vector<char> variables;

	// Collect all variables from both expressions
	for (char ch : expr1 + expr2) {
		if (isalpha(ch) && find(variables.begin(), variables.end(), ch) == variables.end()) {
			variables.push_back(ch);
		}
	}

	int numVars = variables.size();
	int numRows = pow(2, numVars);

	for (int i = 0; i < numRows; ++i) {
		vector<bool> varValues(numVars);

		// Assign values to variables
		for (int j = 0; j < numVars; ++j) {
			varValues[j] = (i & (1 << (numVars - 1 - j))) != 0;
		}

		int index1 = 0, index2 = 0;
		bool result1 = evaluateExpression(expr1, index1, varValues, variables);
		bool result2 = evaluateExpression(expr2, index2, varValues, variables);

		if (result1 != result2) {
			return false;
		}
	}

	return true;
}

int main() {
	string expr1, expr2;
	cout << "& for AND, | for OR, ! for NOT, -> for implication, = for biconditional\n";

	cout << "Enter first logical expression: ";
	getline(cin, expr1);
	cout << "Enter second logical expression: ";
	getline(cin, expr2);

	// Print truth table for the first expression
	vector<char> variables;
	for (char ch : expr1) {
		if (isalpha(ch) && find(variables.begin(), variables.end(), ch) == variables.end()) {
			variables.push_back(ch);
		}
	}

	cout << "\nTruth Table for Expression 1:" << endl;
	printTruthTable(expr1, variables);

	// Print truth table for the second expression
	cout << "\nTruth Table for Expression 2:" << endl;
	printTruthTable(expr2, variables);

	// Check equivalence
	bool equivalent = checkEquivalence(expr1, expr2);
	if (equivalent) {
		cout << "Both statements are logically equivalent" << endl;
	}
	else {
		cout << "Statements are not logically equivalent" << endl;
	}
	system("pause");
	return 0;
}

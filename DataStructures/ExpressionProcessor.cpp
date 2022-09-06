#include "List.h"
#include "FileLoader.h"
#include "ExpressionProcessor.h"
using namespace std;

void ExpressionProcessor::ProcessFiles() {

	FileLoader loader;

	int count = loader.LoadFiles();

	for (int i = 0; i < 5; i++)
	{

		ProcessInfixExpression(loader.GetListToProcess());

		cout << "START Display Expression List " + to_string(i + 1) << endl;
		expressionList.DisplayString();
		cout << "END Display Expression List file " + to_string(i + 1) << endl;

		cout << "START Evaluate Expression List " + to_string(i + 1) << endl;
		EvaluateExpression();
		cout << "END Evaluate Expression List file " + to_string(i + 1) << endl;

		expressionList.~List();

		cout << "     " << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << "     " << endl;
	}

}

void ExpressionProcessor::DisplayExpressionList() {
	expressionList.DisplayString();
}

void ExpressionProcessor::ProcessInfixExpression(List list) {

	int length = list.Length();

	for (int i = 0; i <= length; i++) {
		string element = list.PopElement();
		if (CheckIfNumber(element)) {
			expressionList.Push(element);
		}
		else if (operatorStack.IsEmpty() || CompareEqualsOperators(GetPriorityStack(operatorStack.GetTop()), GetPriorityElement(element)))
		{
			if ( GetPriorityStack(operatorStack.GetTop()) == GetPriorityElement(element))
			{
				if (CheckIfNumber(element))
				{
					expressionList.Push(operatorStack.Pop());
					
				}
				if (element != ")")
				{
					operatorStack.Push(element);
				}
			}
			else if (CheckEndParenthesis(element) || element == "") {
				string outOperator = "";
				int currentStackCount = operatorStack.Length();
				for (int j = 0; j < currentStackCount; j++)
				{
					outOperator = operatorStack.Pop();
					if (outOperator != "(" )
					{
						expressionList.Push(outOperator);
					}
				}
			}
			else if (element != ")") {
				operatorStack.Push(element);
			}
			
		}
		else if (!CheckEndParenthesis (element) && CompareOperators(GetPriorityStack(operatorStack.GetTop()), GetPriorityElement(element))) {
			expressionList.Push(operatorStack.Pop());
			operatorStack.Push(element);
		}
		else if (CheckEndParenthesis(element) ) {
			string outOperator = "";
			for (int j = 0; j < operatorStack.Length(); j++)
			{
				outOperator = operatorStack.Pop();
				if (outOperator != "(")
				{
					expressionList.Push(outOperator);
				}
			}
		} 
	}
}

int ExpressionProcessor::GetPriorityStack(string stringOperator) {
	if (stringOperator == "+" || stringOperator == "-") {
		return 1;
	}
	else if (stringOperator == "*" || stringOperator == "/") {
		return 2;
	}
	else if (stringOperator == "^") {
		return 3;
	}
	else if (stringOperator == "(") {
		return 0;
	}
}

int ExpressionProcessor::GetPriorityElement(string stringOperator) {
	if (stringOperator == "+" || stringOperator == "-") {
		return 1;
	}
	else if (stringOperator == "*" || stringOperator == "/") {
		return 2;
	}
	else if (stringOperator == "^") {
		return 4;
	}
	else if (stringOperator == "(") {
		return 5;
	}
}

bool ExpressionProcessor::CheckIfNumber(string elementOperator) {

	try {
		int num = stoi(elementOperator);
		return true;
	}
	catch (std::exception& e) {
		return false;
	}
}

bool ExpressionProcessor::CheckEndParenthesis(string elementOperator)
{
	return elementOperator == ")";
}

bool ExpressionProcessor::CompareOperators(int stackOperator, int elementOperator) {
	return elementOperator < stackOperator;
}

bool ExpressionProcessor::CompareEqualsOperators(int stackOperator, int elementOperator) {
	return elementOperator >= stackOperator;
}

void ExpressionProcessor::EvaluateExpression() {

	int length = expressionList.Length();

	int num1 = NULL;

	int num2 = NULL;

	int result = 0;

	for (int i = 0; i <= length; i++) {
		string element = expressionList.PopElement();

		if (CheckIfNumber(element) && num1 == NULL)
		{
			num1 = stoi(element);
			continue;
		}

		if (CheckIfNumber(element) && num2 == NULL)
		{
			num2 = stoi(element);
			continue;
		}

		if (element == "+") {
			result +=  num1 + num2;
		}
		else if (element == "-") {
			result += num1 - num2;
		}
		else if (element == "*") {
			result += num1 * num2;
		}
		else if (element == "/" && num2 != 0) {
			result += num1 / num2;
		}
		else if (element == "^") {
			
			while (num1 != 0) {
				result *= num1;
				--num1;
			}
			
		}

		num1 = NULL;

		num2 = NULL;
	}
	cout << "Evaluated Expression List " + to_string(result) << endl;
}
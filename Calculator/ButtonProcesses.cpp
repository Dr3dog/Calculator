#include "ButtonProcesses.h"

enum Operators {
	add, subtract, divide, multiply
};

int Calculate(std::vector<int>* _vals, std::vector<int>* _operation) {
	int answer = 0;
	if (_vals->size() != 0 && _vals->size() < 2)
	{
		answer = _vals->at(0);
	}
	for (int i = 0; i < _operation->size(); i++)
	{
		switch (_operation->at(i))
		{
		case divide:
		{
			_vals->at(i + 1) = _vals->at(i) / _vals->at(i + 1);
			break;
		}
		case multiply:
		{
			_vals->at(i + 1) *= _vals->at(i);
			break;
		}
		case subtract:
		{
			_vals->at(i + 1) = _vals->at(i) - _vals->at(i + 1);
			break;
		}
		case add:
		{
			_vals->at(i + 1) += _vals->at(i);
			break;
		}
	}
	answer = _vals->at(_vals->size() - 1);
	return answer;
}
#pragma once
#include <vector>
using namespace std;
class ButtonProcesses
{
public:
	static ButtonProcesses& GetInstance()
	{
		static ButtonProcesses instance;
		return instance;
	};
	int Calculate(std::vector<int>* _vals, std::vector<int>* _operation);
private:
	ButtonProcesses() {};
	ButtonProcesses(ButtonProcesses const&) = delete;
	void operator = (ButtonProcesses const&) = delete;
	std::vector<int>* calcValues;
	std::vector<int>* operatorIDs;
};


#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std; 



const int FRESHERS = 5; 
class CallHandler{
	static int LEVELS = 3; 
	vector<vector<Employee>> EmployeeLevel[LEVELS];
	vector<queue<Call>> callQ[LEVELS];
	CallHandler(){.....} //Call the constructor
	Employee getCallHandler(Call call){
		for(int i = call.Rank; i<LEVELS-1;i++){
			vector<Employee> emp = EmployeeLevel[i];
			for(Employee e:emp){
				if(e.free)
					return e; 
			}
		}
		return NULL; 
	}
	void DispatchCall(Call call){
		Employee emp = getCallHandler(call);
		if(emp!=NULL){
			emp.ReceiveCall(call);
		}else{
			callQ[call.Rank].push(call);
		}
	}

};

class Call{
	int rank =0; 
	void reply(string message);
	void disconnect();
}

class Employee
{
public:
	CallHandler handler; 
	int rank; 
	bool free; 
	Employee(int r){
		rank=r;
	}
	void ReceiveCall(Call call);// Call received
	void CallHandled(Call call); //call complete
	void CannotHandle(Call call){  //escalate call
		call.rank = rank+1; 
		CallHandler.DispatchCall(Call);
		free=true; 
	} 
	
	class Fresher : public Employee{
		Fresher(int rank):Employee(rank);
	}
	class TechLead: public Employee{
		TechLead(int rank):Employee(rank);
	}
	class Manager:public Employee{
		Manager(int rank):Employee(rank);
	}
};

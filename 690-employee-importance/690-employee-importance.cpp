/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mapping;
        for (auto employee: employees) mapping[employee->id] = employee;
        int res = 0;
        function<int(Employee*)> traverse = [&](Employee* e) -> int {
            int counter = mapping[e->id]->importance;
            for (auto childId: e->subordinates) counter += traverse(mapping[childId]);
            return counter;
        };
        return traverse(mapping[id]);
    }
};
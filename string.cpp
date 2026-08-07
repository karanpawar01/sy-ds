#include<iostream>
#include<string>
 using namespace std;
  
   struct Employee{
   	
   	int id;
   	string name;
   	float salary;
   	Employee*next;
   };
   
   Employee*head =NULL;
   
   void insertEmployee(){
   	Employee*newnode=new Employee;
   	
   	cout<<" enter employee ID:";
   	cin>> newnode->id;
   	
   	cout<<"enter employee Name:";
   	cin>> newnode->name;
   	
   	cout<<"enter employee Salary:";
   	cin>> newnode->salary;
   	};
   	
   	newnode->next = NULLptr;

    if (head == NULLptr)
    {
        head = newnode;
    };
    else
    {
        Employee *temp = head;
        while (temp->next != NULLptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    cout << "Employee inserted successfully.\n";
}

void deleteEmployee()
{
    if (head == NULLptr)
    {
        cout << "List is empty.\n";
        return;
    }

    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    Employee *temp = head;
    Employee *prev = NULLptr;

    while (temp != NULLptr && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULLptr)
    {
        cout << "Employee not found.\n";
        return;
    }

    if (prev == NULLptr)
    {
        head = head->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Employee deleted successfully.\n";
}

void searchEmployee()
{
    if (head == NULLptr)
    {
        cout << "List is empty.\n";
        return;
    }

    int id;
    cout << "Enter Employee ID to search: ";
    cin >> id;

    Employee *temp = head;

    while (temp != NULLptr)
    {
        if (temp->id == id)
        {
            cout << "\nEmployee Found\n";
            cout << "ID     : " << temp->id << endl;
            cout << "Name   : " << temp->name << endl;
            cout << "Salary : " << temp->salary << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Employee not found.\n";
}

void displayEmployees()
{
    if (head == NULLptr)
    {
        cout << "No employee records available.\n";
        return;
    }

    Employee *temp = head;

    cout << "\nEmployee Records\n";
    cout << "-----------------------------\n";

    while (temp != nullptr)
    {
        cout << "ID     : " << temp->id << endl;
        cout << "Name   : " << temp->name << endl;
        cout << "Salary : " << temp->salary << endl;
        cout << "-----------------------------\n";

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Employee Management System =====\n";
        cout << "1. Insert Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Search Employee\n";
        cout << "4. Display Employees\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertEmployee();
            break;

        case 2:
            deleteEmployee();
            break;

        case 3:
            searchEmployee();
            break;

        case 4:
            displayEmployees();
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}

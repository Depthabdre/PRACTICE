#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Linked list node structure for stack
struct Node
{
    char data;
    Node *next;
};

Node *topPtr = nullptr; // Stack pointer

// Stack operations
void topPtr_push(char ch)
{
    Node *newNode = new Node();
    newNode->data = ch;
    newNode->next = topPtr;
    topPtr = newNode;
}

char topPtr_pop()
{
    if (topPtr == nullptr)
    {
        cout << "ALERT!!!! Stack is Empty!!!!\n";
        return '\0';
    }
    Node *temp = topPtr;
    char pop_ele = topPtr->data;
    topPtr = topPtr->next;
    delete temp;
    return pop_ele;
}

bool Check_Palindrome()
{
    string num;
    cout << "Enter Number: ";
    cin >> num;

    // Push characters onto the stack
    for (char ch : num)
    {
        topPtr_push(ch);
    }

    // Construct reversed string
    string reversed = "";
    while (topPtr != nullptr)
    {
        reversed += topPtr_pop();
    }

    // Compare original and reversed strings
    if (num == reversed)
    {
        cout << "The number is a palindrome.\n";
        return true;
    }
    else
    {
        cout << "The number is not a palindrome.\n";
        return false;
    }
}
void Convert_Decimal_To_Binary()
{
    int Num;
    cout << "Enter Number: ";
    cin >> Num;
    char ch;
    int digit;
    while (Num > 0)
    {
        digit = Num % 2;
        ch = '0' + digit;
        topPtr_push(ch);
        Num /= 2;
    }
    string Binary = "";
    while (topPtr != nullptr)
    {
        Binary += topPtr_pop();
    }
    cout << "The number in binary format is: " << Binary << "\n";
}
void Evaluate_Post()
{
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    for (int i = 0; i < postfix.length(); i++)
    {
        if (isdigit(postfix[i]))
        {
            topPtr_push(postfix[i]);
        }
        else
        {
            char b = topPtr_pop();
            char a = topPtr_pop();

           
            int operandA = a - '0'; 
            int operandB = b - '0'; 

            
            int result;
            if (postfix[i] == '+')
            {
                result = operandA + operandB;
            }
            else if (postfix[i] == '-')
            {
                result = operandA - operandB;
            }
            else if (postfix[i] == '*')
            {
                result = operandA * operandB;
            }
            else if (postfix[i] == '/')
            {
                result = operandA / operandB; 
            }

            
            topPtr_push(result + '0'); 
        }
    }
    if (topPtr != nullptr) {
    char finalResult = topPtr_pop();  
    cout << "The result of the postfix expression is: " << finalResult - '0' << endl;  
} else {
    cout << "Error: Stack is empty, something went wrong during evaluation.\n";
}
}

int main()
{
    int choice;
    while (true)
    {
        cout << "\nStack Applications Menu\n";
        cout << "1. Check Palindrome\n";
        cout << "2. Convert Decimal to Binary\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Infix to Post fix Converter\n"; // THINK OF UNARY OPERATOR LIKE TRIG
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter Number to check for palindrome: ";
            bool is_pali = Check_Palindrome();
            // Call your palindrome check function here
        }
        else if (choice == 2)
        {
            cout << "Enter decimal number to convert to binary: ";
            Convert_Decimal_To_Binary();
            // Call your decimal-to-binary function here
        }
        else if (choice == 3)
        {
            cout << "Enter postfix expression to evaluate: ";
            Evaluate_Post();
        }
        else if (choice == 4)
        {
            cout << "Enter infix expression to evaluate: ";
            // Call your infix evaluation function here
        }
        else if (choice == 5)
        {
            cout << "Exiting program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

#include <iostream>
#include <cmath>
#include <cctype>
#include <limits>
#include <stdexcept>

using namespace std;

void checkValidInput()
{
    if (cin.fail()) //git
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Incorrect input");
    }
}

void checkValidParams_n(int n)
{
    if (cin.peek() != '\n' || n <= 1 || floor(n) != n)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Incorrect value of n (enter a positive integer value greater than 1)");
    }
}

void checkValidParams_x(double x)
{
    if (cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Incorrect value of x (enter a number)");
    }
}

void checkValidRange_a(double a)
{
    if (cin.peek() != '\n' || floor(a) != a)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Enter a valid integer number for 'a'");
    }
}

void checkValidRange_b(double b)
{
    if (cin.peek() != '\n' || floor(b) != b)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Enter a valid integer number for 'b'");
    }
}

void checkValidRange_a_b(double a, double b, int n)
{
    if (a > b)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Incorrect values of a and b (input b greater than a)");
    }
    else if (a == b)
    {
        throw invalid_argument("You have entered the same value for a and b.");
    }
}

void checkValidStep(double step, double a, double b)
{
    if (step <= 0 || step > abs(b - a) || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid step value (Input positive integer step; positive step or step that is less or equal to the range)");
    }
}

void checkValidChoice(int choice)
{
    if (cin.fail() || cin.peek() != '\n' || choice < 0 || choice > 2 || floor(choice) != choice)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Input a valid integer number (0, 1, or 2)!");
    }
}

void singleFunctionCalculation(int n, double x)
{
    double y = 0.0;

    try
    {
        if (x < 0)
        {
            for (int i = 0; i <= n; ++i)
            {
                double product = 1.0;
                for (int j = 0; j <= n + 1; ++j)
                {
                    product = product * (i - (j / 2.0));
                }
                y += product;
            }
        }
        else
        {
            double product = 1.0;
            for (int j = 1; j <= n; j++)
            {
                product = product * (j / (x + 3 * j));
            }
            y = x + product;
        }
    }
    catch (const exception& e)
    {
        cout << "An exception occurred: " << e.what() << endl;
    }

    cout << "x = " << x << " "
        << "Result = " << y << endl;
}

void rangeCalculation(int n, double a, double b, double step)
{
    try
    {
        checkValidStep(step, a, b);
        checkValidInput();

        for (double x = a; x <= b; x += step)
        {
            double y = 0.0;

            if (x < 0)
            {
                for (int i = 0; i <= n; ++i)
                {
                    double product = 1.0;
                    for (int j = 0; j <= n + 1; ++j)
                    {
                        product = product * (i - (j / 2.0));
                    }
                    y += product;
                }
            }
            else
            {
                double product = 1.0;
                for (int j = 1; j <= n; j++)
                {
                    product = product * (j / (x + 3 * j));
                }
                y = x + product;
            }

            cout << "x = " << x << " "
                << "Result = " << y << endl;
        }
    }
    catch (const invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (const exception& e)
    {
        cout << "An unexpected exception occurred: " << e.what() << endl;
    }
}

int main() {
    int choice;
    int n;
    double a, b, step, x;

    while (true) {
        cout << "\nHello, user!\nIf you want to calculate a single function - press '1'\nIf you want to calculate function within a certain range - press '2'\nIf you want to exit - press '0'\nYour choice : ";
        cin >> choice;

        try {
            checkValidChoice(choice);

            if (choice == 1) {
                cout << "Enter the value of n: ";
                cin >> n;
                checkValidParams_n(n);

                cout << "Enter the value of x: ";
                cin >> x;
                checkValidParams_x(x);

                singleFunctionCalculation(n, x);
            }
            else if (choice == 2) {
                cout << "Enter the value of 'n': ";
                cin >> n;
                checkValidParams_n(n);

                cout << "Enter the range [a, b]: a= ";
                cin >> a;
                checkValidRange_a(a);

                cout << "Enter the range [a, b]: b= ";
                cin >> b;
                checkValidRange_b(b);
                checkValidRange_a_b(a, b, n);

                cout << "Enter the step: ";
                cin >> step;
                checkValidStep(step, a, b);

                rangeCalculation(n, a, b, step);
            }
            else if (choice == 0) {
                cout << "You exited" << endl;
                break;
            }
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
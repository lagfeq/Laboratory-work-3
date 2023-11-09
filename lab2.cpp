#include <iostream>
#include <cmath>
#include <cctype>
#include <limits>

using namespace std;

int main()
{
    while (true)
    {
        int n, choice;
        double a, b, step, x, y, result;

        cout << "\nHello, user!\nIf you want to calculate a single function - press '1'\nIf you want to calculate function within a certain range - press '2'\nIf you want to exit - press '0'\nYour choice : ";

        if (!(cin >> choice) || cin.peek() != '\n')
        {
            cout << "Input a valid number (1, 2, or 0)!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1)
        {
            cout << "Enter the value of n: ";
            if (!(cin >> n) || cin.peek() != '\n' || n <= 1)
            {
                cout << "Incorrect value of n (enter an integer value that is greater than 1)" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cout << "Enter the value of x: ";
            if (!(cin >> x) || cin.peek() != '\n')
            {
                cout << "Incorect value of x (enter a number)" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (x < 0)
            {
                for (int i = 0; i <= n; ++i)
                {
                    double product = 1.0;
                    for (int j = 0; j <= n + 1; ++j)
                    {
                        product = product * (i - (j / 2.0));
                    }
                    y = y + product;
                }
                cout << "x= " << x << " "
                     << "Result= " << y << endl;
                continue;
            }
            else
            {
                double product = 1.0;
                for (int j = 1; j <= n; j++)
                {
                    product = product * (static_cast<double>(j) / (x + 3 * j));
                }
                result = x + product;
                cout << "x= " << x << " "
                     << "Result = " << result << endl;
                continue;
            }
        }

        else if (choice == 2 && cin.peek() == '\n')
        {
            cout << "Enter the range [a, b]: a= ";
            if (!(cin >> a) || cin.peek() != '\n')
            {
                cout << "Enter a valid number for 'a'." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cout << "Enter the range [a, b]: b= ";
            if (!(cin >> b) || cin.peek() != '\n')
            {
                cout << "Enter a valid number for 'b'." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (a > b)
            {
                cout << " Incorrect values of a and b (input b greater than a)";
                continue;
            }
            else if (a == b)
            {
                cout << "You have entered the same value for a and b. Enter the value of 'n' to calculate it as a single function: ";
                if (!(cin >> n) || cin.peek() != '\n' || n <= 1)
                {
                    cout << "Enter n as integer that is greater than 1" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else if (a < 0 && b < 0)
                {
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
                                    product = product * (i - (j /
                                                              2.0));
                                }
                                y += product;
                            }
                        }
                        cout << "x= " << x << " "
                             << "Result= " << y << endl;
                    }
                    continue;
                }
                else
                {

                    for (double x = a; x <= b; x += step)
                    {
                        double product = 1.0;
                        for (int j = 1; j <= n; j++)
                        {
                            product = product * (j / (x + 3 * j));
                        }
                        y = x + product;
                        cout << "x= " << x << " "
                             << "Result= " << y << endl;
                    }
                    continue;
                }
            }
            cout << "Enter the step: ";
            if (!(cin >> step) || step <= 0 || step > abs(b - a) || cin.peek() != '\n')
            {
                cout << "Incorrect step (Input integer step; positive  step or step that is less or equal to the range)" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else
            {
                cout << "Enter the value of 'n': ";
                if (!(cin >> n) || cin.peek() != '\n')
                {
                    cout << "Enter n as integer that is greater than 1" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else if (a < 0 && b < 0)
                {
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
                                    product = product * (i - (j /
                                                              2.0));
                                }
                                y += product;
                            }
                        }
                        cout << "x= " << x << " "
                             << "Result= " << y << endl;
                    }
                    continue;
                }

                else if (a < 0 && b >= 0)
                {
                    for (double x = a; x < 0; x += step)
                    {
                        double y = 0.0;
                        if (x < 0)
                        {
                            for (int i = 0; i <= n; ++i)
                            {
                                double product = 1.0;
                                for (int j = 0; j <= n + 1; ++j)
                                {
                                    product = product * (i - (j /
                                                              2.0));
                                }
                                y += product;
                            }
                        }
                        cout << "x= " << x << " "
                             << "Result= " << y << endl;
                    }
                    for (double x = 0; x <= b; x += step)
                    {
                        double product = 1.0;
                        for (int j = 1; j <= n; j++)
                        {
                            product = product * (j / (x + 3 * j));
                        }
                        y = x + product;
                        cout << "x= " << x << " "
                             << "Result= " << y << endl;
                    }
                    continue;
                }
                else
                {
                    for (double x = a; x <= b; x += step)
                    {
                        double product = 1.0;
                        for (int j = 1; j <= n; j++)
                        {
                            product = product * (j / (x + 3 * j));
                        }
                        y = x + product;
                        cout << "x= " << x << " "
                             << "Result= " << y << endl;
                    }
                    continue;
                }
            }
        }
        else if (choice == 0)
        {
            cout << "You exited" << endl;
            break;
        }
        else
        {
            cout << "Input '1' or '2' or '0' (other options are not supported)";
            continue;
        }
    }
    return 0;
}
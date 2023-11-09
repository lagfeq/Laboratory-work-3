#include <iostream>  //git hub
#include <cmath>
using namespace std;
int main()
{

    int n, choice;
    double a, b, step, x, y, result;
    cout << "'\nHello, user!'\n' If you want to calculate a single function - press '1' '\n' If you want to calculate function within a certain range - press '2' '\n' Your choice : ";
    cin >>
        choice;
    if (choice == 1 && cin.peek() == '\n')
    {
        cout << "Enter the value of n: ";
        if (cin >> n && cin.peek() == '\n' && n > 1)
        {
            cout << "Enter the value of x: ";
            if (cin >> x)
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
                        y = y + product;
                    }
                    cout << "x= " << x << " "
                         << "Result= " << y << endl;
                    return 0;
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
                    return 0;
                }
            }
            else
            {
                cout << "Incorect value of x (enter a number)" << endl;
            }
        }
        else
        {
            cout << "Incorrect value of n (enter an integer value that is  greater than 1)" << endl;
            return 0;
        }
    }
    else if (choice == 2 && cin.peek() == '\n')
    {
        cout << "Enter the range [a, b]: a= ";
        if (cin >> a && cin.peek() == '\n')
        {
            cout << "Enter the range [a, b]: b= ";
            if (cin >> b && cin.peek() == '\n')
            {
                if (a > b)
                {
                    cout << " Incorrect values of a and b (input b greater than a)";
                }
                else if (a == b)
                {
                    cout << "You have entered the same value for a and b. Enter the value of 'n' to calculate it as a single function: ";
                    if (cin >> n && n > 1 && cin.peek() == '\n')
                    {
                        if (a < 0 && b < 0)
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
                            return 0;
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
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        cout << "Enter n as integer that is greater than 1";
                    }
                }
                else
                {
                    cout << "Enter the step: ";
                    cin >> step;
                    if (step <= 0 || step >= abs(b - a))
                    {
                        cout << "Incorrect step (Input integer step; positive  step or step that is less or equal to the range)" << endl;
                        return 1;
                    }
                    else
                    {

                        cout << "Enter the value of 'n': ";
                        if (cin >> n && n > 1 && cin.peek() == '\n')
                        {

                            if (a < 0 && b < 0)
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
                                return 0;
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
                                return 0;
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
                                return 0;
                            }
                        }
                        else
                        {
                            cout << "Enter n as integer that is greater than 1";
                        }
                    }
                }
            }
            else
            {
                cout << "Enter b as number";
            }
        }
        else
        {
            cout << "Enter a as number";
        }
    }
    else
    {
        cout << "Input '1' or '2' (other options are not supported)";
        return 0;
    }
}
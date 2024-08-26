#include <iostream>

using namespace std;


int result_num, result_den;


void add_fractions(int, int, int, int);
void sub_fractions(int, int, int, int);
void multiply_fractions(int, int, int, int);
void divide_fractions(int, int, int, int);
void display_result();
void simplify_fraction();
int find_gcd(int, int);


int main()
{
    int f1_num, f1_den, f2_num, f2_den;
    char dummy;

    cout << "Enter first fraction (e.g., 2/3): ";
    cin >> f1_num >> dummy >> f1_den;
    if (f1_den == 0) {
        cout << "Error: Denominator of the first fraction cannot be zero." << endl;
        return 1;
    }

    cout << "Enter second fraction (e.g., 1/2): ";
    cin >> f2_num >> dummy >> f2_den;
    if (f2_den == 0) {
        cout << "Error: Denominator of the second fraction cannot be zero." << endl;
        return 1;
    }

    cout << "Adding fractions results in ";
    add_fractions(f1_num, f1_den, f2_num, f2_den);
    display_result();
    cout << endl;

    cout << "Subtracting fractions results in ";
    sub_fractions(f1_num, f1_den, f2_num, f2_den);
    display_result();
    cout << endl;

    cout << "Multiplying fractions results in ";
    multiply_fractions(f1_num, f1_den, f2_num, f2_den);
    display_result();
    cout << endl;

    cout << "Dividing fractions results in ";
    if (f2_num == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
    } else {
        divide_fractions(f1_num, f1_den, f2_num, f2_den);
        display_result();
    }
    cout << endl;

    return 0;
}


void add_fractions(int f1_num, int f1_den, int f2_num, int f2_den)
{
    result_den = f1_den * f2_den;
    result_num = f1_num * f2_den + f2_num * f1_den;
    simplify_fraction();
}


void sub_fractions(int f1_num, int f1_den, int f2_num, int f2_den)
{
    result_den = f1_den * f2_den;
    result_num = f1_num * f2_den - f2_num * f1_den;
    simplify_fraction();
}


void multiply_fractions(int f1_num, int f1_den, int f2_num, int f2_den)
{
    result_den = f1_den * f2_den;
    result_num = f1_num * f2_num;
    simplify_fraction();
}


void divide_fractions(int f1_num, int f1_den, int f2_num, int f2_den)
{
    result_num = f1_num * f2_den;
    result_den = f1_den * f2_num;
    simplify_fraction();
}


void simplify_fraction()
{
    if (result_den == 0) {
        cout << "Error: Division by zero." << endl;
        return;
    }

    int gcd = find_gcd(result_num, result_den);
    result_num /= gcd;
    result_den /= gcd;


    if (result_den < 0) {
        result_num = -result_num;
        result_den = -result_den;
    }
}


int find_gcd(int a, int b)
{

    return std::gcd(a, b);
}


void display_result()
{
    cout << result_num << "/" << result_den;
}

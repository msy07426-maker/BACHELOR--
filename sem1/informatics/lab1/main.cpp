#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std ;

int main()
 {
    // -------------------------------------------------------------
    // المسألة الأولى: حساب المعادلة الرياضية ومقارنة الدقة (float vs double)
    // -------------------------------------------------------------
    cout << "--- Task 1: Precision Test ---" << std::endl;

    // المعطيات الثابتة من السؤال للخيار 28
    double a_d = 1000.0;
    double b_d = 0.0001;

    float a_f = 1000.0f;
    float b_f = 0.0001f;

    // الحساب باستخدام نوع البيانات double 
    double num_d = pow(a_d - b_d, 5) - (pow(a_d, 5) - 5.0 *pow(a_d, 4) * b_d);
    double den_d = -10.0 *pow(a_d, 3) *pow(b_d, 2) + 10.0 *pow(a_d, 2) *pow(b_d, 3) - 5.0 * a_d *pow(b_d, 4) + pow(b_d, 5);
    double result_double = num_d / den_d;

    // الحساب باستخدام نوع البيانات float 
    float num_f = pow(a_f - b_f, 5) - (pow(a_f, 5) - 5.0f *pow(a_f, 4) * b_f);
    float den_f = -10.0f *pow(a_f, 3) *pow(b_f, 2) + 10.0f * pow(a_f, 2) * pow(b_f, 3) - 5.0f * a_f * pow(b_f, 4) + pow(b_f, 5);
    float result_float = num_f / den_f;

    // طباعة النتائج بدقة 6 أرقام بعد الفاصلة
    cout << fixed << setprecision(6);
    cout << "Result (double): " << result_double << endl;
    cout << "Result (float) : " << result_float  << endl;
    cout <<  endl;

    // -------------------------------------------------------------
    // المسألة الثانية: شرح رموز الزيادة والنقصان
    // -------------------------------------------------------------
    std::cout << "--- Task 2: Increment/Decrement Operators ---" << std::endl;
    
    // قيم أولية افتراضية لتوضيح العمليات البرمجية 
    int n = 5;
    int m = 5;

    // 1) n++ * ++m
    int expr1 = n++ * ++m;
    cout << "1) n++ * ++m = " << expr1 << "  -> (Current state in memory: n=" << n << ", m=" << m << ")"    << endl;

    // 2) --m < n--
    bool expr2 = --m < n--;
    cout << "2) --m < n-- = " << std::boolalpha << expr2 << "  -> (Current state in memory: n=" << n << ", m=" << m << ")" << endl;

    // 3) m++ > n++
    bool expr3 = m++ > n++;
    cout << "3) m++ > n++ = " << std::boolalpha << expr3 << "  -> (Current state in memory: n=" << n << ", m=" << m << ")" << endl;

    return 0;
}


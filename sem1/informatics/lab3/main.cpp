#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// دالة مساعدة لحساب المضروب (Factorial)
double factorial(int num)
{
    double fact = 1.0;
    for (int i = 1; i <= num; i++) 
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    cout << "=== Lab 3: Function Taylor Series Approximation (Variant 28) ===" << endl;
    cout << "X\t\tSN (n=12)\tSE (eps=0.0001)\tY (Exact)" << endl;
    cout << "------------------------------------------------------------------" << endl;

    double a = 0.1;
    double b = 1.0;
    int k = 10;
    double step = (b - a) / k; // حساب خطوة الحركة لـ X
    double epsilon = 0.0001;

    // الحلقة الخارجية لتغيير قيمة X من a إلى b
    for (double x = a; x <= b + 1e-9; x += step)
        {
        
            // ---- أولاً: الحساب من أجل n = 12 ثابت ----
             double sn = 1.0;
             for (int n = 1; n <= 12; n++)
                 {
                    double term = pow(-1, n) * pow(x, 2 * n) / factorial(2 * n + 1);
                    sn += term;
                  }

            // ---- ثانياً: الحساب من أجل دقة محددة eps ----
            double se = 1.0;
            int n_e = 1;
            while (true) 
            {
            double term = pow(-1, n_e) * pow(x, 2 * n_e) / factorial(2 * n_e + 1);
            se += term;
            if (abs(term) < epsilon)
               {
                 break;
               }
             n_e++;
            }

        // ---- ثالثاً: حساب القيمة الحقيقية والدقيقة للدالة ----
        double y = sin(x) / x;

        // طباعة السطر بالصيغة المطلوبة في الكتيب الجامعي بدقة
        cout << fixed << setprecision(2) << x << "\t\t"
             << setprecision(6) << sn << "\t" << se << "\t" << y << endl;
    }

    cout << "------------------------------------------------------------------" << endl;
    return 0;
}


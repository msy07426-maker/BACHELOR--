#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() 
{
    cout << "=== Lab 2: Sum of Infinite Series (Variant 28) ===" << endl;

    double sum = 0.0;       // متغير لحفظ المجموع الكلي
    double epsilon = 1e-4;  // الدقة المطلوبة (0.0001)
    double an = 0.0;        // متغير لحفظ قيمة الحد الحالي
    int n = 1;              // عداد الحلقة يبدأ من 1

    cout << n << "\t" << "an" << "\t\t" << "Current Sum" << endl;
    cout << "---------------------------------------------" << endl;

    // الحلقة التكرارية لحساب السلسلة
    while (true) {
        // حساب الحد العام حسب صيغة الخيار 28
        an = (2.0 * n + 1.0) / pow(3.0, n);

        // إضافة الحد الحالي للمجموع الكلي
        sum += an;

        // طباعة خطوات الحل بالتفصيل للأستاذ
        cout << n << "\t" << fixed << setprecision(6) << an << "\t" << sum << endl;

        // شرط التوقف: إذا أصبح الحد الحالي أصغر من الدقة المطلوبة
        if (an < epsilon) {
            break;
        }

        n++; // الانتقال للحد التالي
    }

    cout << "---------------------------------------------" << endl;
    cout << "Final Sum of the series: " << fixed << setprecision(4) << sum << endl;
    cout << "Total iterations (n): " << n << endl;

    return 0;
}


#include <iostream>
#include <io.h>
#include <fcntl.h>

double f(double x) {
    return 
}

// Метод левых прямоугольников
double leftRect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += f(a + i * h);
    }
    return h * sum;
}

// Метод правых прямоугольников
double rightRect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += f(a + i * h);
    }
    return h * sum;
}

// Метод средних прямоугольников
double midRect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += f(a + (i + 0.5) * h);
    }
    return h * sum;
}

// Метод трапеций
double trapezoid(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }
    return h * sum;
}

double myAbs(double x) {
    if (x >= 0) {
        return x;
    }
    else {
        return -x;
    }
}

int main() {

    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);


    double a, b;
    int n;

    std::wcout << " a: ";
    std::wcin >> a;
    std::wcout << " b: ";
    std::wcin >> b;
    std::wcout << " n: ";
    std::wcin >> n;

    // Расчёт с шагом h
    double L1 = leftRect(a, b, n);
    double R1 = rightRect(a, b, n);
    double M1 = midRect(a, b, n);
    double T1 = trapezoid(a, b, n);

    // Расчёт с удвоенным числом разбиений (шаг h/2)
    int n2 = 2 * n;
    double L2 = leftRect(a, b, n2);
    double R2 = rightRect(a, b, n2);
    double M2 = midRect(a, b, n2);
    double T2 = trapezoid(a, b, n2);

   

    std::wcout << "\n n = " << n << "\n";
    std::wcout << L"левые прямоугольники:   " << L1 << "\n";
    std::wcout << L"правые прямоугольники:  " << R1 << "\n";
    std::wcout << L"средние прямоугольники: " << M1 << "\n";
    std::wcout << L"трапеции:               " << T1 << "\n";

    std::wcout << L"\n  погрешность (правило Рунге) \n";
    std::wcout << L"Левые прямоугольники:   " << myAbs(L1 - L2) / 3.0 << "\n";
    std::wcout << L"Правые прямоугольники:  " << myAbs(R1 - R2) / 3.0 << "\n";
    std::wcout << L"Средние прямоугольники: " << myAbs(M1 - M2) / 3.0 << "\n";
    std::wcout << L"Трапеции:               " << myAbs(T1 - T2) / 3.0 << "\n";

    std::wcout << L"\n Уточнённые значения (Рунге) \n";
    std::wcout << L"Средние прямоугольники: " << M2 + (M2 - M1) / 3.0 << "\n";
    std::wcout << L"Трапеции:               " << T2 + (T2 - T1) / 3.0 << "\n";

    return 0;
}

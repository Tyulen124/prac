#include <iostream>

// Подынтегральная функция — замените на свою
double f(double x) {
    return x * x; // пример: интеграл от x^2
}

// Метод левых прямоугольников
double leftRect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += f(a + i * h);
    return h * sum;
}

// Метод правых прямоугольников
double rightRect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 1; i <= n; i++)
        sum += f(a + i * h);
    return h * sum;
}

// Метод средних прямоугольников
double midRect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += f(a + (i + 0.5) * h);
    return h * sum;
}

// Метод трапеций
double trapezoid(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;      // крайние точки с весом 1/2
    for (int i = 1; i < n; i++)
        sum += f(a + i * h);               // внутренние точки с весом 1
    return h * sum;
}

int main() {
    double a, b;
    int n;

    std::cout << "Введите нижний предел интегрирования a: ";
    std::cin >> a;
    std::cout << "Введите верхний предел интегрирования b: ";
    std::cin >> b;
    std::cout << "Введите число разбиений n: ";
    std::cin >> n;

    // --- Расчёт с шагом h ---
    double L1 = leftRect(a, b, n);
    double R1 = rightRect(a, b, n);
    double M1 = midRect(a, b, n);
    double T1 = trapezoid(a, b, n);

    // --- Расчёт с удвоенным числом разбиений (шаг h/2) ---
    int n2 = 2 * n;
    double L2 = leftRect(a, b, n2);
    double R2 = rightRect(a, b, n2);
    double M2 = midRect(a, b, n2);
    double T2 = trapezoid(a, b, n2);

    std::cout.precision(10);
    std::cout << std::fixed;

    std::cout << "\n--- Результаты при n = " << n << " ---" << std::endl;
    std::cout << "Левые прямоугольники:   " << L1 << std::endl;
    std::cout << "Правые прямоугольники:  " << R1 << std::endl;
    std::cout << "Средние прямоугольники: " << M1 << std::endl;
    std::cout << "Трапеции:               " << T1 << std::endl;

    // --- Оценка погрешности по правилу Рунге: |I_h - I_h/2| / 3 ---
    std::cout << "\n--- Оценка погрешности (правило Рунге) ---" << std::endl;
    std::cout << "Левые прямоугольники:   " << (L1 > L2 ? L1 - L2 : L2 - L1) / 3.0 << std::endl;
    std::cout << "Правые прямоугольники:  " << (R1 > R2 ? R1 - R2 : R2 - R1) / 3.0 << std::endl;
    std::cout << "Средние прямоугольники: " << (M1 > M2 ? M1 - M2 : M2 - M1) / 3.0 << std::endl;
    std::cout << "Трапеции:               " << (T1 > T2 ? T1 - T2 : T2 - T1) / 3.0 << std::endl;

    // --- Уточнённое значение по Рунге: I_уточн = I_h/2 + (I_h/2 - I_h)/3 ---
    std::cout << "\n--- Уточнённые значения (Рунге) ---" << std::endl;
    std::cout << "Средние прямоугольники: " << M2 + (M2 - M1) / 3.0 << std::endl;
    std::cout << "Трапеции:               " << T2 + (T2 - T1) / 3.0 << std::endl;

    return 0;
}
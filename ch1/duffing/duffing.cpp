#include <iostream>
#include <fstream>
#include <cmath>
#include <functional>

// Duffing振動子の右辺
double duffing_f(double x, double v, double t) {
    double gamma = 0.1;
    double f0 = 2.0;
    double omega = 2.4;
    return - gamma * v + x - std::pow(x, 3) + f0 * std::cos(omega * t);
}

// 調和振動子
double harmonic_f(double x, double v, double t) {
    double k = 1.0; // バネ定数
    return -k * x; // フックの法則に基づく力
}

// ルンゲクッタ法による更新
void runge_kutta(double &x, double &v, double t, double h, std::function<double(double, double, double)> f) {
    double k1x = h * v;
    double k1v = h * f(x, v, t);

    double k2x = h * (v + 0.5 * k1v);
    double k2v = h * f(x + 0.5 * k1x, v + 0.5 * k1v, t + 0.5 * h);

    double k3x = h * (v + 0.5 * k2v);
    double k3v = h * f(x + 0.5 * k2x, v + 0.5 * k2v, t + 0.5 * h);

    double k4x = h * (v + k3v);
    double k4v = h * f(x + k3x, v + k3v, t + h);

    x += (k1x + 2 * k2x + 2 * k3x + k4x) / 6;
    v += (k1v + 2 * k2v + 2 * k3v + k4v) / 6;
}

int main() {
    // 初期条件
    double t0 = 0.0;
    double x = 0.5; // y(0)
    double v = 0; // y'(0)
    double h = 0.005; // ステップサイズ
    int steps = 100000000; // ステップ数

    double attractor_width = (2.0*3.141592) / (2.4*h);

    std::function<double(double, double, double)> f = duffing_f;

    // 出力ファイル
    std::ofstream outfile("duffing.dat");
    std::ofstream attractor_outfile("duffing_attractor.dat");

    for (int step = 0; step < steps; ++step) {
        double t = t0 + step * h;
        bool attractor = (std::fmod(t, attractor_width) < h);
        outfile << t << " " << x << " " << v << std::endl; // データ出力
        if(attractor) attractor_outfile << t << " " << x << " " << v << std::endl;
        runge_kutta(x, v, t, h, f);
    }

    // outfile.close();
    attractor_outfile.close();
    return 0;
}
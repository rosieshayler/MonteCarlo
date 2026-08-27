#include <iostream>
#include <cmath>
#include <random>
#include <string>

int main(int argc, char* argv[])
{
    double S_0 = std::stod(argv[1]);
    double K = std::stod(argv[2]);
    double T = std::stod(argv[3]);
    double r = std::stod(argv[4]);
    double sigma = std::stod(argv[5]);
    
    int simulation_count = 100000;
    double payoff_sum = 0.0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> norm(0.0, 1.0);

    for (int i = 0; i <simulation_count; i++){
        double Z = norm(gen);
        double S_T = S_0*std::exp((r-0.5*sigma*sigma)*T + sigma*std::sqrt(T)*Z);
        double payoff = std::max(S_T - K, 0.0);
        payoff_sum += payoff;
    }

    double average_payoff = payoff_sum/simulation_count;
    double option_price = average_payoff * std::exp(-r * T);

    std::cout << "Simulated Call Option Price: " << option_price << std::endl;

    return 0;
}


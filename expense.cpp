#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Expense {
public:
    std::string date;
    std::string category;
    double amount;

    Expense(std::string d, std::string c, double a) : date(d), category(c), amount(a) {}
};

class ExpenseTracker {
    std::vector<Expense> expenses;

public:
    void addExpense(const Expense& exp) {
        expenses.push_back(exp);
    }

    void displayExpenses() const {
        for (const auto& exp : expenses) {
            std::cout << "Date: " << exp.date << ", Category: " << exp.category << ", Amount: " << exp.amount << std::endl;
        }
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        for (const auto& exp : expenses) {
            file << exp.date << "," << exp.category << "," << exp.amount << std::endl;
        }
    }
};

int main() {
    ExpenseTracker tracker;
    tracker.addExpense(Expense("2024-05-21", "Food", 12.5));
    tracker.addExpense(Expense("2024-05-22", "Transport", 15.0));
    tracker.displayExpenses();
    tracker.saveToFile("expenses.csv");

    return 0;
}

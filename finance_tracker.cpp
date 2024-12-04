#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

enum TransactionType
{
    INCOME,
    EXPENSE
};

class Transaction
{
public:
    double amount;
    string description;
    string date;
    TransactionType type;

    Transaction(double amt, string desc, string d, TransactionType t)
        : amount(amt), description(desc), date(d), type(t) {}

    bool operator<(const Transaction &other) const
    {
        return this->amount < other.amount;
    }
};

class FinanceTracker
{
private:
    list<Transaction *> transactions;
    priority_queue<Transaction *> incomeQueue;
    priority_queue<Transaction *> expenseQueue;
    double totalIncome = 0, totalExpenses = 0;

    string getCurrentDate()
    {
        time_t now = time(0);
        tm *localtm = localtime(&now);
        char buffer[11];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtm);
        return string(buffer);
    }

public:
    void addTransaction(double amount, string description, string date, TransactionType type)
    {
        if (date.empty())
        {
            date = getCurrentDate();
        }
        Transaction *newTransaction = new Transaction(amount, description, date, type);
        transactions.push_back(newTransaction);

        if (type == INCOME)
        {
            incomeQueue.push(newTransaction);
            totalIncome += amount;
        }
        else
        {
            expenseQueue.push(newTransaction);
            totalExpenses += amount;
        }

        if (totalExpenses > totalIncome)
        {
            cout << "\n⚠️  Warning: Expenses exceed income! You are out of budget.\n";
        }
    }

    void showPriorityTransaction(TransactionType type)
    {
        if (type == INCOME && !incomeQueue.empty())
        {
            Transaction *t = incomeQueue.top();
            cout << "Highest Income: " << t->description << ", Amount: " << t->amount << "\n";
        }
        else if (type == EXPENSE && !expenseQueue.empty())
        {
            Transaction *t = expenseQueue.top();
            cout << "Highest Expense: " << t->description << ", Amount: " << t->amount << "\n";
        }
        else
        {
            cout << "No transactions of this type.\n";
        }
    }

    void generateReport()
    {
        // Generate the report content
        string reportContent = "--- 📝 Financial Report 📝 ---\n";
        reportContent += "Total Income 🤑: " + to_string(totalIncome) + "\n";
        reportContent += "Total Expenses 💸: " + to_string(totalExpenses) + "\n";
        reportContent += "Balance 💰: " + to_string(totalIncome - totalExpenses) + "\n";

        // Display the report to the user
        cout << "\n"
             << reportContent;

        // Ask if the user wants to save the report
        char saveChoice;
        cout << "\nDo you want to save this report to a file? (y/n): ";
        cin >> saveChoice;

        if (tolower(saveChoice) == 'y')
        {
            // Save the report to a text file
            ofstream reportFile("report.txt");
            reportFile << reportContent;
            reportFile.close();
            cout << "\n✅ Report has been saved to 'report.txt' in the current directory.\n";
        }
        else
        {
            cout << "\n❌ Report was not saved.\n";
        }
    }

    void viewTransactions()
    {
        cout << "\n============================== Transaction History ==============================\n";
        cout << "|   Type   |       Description        |    Amount    |       Date       |\n";
        cout << "-------------------------------------------------------------------------------\n";

        for (auto &transaction : transactions)
        {
            string type = (transaction->type == INCOME) ? "Income " : "Expense";
            cout << "| " << setw(8) << left << type
                 << "| " << setw(23) << left << transaction->description
                 << "| " << setw(12) << left << transaction->amount
                 << "| " << setw(16) << left << transaction->date
                 << "|\n";
        }

        cout << "-------------------------------------------------------------------------------\n";
    }
};
void displayBanner()
{
    cout << "\n=============================\n";
    cout << "   💰🤑 Personal Finance Tracker 🤑💰\n";
    cout << "=============================\n";
}

int main()
{
    FinanceTracker tracker;
    int choice;
    double amount;
    string description, date;
    int transactionType;

    while (true)
    {
        displayBanner();
        cout << "=============================\n";
        cout << "   💰 Personal Finance Tracker 💰\n";
        cout << "=============================\n";
        cout << "1. ➕ Add Income 💵\n";
        cout << "2. ➖ Add Expense 💸\n";
        cout << "3. 📈 Show Highest Income 🤑\n";
        cout << "4. 📉 Show Highest Expense 🛒\n";
        cout << "5. 📝 Generate Financial Report 📊\n";
        cout << "6. 📋 View Transaction History 📅\n";
        cout << "7. 🚪 Exit 🔚\n";
        cout << "=============================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter income amount: ";
            cin >> amount;
            cin.ignore();
            cout << "Enter description: ";
            getline(cin, description);
            cout << "Enter date (YYYY-MM-DD) or leave blank for today: ";
            getline(cin, date);
            tracker.addTransaction(amount, description, date, INCOME);
            break;
        case 2:
            cout << "Enter expense amount: ";
            cin >> amount;
            cin.ignore();
            cout << "Enter description: ";
            getline(cin, description);
            cout << "Enter date (YYYY-MM-DD) or leave blank for today: ";
            getline(cin, date);
            tracker.addTransaction(amount, description, date, EXPENSE);
            break;
        case 3:
            tracker.showPriorityTransaction(INCOME);
            break;
        case 4:
            tracker.showPriorityTransaction(EXPENSE);
            break;
        case 5:
            tracker.generateReport();
            break;
        case 6:
            tracker.viewTransactions();
            break;
        case 7:
            cout << "Exiting... Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

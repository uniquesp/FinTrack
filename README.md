# FinTrack 💰 : Personal Finance Tracker


## 📖 **Overview**
The **FinTrack** is a console-based application designed to help users efficiently manage their personal finances. The program enables users to record incomes and expenses, analyze their financial habits, and generate reports for better budgeting. 🚀

---

## ✨ **Features**
- **💵 Add Income**: Record your income with a description and date.
- **💸 Add Expense**: Track your spending, including categories and amounts.
- **📈 Show Highest Income**: Identify the largest single income source.
- **📉 Show Highest Expense**: Discover where you're spending the most.
- **📝 Generate Financial Report**:  
  - View a detailed summary of total income, expenses, and balance.  
  - Save the report as a text file.  
- **📋 Transaction History**:  
  - View all transactions in a **table format** with clear details.  
- **⚠️ Budget Warning**: Notifies users if expenses exceed income.  
- **📅 Automatic Date Handling**: Automatically assigns the current date if not provided.  

---

## 🛠 **Tech Stack**
![C++ Badge](https://img.shields.io/badge/Language-C%2B%2B-blue)
![DSA Badge](https://img.shields.io/badge/Data%20Structures-Priority%20Queues-orange)
![Tools Badge](https://img.shields.io/badge/Tools-GCC%20%7C%20g%2B%2B-yellowgreen)

- **Language**: C++  
- **Core Concepts**: Object-Oriented Programming (OOP), Priority Queues, STL (Standard Template Library)  
- **Tools**:  
  - Compiler: GCC/g++  
  - File Handling for Reports  

---

## 💻 **How to Run**
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/Personal-Finance-Tracker.git
   cd Personal-Finance-Tracker
   ```

2. **Compile the Code**:
   ```bash
   g++ -o FinanceTracker finance_tracker.cpp
   ```

3. **Run the Application**:
   ```bash
   ./FinanceTracker
   ```

---

## 📊 **Sample Output**
### Main Menu
```
=============================
   💰 Personal Finance Tracker 💰
=============================
1. ➕ Add Income 💵
2. ➖ Add Expense 💸
3. 📈 Show Highest Income 
4. 📉 Show Highest Expense 
5. 📝 Generate Financial Report 
6. 📋 View Transaction History 
7. 🚪 Exit 
=============================
Enter your choice: 
```

### Transaction History (Table Format)
```
============================== Transaction History ==============================
|   Type   |       Description        |    Amount    |       Date       |
-------------------------------------------------------------------------------
| Income   | Salary                   | 2000         | 2024-12-04       |
| Expense  | Groceries                | 300          | 2024-12-05       |
| Expense  | Rent                     | 1200         | 2024-12-03       |
-------------------------------------------------------------------------------
```

---

## 🔖 **Project Structure**
```
├── finance_tracker.cpp   # Main source file
├── report.txt            # Generated financial report
└── README.md             # Project documentation
```

---

## 🚀 **Features to Explore**
1. **Auto Date Assignment**: If no date is entered, the system automatically assigns the current date.  
2. **Warnings**: Get notified if your spending surpasses your income.  
3. **Report Saving**: Save your transactions and financial analysis in a text file.  

---

## 📂 **Generated Report Example**
**File: `report.txt`**  
```
--- Financial Report ---
Total Income: 2000
Total Expenses: 2500
Balance: -500

--- Transaction History ---
Income: Salary, Amount: 2000, Date: 2024-12-04
Expense: Groceries, Amount: 300, Date: 2024-12-05
Expense: Rent, Amount: 1200, Date: 2024-12-03
```

---



## 🤝 **Contributing**
Contributions are welcome! Feel free to submit a pull request or open an issue to suggest improvements.

---

Let me know if you'd like further personalization for your GitHub page!

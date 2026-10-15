# Bank Management System

A console banking application built with object-oriented C++. The system is organized around roughly 40 classes covering screens, domain entities, and utilities — modeled the way a real branch banking product separates UI flows from business logic.

## Features

**Client management**
- List, add, update, delete, and find clients
- Account balance inquiries and total-balances report

**Transactions**
- Deposit and withdraw with validation
- Transfer between accounts with a persistent transfer log
- Transaction history per user session

**User management & permissions**
- Bank staff accounts with username/password login
- Role-based permissions using a bitmask (`PerShowClientList`, `PerAddClient`, `PerTransactions`, `PerManageUsers`, `PerCurrencyExchance`, …) — each screen checks permissions before rendering
- Full audit of login/register activity in a register log

**Currency exchange**
- Currency catalogue with live rate storage
- Currency converter/calculator and rate-update screen

**Cross-cutting utilities**
- `clsDate` — full date arithmetic
- `clsString` — string manipulation helpers
- `clsValid` / `clsUtil` — input validation, PIN and record-number generation

## Architecture

Every screen derives from `clsScreen`, which standardizes headers and navigation. Domain entities (`clsClient`, `clsUser`, `clsCurrency`) encapsulate their own file I/O, so persistence is handled at the model layer, not in the UI code.

```
Screens (clsScreen base)          Domain (file-backed)       Utilities
├── clsLoginScreen                ├── clsClient              ├── clsDate
├── clsMainMenu                   ├── clsUser (permissions)  ├── clsString
├── clsTransactionsMenuScreen     └── clsCurrency            ├── clsUtil
├── clsManageUsersScreen                                   └── clsValid
└── clsCurrencyExchanceScreen
```

## Tech stack

- C++ (OOP: inheritance, encapsulation, enums, bitwise permissions)
- File-based persistence (`Clients.txt`, `Users.txt`, `Currencies.txt`, `TransferLog.txt`, `RegisterLog.txt`)
- Visual Studio solution (`BankV2.sln`)

## How to run

1. Open `BankV2.sln` in Visual Studio (2019 or newer).
2. Build and run (`Ctrl+F5`).
3. Sign in with an account from `Users.txt`.

The smaller ATM front-end for this system is in [project---Bank-sub-system-Atm](https://github.com/ahmadalsalh4/project---Bank-sub-system-Atm).

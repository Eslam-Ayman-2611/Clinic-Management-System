# Clinic Management System

A console-based Clinic Management System developed in C as a final project after completing a season in the **Embedded Systems Committee at IEEE Al-Azhar**.

The project applies fundamental C programming concepts to simulate clinic operations, including patient registration, appointment scheduling, patient record management, and financial tracking.

## Project Overview

The system provides two operating modes:

- **Admin Mode:** Allows authorized administrators to manage patients, appointments, and clinic operations.
- **User Mode:** Allows users to view patient information and check the clinic's weekly appointment schedules.

## Features

### Admin Mode

- Admin authentication.
- Register new patients.
- Register existing patients for appointments.
- Handle emergency patient registration.
- Reserve available appointment slots.
- Edit patient records.
- Cancel reservations.
- View clinic treasury funds.
- Switch to User Mode or log out.

### User Mode

- Search and view patient records using Patient ID.
- View daily reservations.
- View the complete weekly appointment schedule.
- Check available and reserved appointment slots.
- View the weekly emergency schedule.

## Technologies Used

- **Programming Language:** C
- **Development Environment:** Linux / macOS Terminal
- **Libraries:** Standard C libraries and POSIX system functions.

## Project Structure

| File       | Description                                                            |
| ---------- | ---------------------------------------------------------------------- |
| `main.c`   | Application entry point and main program loop.                         |
| `User.c`   | Implements user mode and patient information viewing.                  |
| `Admin.c`  | Implements admin operations and clinic management functionality.       |
| `Header.h` | Contains structures, macros, global variables, and required libraries. |

## Getting Started

### Prerequisites

- GCC compiler or a compatible C compiler.
- Linux or macOS terminal.

### Compilation

Clone the repository:

```bash
git clone https://github.com/Eslam-Ayman-2611/Clinic-Management-System.git
```

Navigate to the project directory:

```bash
cd Clinic-Management-System
```

Compile the project:

```bash
gcc main.c -o clinic
```

### Run the Application

```bash
./clinic
```

## Implementation Notes

- Patient records and appointment schedules are maintained using C structures and arrays.
- The application uses in-memory storage; data is not persisted after the program terminates.
- The project focuses on applying C programming fundamentals through a practical management-system scenario.

## Learning Outcomes

This project provided practical experience with:

- C programming fundamentals.
- Structures and arrays.
- Functions and modular code organization.
- Conditional statements and loops.
- Input validation and data handling.
- Building menu-driven console applications.
- Applying programming concepts to a real-world-inspired problem.

## Project Background

Developed as a final project following a training season with the **Embedded Systems Committee at IEEE Al-Azhar**, demonstrating the practical application of programming concepts acquired during the training.

# Minishell1

A lightweight shell implementation in C, created as part of a system programming project. This project aims to replicate basic shell functionality while learning about process management, system calls, and shell programming.

## 🛠️ Prerequisites

- GCC compiler
- Make

## 🚀 Quick Start

1. Clone the repository:
```bash
git clone https://github.com/LucasMarsala/minishell1.git
cd minishell1
```

2. Compile the project:
```bash
make
```

3. Run the shell:
```bash
./minishell1
```

## 📁 Project Structure

```
.
├── include/        # Header files
├── src/           # Source files
├── main.c         # Main program entry point
└── Makefile       # Build configuration
```

## 🛠️ Technologies Used

- C (86.3%)
- Makefile (13.7%)

## 🔧 Features

- Basic shell command execution
- Process management
- Environment variable handling
- Built-in commands
- Command parsing
- Error handling

## 📝 Implementation Details

The shell implements several key features:
- Command execution using `execve`
- Process creation and management
- Environment variable expansion
- Basic command parsing
- Error handling and reporting

## 🐛 Debugging

The project includes error handling and debugging capabilities:
- Detailed error messages
- Process status reporting
- Command execution feedback

## 📚 Learning Objectives

This project helps understand:
- Process management in Unix systems
- System calls and their usage
- Shell programming concepts
- C programming best practices
- Make build systems

---
⭐ Don't forget to star this repository if you found it useful!

# codelldb-debug-project

This project is a simple C++ application that utilizes CodeLLDB for debugging. Below are the instructions on how to build and run the application.

## Project Structure

```
codelldb-debug-project
├── src
│   └── main.cpp
├── .vscode
│   └── launch.json
├── CMakeLists.txt
└── README.md
```

## Requirements

- CMake
- A C++ compiler (e.g., g++, clang++)
- CodeLLDB extension for debugging in your IDE

## Building the Project

1. Open a terminal and navigate to the project directory:
   ```
   cd codelldb-debug-project
   ```

2. Create a build directory:
   ```
   mkdir build
   cd build
   ```

3. Run CMake to configure the project:
   ```
   cmake ..
   ```

4. Build the project:
   ```
   make
   ```

## Running the Application

After building the project, you can run the application using the following command in the terminal:

```
./your_executable_name
```

Replace `your_executable_name` with the actual name of the compiled executable.

## Debugging with CodeLLDB

To debug the application using CodeLLDB:

1. Open the project in your IDE.
2. Ensure that the CodeLLDB extension is installed.
3. Open the debug configuration file located at `.vscode/launch.json`.
4. Set breakpoints in your source code as needed.
5. Start the debugging session from your IDE.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.
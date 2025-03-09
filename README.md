# Paint For Kids

Paint For Kids is an interactive C++ drawing application designed specifically for children. Built using the CMUgraphics library and developed in Visual Studio, this project provides an engaging platform for kids to explore their creativity while learning fundamental computer interactions.

## Features
The application offers a rich set of functionalities, including:
- **Drawing Tools**: Draw rectangles, squares, circles, triangles, and hexagons.
- **Color Management**: Choose from multiple colors for both drawing and filling.
- **Editing Capabilities**: Select, move, resize, drag, and delete shapes.
- **Undo/Redo**: Supports multiple undo and redo operations.
- **Playback & Recording**: Record and replay drawing actions.
- **File Management**: Save and load drawings.
- **Game Mode**: Engage in shape and color-based interactive games.

## Technology Stack
- **Programming Language**: C++
- **Integrated Development Environment (IDE)**: Visual Studio
- **Graphics Library**: CMUgraphics
- **Concepts Utilized**: Object-Oriented Programming (OOP), Event Handling, File I/O

## Prerequisites
To build and run Paint For Kids, ensure you have the following:
- **Windows OS**
- **Visual Studio (2019 or later)** with C++ Desktop Development workload installed
- **CMUgraphics Library**
- **Git (optional for version control and repository cloning)**

## Installation & Setup
### 1. Clone the Repository
```sh
git clone https://github.com/<your-username>/Paint-For-Kids.git
cd Paint-For-Kids
```

### 2. Open the Project in Visual Studio
- Locate `PaintForKids.sln` in the root directory.
- Open it in Visual Studio by double-clicking or using `File > Open > Project/Solution`.

### 3. Build and Run the Application
- Select `Debug` or `Release` mode.
- Set `PaintForKids` as the startup project.
- Press `F5` to run or `Ctrl+F5` to run without debugging.

## Project Structure
- `PaintForKids.sln` - Visual Studio solution file
- `main.cpp` - Application entry point
- `ApplicationManager.h/.cpp` - Core logic handling application operations
- `DEFS.h` - Contains action definitions and constants
- `UI` - Handles user interface elements
- `Shapes` - Defines different drawable shapes

## Action Types
The application supports various user actions as defined in `DEFS.h`:
```cpp
enum ActionType {
    DRAW_RECT, DRAW_SQUARE, DRAW_CIRCLE, DRAW_TRIANGLE, DRAW_HEXAGON,
    SELECT, MOVE, RESIZE, DRAG, DELETE, CLEAR, UNDO, REDO,
    RECORD_START, RECORD_STOP, RECORD_PLAY,
    SAVE, LOAD,
    PLAY_SHAPE, PLAY_COLOR, PLAY_BOTH,
    TO_DRAW_MODE, TO_PLAY_MODE, TO_COLOR_MODE,
    EXIT
};
```

## Troubleshooting
### Common Issues & Fixes
- **Compilation Errors**: Ensure CMUgraphics is correctly linked.
- **Linker Errors**: Verify that all `.cpp` files are included in the project.
- **Graphics Not Displaying**: Check if CMUgraphics dependencies are correctly set up.

For any inquiries or issues, feel free to open an issue on GitHub or reach out to me at [karimzakzouk@outlook.com].




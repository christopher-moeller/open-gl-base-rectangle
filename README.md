# OpenGLApp

## Description
OpenGLApp is a simple OpenGL application using GLFW for window and input management and GLEW for OpenGL extension handling. It should work as a template for graphics applications. This project is set up using `premake5` to automate the creation of Xcode project files for macOS.

## Features
- GLFW integration for cross-platform window creation.
- GLEW for OpenGL extension management.
- Fully configured with a `premake5.lua` script to generate build files for Xcode.

---

## Prerequisites

### Tools
1. **Premake5**: Ensure you have `premake5` installed. You can download it from the [Premake website](https://premake.github.io/).
2. **Xcode**: Install Xcode from the Mac App Store.
3. **GLFW and GLEW**: The project expects GLFW and GLEW to be included as subdirectories in the `vendor` folder.

### File Structure
Ensure the following file structure:
```
OpenGLApp/
├── premake5.lua
├── src/
│   ├── main.cpp
├── vendor/
│   ├── GLFW/
│   │   ├── include/
│   │   ├── lib/
│   │       └── libglfw3.a
│   ├── GLEW/
│   │   ├── include/
│   │   ├── lib/
│   │       └── libGLEW.a
```

---

## Setup Instructions

### Step 1: Clone the Repository
Clone this repository to your local machine:
```bash
git clone <repository-url>
cd OpenGLApp
```

### Step 2: Install Dependencies
Place the precompiled GLFW and GLEW libraries in the `vendor` folder as per the structure above. Ensure that:
- The `include` directories contain the respective headers (`GLFW/glfw3.h`, `GL/glew.h`).
- The `lib` directories contain the precompiled static libraries (`libglfw3.a`, `libGLEW.a`).

### Step 3: Generate Xcode Project
Run `premake5` to generate the Xcode project files:
```bash
premake5 xcode4
```
This will create an Xcode project in the root folder.

### Step 4: Open Xcode and Build
1. Open the generated `.xcodeproj` file in Xcode.
2. Select the desired scheme (Debug or Release).
3. Click the "Run" button (or press `Cmd + R`) to build and run the application.

---

## premake5.lua
The `premake5.lua` script automates the setup of the Xcode project. It:
- Specifies project configurations (`Debug` and `Release`).
- Sets up include directories and library paths for GLFW and GLEW.
- Links the required libraries (`libglfw3.a`, `libGLEW.a`) and macOS frameworks (`OpenGL.framework`).

---

## main.cpp
The `main.cpp` file contains a simple OpenGL application that:
- Creates a GLFW window.
- Initializes GLEW.
- Renders a blank window and listens for input events.

---

## Known Issues
1. **Multiple Windows**: Ensure Xcode is not relaunching old processes. Disable "Debug: Attach to Process on Launch" in the Xcode scheme.
2. **Library Not Found**: Ensure `libglfw3.a` and `libGLEW.a` are correctly placed in the `vendor` directory.
3. **MetalTools Warning**: This warning can be safely ignored if the application functions correctly.


# Setting the Working Directory in Xcode (Manual Method)

If you encounter issues with file paths when running your application in Xcode, you can manually set the working directory in your Xcode scheme. Follow these steps:

## Steps to Set the Working Directory

1. Open your project in **Xcode**.
2. Go to the menu bar and select **Product > Scheme > Edit Scheme**.
3. In the left-hand sidebar of the scheme editor, select the **Run** option.
4. Click on the **Options** tab at the top of the window.
5. Check the box labeled **Use custom working directory**.
6. Set the custom working directory to the root of your project (where your `premake5.lua` file is located). 
   - You can do this by clicking the folder icon and navigating to the project root.
7. Click **Close** to save the changes.

## Notes
- You will need to repeat this step if you regenerate the Xcode project with `premake5 xcode4`.
- If you want to automate this process, consider using a custom script to modify the `.xcscheme` file after project generation.

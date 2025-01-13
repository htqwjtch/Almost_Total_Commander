<h1 align="center">
  Almost Total Commander
</h1>
<p align="center">
  <img src="https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++ Badge">
  <img src="https://img.shields.io/badge/Qt-%23217346.svg?style=for-the-badge&logo=Qt&logoColor=white" alt="Qt Badge">
  <img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="Linux Badge">
</p>

A simple tabbed file manager, inspired by the functionality of Total Commander.
- [x] File system navigation
- [x] Basic operations with tabs
      (create, delete, moving through)
- [x] Basic operations with files, folders, symbolic links
      (create, delete, copy, move, rename, search)
- [x] Show hidden files 
- [x] Sort files
- [x] Hotkeys for operations (view in "Actions" drop-down menu)
- [x] Select multiple objects 
- [ ] Drag&Drop
- [ ] ~~Create, view, edit an archive~~
- [ ] Bookmarks for folders
- [ ] ~~Light/Dark theme mode~~
- [ ] Color the file names by extensions
- [x] Recycle Bin
- [ ] Revert changes

## How to start
### 1. Install the dependencies
Make sure that you have installed:
- `make`
- `g++` compiler (C++17 standard)
- `qmake` and `Qt` (Qt version >= 4)

Run to install all this on Ubuntu (or other Debian-based systems):
```
apt install build-essential qt5-qmake qtbase5-dev qtbase5-dev-tools qtchooser
```

### 2. Build the project
Create the `build` folder in the root folder of the project and navigate to it:
```
mkdir build
cd build
```
Run the build:
```
qmake ../Almost_Total_Commander.pro
make
```

### 3. Run the app
After the build is successful, run the compiled binary file:
```
./Almost_Total_Commander
```

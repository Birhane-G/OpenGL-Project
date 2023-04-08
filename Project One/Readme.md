# OpenGL
openGl is a cross-platform graphics API that is used to create 2D and 3D graphics in computer application. It provide a set of function that allow developers to create complex graphics images and animations, and it can be used with a variety of programming languages, including c++, java, python,  and more. OpenGL is widely used in video games, virtual reality applications, scientific visualization, and other areas where high-performance graphics are required.
- In this program we are going to use C++ programming Language and our platform is ubuntu

## Table of Contents
-[Prerequest](#prerequest)
-[Installation](#installation)
-[usage](#usage)


## Prerequest
- Gl :- It stands for Graphics Library, used for Rendering 2D and 3D graphics
```bash 
   http://www.opengl.org
``` 
- Glu :- It stands for OpenGl utility Library. it is a set of functions that provide additional functionality to OpenGl. Glu provides functions for creating and manipulating 3D objects, performing transformations,  and generating textures.
- Glut :- It stands for OpenGl utility Toolkit. It is a library for OpenGl programming. It provide a simple API for creating Windows, handling input events such as keyboard and mouse events, and creating menus.GLUT is also platform independent and can be used on Windows, Linux and Mac OS. 
```bash 
   http://www.opengl.org
``` 
## Installation
Now lets see How to install OpenGL on out Ubuntu OS
Now because GLUT (OpenGL Utility Toolkit) depends upon OpenGL and a number of other related libraries, if we install GLUT then OpenGL will be automatically be installed.

-Run the following commands to install OpenGL.
```bash 
    sudo apt-get update
``` 
```bash 
    sudo apt-get upgrade
``` 
```bash 
    sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
``` 

## Usage

- compile your code
```bash 
    g++ projectOne.cpp -o first -lglut -lGLU -lGL
``` 
- Run
```bash 
    ./first
``` 

## 
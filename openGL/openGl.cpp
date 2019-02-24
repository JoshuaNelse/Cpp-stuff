//
//  openGl.cpp
//  C++fibonacci
//
//  Created by josh shaver on 11/15/18.
//  Copyright © 2018 josh shaver. All rights reserved.
//


#include <iostream>
// GLEW
#define gGLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

const GLint WIDTH = 800;
const GLint HEIGHT = 600;

int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Learn OpenGL", nullptr, nullptr);
    
    int screenWidth;
    int screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    
    if (nullptr == window){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    
    glewExperimental = GL_TRUE;
    
    if (GLEW_OK != glewInit()){
        std::cout << "Failed to Initialize GLEW" << std::endl;
        return -1;
    }
    
    glViewport(0, 0, screenWidth, screenHeight);
    
    //game loop
    while (!glfwWindowShouldClose(window)){
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window);
    }
    
    glfwTerminate();
    return 0;
}


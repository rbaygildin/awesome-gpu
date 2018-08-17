#define GLEW_STATIC

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <GLFW/glfw3.h>

using namespace std;

static void errorCallback(int error, const char *description)
{
    fprintf(stderr, "Error %d: %s\n", error, description);
}

static void keyCallback(GLFWwindow *wnd, int key, int scanCode, int action, int mode){
    if(key ==GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(wnd, GL_TRUE);
}

int main() {
    glfwSetErrorCallback(errorCallback);
    if(!glfwInit()){
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *wnd = glfwCreateWindow(600, 600, "Hello world", nullptr, nullptr);
    if(wnd == nullptr){
        cerr << "Can not create window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(wnd);
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK){
        cerr << "Can not create GLEW context" << endl;
        return -1;
    }

    glfwSetKeyCallback(wnd, keyCallback);

    int w, h;
    glfwGetFramebufferSize(wnd, &w, &h);
    glViewport(0, 0, w, h);
    while(!glfwWindowShouldClose(wnd)){
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        glfwSwapBuffers(wnd);
    }
    glfwTerminate();

    return 0;
}
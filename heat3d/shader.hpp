#ifndef SHADER_H
#define SHADER_H

#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class shader
{
    GLuint id;
    GLuint vertex, fragment; 
    GLFWwindow *window;

    std::string load_file(const std::string file_name);
    GLuint compile_shader(const char* code, GLenum shader_type);
    GLuint create_program();

    void check_compilation_errors(GLuint id, bool is_shader);
public:
    shader(const std::string fragment_shader_filename, const std::string vertex_shader_filename);

    void use_program() const;
    void set_window(GLFWwindow *window);
    GLFWwindow* get_window() const;
    GLuint get_id() const;
};

#endif // SHADER_H
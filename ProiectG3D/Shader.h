#pragma once
#include <GL/glew.h>

#include <GLM.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <glfw3.h>

#pragma comment (lib, "glfw3dll.lib")
#pragma comment (lib, "glew32.lib")
#pragma comment (lib, "OpenGL32.lib")

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

	void Use() const;

	unsigned int GetID() const;

	unsigned int loc_model_matrix;
	unsigned int loc_view_matrix;
	unsigned int loc_projection_matrix;

	void SetVec3(const std::string& name, const glm::vec3& value) const;
	void SetVec3(const std::string& name, float x, float y, float z) const;
	void SetFloat(const std::string& name, float val) const;
	void SetMat4(const std::string& name, const glm::mat4& mat) const;

private:
	void Init(const char* vertexPath, const char* fragmentPath);
	void CheckCompileErrors(unsigned int shader, std::string type);

private:
	unsigned int ID;
};


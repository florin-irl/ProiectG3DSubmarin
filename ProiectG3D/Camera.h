#include <stdlib.h> 
#include <stdio.h>
#include <math.h> 

#include <GL/glew.h>

#include <GLM.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>

#include "ECameraMovementType.h"
class Camera
{
public:
	Camera(const int width, const int height, const glm::vec3& position);

	void Set(const int width, const int height, const glm::vec3& position);
	void Reset(const int widht, const int height);

	void Reshape(int windowWidth, int windowHeight);

	const glm::mat4 GetViewMatrix() const;
	const glm::vec3 GetPosition() const;
	const glm::mat4 GetProjectionMatrix() const;

	void ProcessKeyboard(ECameraMovementType direction, float deltaTime);
	void ProcessMouseScroll(float yOffset);

	void MouseControl(float xPos, float yPos);

private:
	void ProcessMouseMovement(float xOffset, float yOffset, bool constrainPitch = true);
	void UpdateCameraVectors();

	const float zNEAR = 0.1f;
	const float zFAR = 500.f;
	const float YAW = -90.0f;
	const float PITCH = 0.0f;
	const float FOV = 45.0f;
	glm::vec3 startPosition;

protected:
	const float cameraSpeedFactor = 2.5f;
	const float mouseSensitivity = 0.1f;
	float zNear;
	float zFar;
	float FoVy;
	int width;
	int height;
	bool isPerspective;

	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 right;
	glm::vec3 up;
	glm::vec3 worldUp;

	float yaw;
	float pitch;

	bool bFirstMouseMove = true;
	float lastX = 0.f, lastY = 0.f;
};
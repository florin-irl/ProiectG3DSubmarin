#include "Camera.h"

Camera::Camera(const int width, const int height, const glm::vec3& position)
{
	startPosition = position;
	Set(width, height, position);

}

void Camera::Set(const int width, const int height, const glm::vec3& position)
{
	this->isPerspective = true;
	this->yaw = YAW;
	this->pitch = PITCH;

	this->FoVy = FOV;
	this->width = width;
	this->height = height;
	this->zNear = zNEAR;
	this->zFar = zFAR;

	this->worldUp = glm::vec3(0, 1, 0);
	this->position = position;

	lastX = width / 2.0f;
	lastY = height / 2.0f;
	bFirstMouseMove = true;

	UpdateCameraVectors();
}

void Camera::Reset(const int width, const int height)
{
	Set(width, height, startPosition);
}

void Camera::Reshape(int windowWidth, int windowHeight)
{
	width = windowWidth;
	height = windowHeight;

	glViewport(0, 0, windowWidth, windowHeight);
}

const glm::mat4 Camera::GetViewMatrix() const
{
	return glm::lookAt(position, position + forward, up);
}

const glm::vec3 Camera::GetPosition() const
{
	return position;
}

const glm::mat4 Camera::GetProjectionMatrix() const
{
	glm::mat4 Proj = glm::mat4(1);
	if (isPerspective) {
		float aspectRatio = ((float)(width)) / height;
		Proj = glm::perspective(glm::radians(FoVy), aspectRatio, zNear, zFar);
	}
	else {
		float scaleFactor = 2000.f;
		Proj = glm::ortho<float>(
			-width / scaleFactor, width / scaleFactor,
			-height / scaleFactor, height / scaleFactor, -zFar, zFar);
	}
	return Proj;
}

void Camera::UpdateCameraVectors()
{
	this->forward.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	this->forward.y = sin(glm::radians(pitch));
	this->forward.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	this->forward = glm::normalize(this->forward);

	right = glm::normalize(glm::cross(forward, worldUp));
	up = glm::normalize(glm::cross(right, forward));
}

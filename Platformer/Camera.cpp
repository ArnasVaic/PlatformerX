#include "Camera.h"

Camera::Camera() noexcept {
	setTarget(0.0f, 0.0f);
}

Camera::Camera(float x, float y) noexcept {
	setTarget(x, y);
}

void Camera::move(float dx, float dy) noexcept {
	al_translate_transform(&transform, dx, dy);
	x += dx;
	y += dy;
}

void Camera::setTarget(float nx, float ny) noexcept {
	al_identity_transform(&transform);
	al_translate_transform(&transform, nx, ny);
	x = nx; 
	y = ny;	
}
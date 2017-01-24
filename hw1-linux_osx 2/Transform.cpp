// Transform.cpp: implementation of the Transform class.


#include "Transform.h"
using namespace glm;

//Please implement the following functions:

// Helper rotation function.
mat3 Transform::rotate(const float degrees, const vec3& axis) {
	// YOUR CODE FOR HW1 HERE
	vec3 axis2 = vec3();
	axis2 = normalize(axis);		//normalize axis
	float x = axis2.x;
	float y = axis2.y;
	float z = axis2.z;
	mat3 M1 = mat3(1.0f);
	mat3 M2 = mat3(vec3(x*x,x*y,x*z),vec3(x*y,y*y,y*z),vec3(x*z,y*z,z*z));
	mat3 M3 = mat3(vec3(0,-z,y),vec3(z,0,-x),vec3(-y,x,0));
	float radians = degrees*pi<float>()/180.0;
	mat3 Mrotate = cos(radians)*M1+(1-cos(radians))*M2+sin(radians)*M3;

	return Mrotate;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
	// YOUR CODE FOR HW1 HERE
	vec3 y = up;
	eye = rotate(-degrees, y) * eye;
	up = rotate(-degrees, y) * up;
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
	// YOUR CODE FOR HW1 HERE
	vec3 x = cross(eye,up);
	eye = rotate(-degrees, x) * eye;
	up = rotate(-degrees, x) * up;
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
	// YOUR CODE FOR HW1 HERE

	// You will change this return call
	return mat4();
}

Transform::Transform()
{

}

Transform::~Transform()
{

}

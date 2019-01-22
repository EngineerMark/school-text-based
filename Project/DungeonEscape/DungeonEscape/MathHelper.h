#pragma once
#include <glm/vec3.hpp>

class MathHelper {
public:
	static float Lerp(float a, float b, float time) {
		return a + time * (b - a);
	}

	static glm::vec3 Lerp(glm::vec3 a, glm::vec3 b, float time) {
		glm::vec3 v;
		v.x = Lerp(a.x, b.x, time);
		v.y = Lerp(a.y, b.y, time);
		v.z = Lerp(a.z, b.z, time);
		return v;
	}
};
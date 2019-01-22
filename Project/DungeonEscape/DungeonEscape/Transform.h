#pragma once
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include "Component.h"
#include "Time.h"
#include "MathHelper.h"

class Transform : public Component
{
private:
	glm::vec3 position;
	glm::quat rotation;
	glm::vec3 scale;
public:
	void SetPosition(glm::vec3 pos) {
		this->position = pos;
	}
	glm::vec3 GetPosition() {
		return position;
	}
	void SetRotation(glm::quat rot) {
		this->rotation = rot;
	}
	glm::quat GetRotation() {
		return rotation;
	}
	void SetScale(glm::vec3 scale) {
		this->scale = scale;
	}
	void SetScale(float scale) {
		this->scale *= scale;
	}
	glm::vec3 GetScale() {
		return scale;
	}

	void Translate(glm::vec3 oldPosition, glm::vec3 newPosition, float time) {
		float _time = Time::GetStartTime();

		SetPosition(MathHelper::Lerp(oldPosition,newPosition, _time));
	}
};


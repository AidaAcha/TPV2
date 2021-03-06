#pragma once

#include <SDL.h>
#include <cassert>

#include "../ecs/Component.h"
#include "../sdlutils/InputHandler.h"
#include "../ecs/Entity.h"
#include "Transform.h"

//#include <math.h>

class FighterCtrl : public Component {
public:
	FighterCtrl() :
		tr_(nullptr), speed_(10.0){
		thrust_ = 0.2;
		speedLimit_ = 1.0f;
	}
	virtual ~FighterCtrl() {
	}


	inline void setSpeed(float speed) {
		speed_ = speed;
	}

	void init() override {
		tr_ = entity_->getComponent<Transform>();
		assert(tr_ != nullptr);
	}

	void update() override {
		if (ih().keyDownEvent()) {
			auto& vel = tr_->getVel();
			auto rot = tr_->getRot();

			if (ih().isKeyDown(SDL_SCANCODE_UP)) {
				newVel = vel + Vector2D(0, -1).rotate(rot) * thrust_;
				vel = newVel;
				/*float velReal = sqrt((int)newVel.getX() ^ 2 + (int)newVel.getY() ^ 2);

				if(velReal > speedLimit_){ vel = vel.normalize()* speedLimit_; }
				else { vel = newVel; }*/
				//double y = (double)x ^ 2;
				/*double velReal = sqrt(newVel.getX() ^ 2 + newVel.getY() ^ 2);*/
				/*if(sqrt(newVel.getX()^2 + newVel.getY() ^ 2) > speedLimit_){  }
				else { vel.normalize()* speedLimit_; }*/

			}
			
			if (ih().isKeyDown(SDL_SCANCODE_LEFT)) {
				rot -= 5.0f;
				tr_->setRot(rot);
			}
			else if (ih().isKeyDown(SDL_SCANCODE_RIGHT)) {
				rot += 5.0f;
				tr_->setRot(rot);
			}
			else if (ih().isKeyDown(SDL_SCANCODE_SPACE)) {
				/*vel.setY(0.0f);
				vel.setX(0.0f);*/
			}

		}
	}

private:
	Transform* tr_;
	float speed_;
	float thrust_;
	float speedLimit_;
	Vector2D newVel;
}
;


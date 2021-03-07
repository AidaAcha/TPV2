#pragma once
#include <cassert>

#include "../ecs/Component.h"
#include "../ecs/Entity.h"
#include "../sdlutils/macros.h"
#include "../sdlutils/SDLUtils.h"
#include "Transform.h"

class Health : public Component {
public:
	/*Rectangle() :
		Rectangle(build_sdlcolor(0xffffffff)) {
	}*/
	Health(Texture* tex, Transform *T) {
		health = 3;
		tex_ = tex;
		tr_ = T;
	}
	virtual ~Health() {
	}

	void init() override {
		tr_ = entity_->getComponent<Transform>();
		assert(tr_ != nullptr);
	}
	void render() override {
		SDL_Rect dest = build_sdlrect(tr_->getPos(), tr_->getW(), tr_->getH());
		tex_->render(dest, tr_->getRot());
		
	}
private:
	int health;
	Transform* tr_;
	Texture* tex_;
};

#include "Player.h"

#include "Game.h"
#include "Loader.h"

void Player::Init() {

	Renderer* renderer = AddRenderer();
	renderer->AddImage(AddTexture("Image/Character.png"));
	
}

void Player::Start() {

}


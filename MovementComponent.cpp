#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration)
	:sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{

}

MovementComponent::~MovementComponent()
{
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	// TODO: insert return statement here
	return this->velocity;
}

const bool MovementComponent::getState(const short unsigned state) const
{
	switch (state)
	{
	case IDLE:
		if (this->velocity.x == 0.f && this->velocity.y == 0.f)
			return true;

		return false;
		break;
	case MOVING_LEFT:
		if (this->velocity.x < 0.f)
			return true;

		return false;
		break;
	case MOVING_RIGHT:
		if (this->velocity.x > 0.f)
			return true;

		return false;
		break;
	case MOVING_UP:
		if (this->velocity.y < 0.f)
			return true;

		return false;
	break;
	case MOVING_DOWN:
		if (this->velocity.y > 0.f)
			return true;

		return false;
		break;
	default:
		break;
	}
}

const bool MovementComponent::idle() const
{
		if (this->velocity.x == 0.f && this->velocity.y == 0.f)
			return true;

		return false;
}

const bool MovementComponent::movingLeft() const
{
	if (this->velocity.x < 0.f)
		return true;

	return false;
}

const bool MovementComponent::movingRight() const
{
	if (this->velocity.x > 0.f)
		return true;

	return false;
}

const bool MovementComponent::moving() const
{
	if (this->velocity.x != 0.f || this->velocity.y != 0.f)
		return true;

	return false;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float& dt)
{
	//Acceleration.
	this->velocity.x += this->acceleration * dir_x;
	
	this->velocity.y += this->acceleration * dir_y;
	
}

void MovementComponent::update(const float& dt)
{


	/*Decelerate the sprite and controls the maximum velocity.
	and moves the sprite */
	if (this->velocity.x > 0.f) // for +ve x
	{

		// Max Velocity Check
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;

			
		// Deceleration x positive
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;


	}

	else if (this->velocity.x < 0.f) // check for -ve x
	{
		// Max velocity Check x negative 
		if (this->velocity.x < -this->maxVelocity) {
			this->velocity.x = -this->maxVelocity;
		}

		//Deceleration x -ve
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;

	}


	//
	if (this->velocity.y > 0.f) // for +ve y
	{

		// Max Velocity Check
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;


		// Deceleration y positive
		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;


	}

	else if (this->velocity.y < 0.f) // check for -ve y
	{
		// Max velocity Check y negative 
		if (this->velocity.y < -this->maxVelocity) {
			this->velocity.y = -this->maxVelocity;
		}

		//Deceleration y -ve
		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;

	}



	//final move
	this->sprite.move(this->velocity * dt); //Uses velocity
}

#ifndef CHARACTER_H
#define CHARACTER_H


#include "Entity.h"
#include "../Managers/EventManager.h"
namespace Entities
{
	class Character: public Entity
	{
	protected:
		int lifePoints;

		bool isLookingToTheRight;

		bool isGrounded;

		bool vulnerability;

		sf::Vector2<float> vel;


	public:
		Character(int life, Managers::GraphicManager* pGraphicsManager = nullptr,Stages::Stage* pStage = nullptr);
		virtual ~Character();
		virtual void execute(float dt, Managers::EventManager* pEventManager) = 0;
		void move(float x, float y);

		void setGrounded(bool ground);
		bool getGrounded() const;

		sf::Vector2<float> getVel() const;
		void setVel(const float x, const float y);


		bool isAlive();
		int getLife();
		void setLife(int life);
		void addLifePoints(int points);
		void decrementLifePoints(int points);
	};
}

#endif //CHARACTER_H

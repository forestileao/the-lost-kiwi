//
// Created by forestileao on 05/07/2021.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Character.h"
#include "../States/StateMachine.h"

#define PLAYER_JUMP_STATE "PlayerJumpState"
#define PLAYER_REST_STATE "PlayerRestState"
//PlayerFireStateName,
#define PLAYER_WALK_STATE "PlayerWalkState"

#define DEFAULT   0, 0,  30, 45
#define JUMP     64, 0,  16, 20
#define JUMP_L   80, 0, -16, 20
#define WALK_R1 144, 0,  16, 20
#define WALK_R2 160, 0,  16, 20
#define WALK_L1 160, 0, -16, 20
#define WALK_L2 176, 0, -16, 20

#define WALK_ANIMATION_FRAME_TIME 0.1

#define PLAYER1_TEXTURE_FILE   "../assets/zombie-boy.png"
#define PLAYER2_TEXTURE_FILE  "../assets/zombie-boy.png"

#define VULNERABILITY_MAX 0.5f

namespace Stages
{
class Stage;
}
namespace Entities
{
	class Player: public Character
	{
	private:

		/* Player State Machine*/
		class PlayerStateMachine: public States::StateMachine
		{
		public:
			PlayerStateMachine(Player *p = nullptr);
			~PlayerStateMachine();
		};

		/* Player States */
		class PlayerJumpState: public States::State
		{
		private:
			Player *p;
		public:
			PlayerJumpState(States::StateMachine* pStateMachine = NULL, Player *p = NULL);
			virtual ~PlayerJumpState();

			void init(void* arg);

			void update(float dt, Managers::EventManager* pEventManager);
			void draw(Managers::GraphicManager* pGraphicManager);
		};
		class PlayerRestState: public States::State
		{
		private:
			Player *p;
		public:
			PlayerRestState(States::StateMachine* pStateMachine = NULL, Player *p = NULL);
			virtual ~PlayerRestState();

			void init(void* arg){std::cout << "REST\n";}

			void update(float dt, Managers::EventManager* pEventManager);
			void draw(Managers::GraphicManager* pGraphicManager);
		};
		class PlayerWalkState: public States::State
		{
		private:
			Player *p;
		public:
			PlayerWalkState(States::StateMachine* pStateMachine = NULL, Player *p = NULL);
			virtual ~PlayerWalkState();

			void init(void* arg){std::cout << "WALK\n"; p->nRect = false; p->frameTime = 0.0f;}

			void update(float dt, Managers::EventManager* pEventManager);
			void draw(Managers::GraphicManager* pGraphicManager);
		};

	private:
		const float groundAcceleration = 9;
		const float airAcceleration = 0.5;
		const float velMax = 100;
		const float jumpVel = 300;

		States::StateMachine *stateMachine;

		Managers::GraphicManager* pGraphicManager;

		Managers::EventManager::keyCode leftKey;
		Managers::EventManager::keyCode rightKey;
		Managers::EventManager::keyCode jumpKey;
		Managers::EventManager::keyCode attackKey;

		bool rightDirection;
		bool double_jump;
		bool nRect;

		Stages::Stage* pStage;

		float frameTime;
		float vulnerability_timer;
		const float attackInterval = 0.5f;
		float attackTimer;

		void setControls(bool isPlayerOne);

	public:
		Player(int life, Stages::Stage* pStage = nullptr, bool firstPlayer = true, Managers::GraphicManager* pGraphicManager = nullptr);
		~Player();

		void execute(float dt, Managers::EventManager *pEventManager);
	};
}

#endif //PLAYER_H

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

#define REST_R   0, 0,  21, 43
#define REST_L   21, 0,  -21, 43

#define JUMP     0, 133,  26, 44

#define JUMP_X 0
#define JUMP_Y 133
#define JUMP_SIZE_X 26
#define JUMP_SIZE_Y 44

// Jumping Pixels
#define WALK_X 36
#define WALK_Y 44
#define WALK_SIZE_X 33
#define WALK_SIZE_Y 44

#define WALK_ANIMATION_FRAME_TIME 0.1

#define PLAYER1_TEXTURE_FILE   "../assets/tileset_player.png"
#define PLAYER2_TEXTURE_FILE  "../assets/tileset_player2.png"

#define VULNERABILITY_MAX_TIME 0.5f

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
			Player *pPlayer;
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

			void init(void* arg){std::cout << "PLAYER: Resting\n";}

			void update(float dt, Managers::EventManager* pEventManager);
			void draw(Managers::GraphicManager* pGraphicManager);
		};
		class PlayerWalkState: public States::State
		{
		private:
			Player *pPlayer;
		public:
			PlayerWalkState(States::StateMachine* pStateMachine = NULL, Player *p = NULL);
			virtual ~PlayerWalkState();

			void init(void* arg){std::cout << "PLAYER: Walking\n"; pPlayer->numRect = false; pPlayer->frameTime = 0.0f;}

			void update(float dt, Managers::EventManager* pEventManager);
			void draw(Managers::GraphicManager* pGraphicManager);
		};

	private:
		Managers::EventManager::keyCode leftKey;
		Managers::EventManager::keyCode rightKey;
		Managers::EventManager::keyCode jumpKey;
		Managers::EventManager::keyCode attackKey;

		const float acceleration = 9;
		const float JumpingAcceleration = 50;
		const float maxVel = 100;
		const float jumpVel = 300;

		States::StateMachine *stateMachine;
		Managers::GraphicManager* pGraphicManager;

		bool double_jump;
		int numRect;

		float frameTime;
		float vulnerabilityTimer;
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

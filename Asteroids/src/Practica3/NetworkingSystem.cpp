#include "NetworkingSystem.h"

#include "messages.h"
#include "EntityManager.h"

NetworkingSystem::NetworkingSystem() :
	System(ECS::_sys_NetWorking) {

}

NetworkingSystem::~NetworkingSystem() {
}

void NetworkingSystem::receive(const messages::Message& msg) {
	if (msg.senderClientId == manager_->getClientId()) {
		game_->getNetworking()->send(msg);
	}
}

void NetworkingSystem::update() {
	auto net = game_->getNetworking();
	messages::Message* msg = nullptr;

	while ((msg = net->recieve()) != nullptr) 
	{
		switch (msg->id) 
		{
		case messages::_PLAYER_INFO:
			manager_->forwardMsg<messages::Message>(msg->senderClientId, messages::_PLAYER_INFO);
			break;

		case messages::_CLIENT_DISCONNECTED:
			manager_->forwardMsg<messages::ClientDisconnectedMsg>(msg->senderClientId,
				static_cast<messages::ClientDisconnectedMsg*>(msg)->clientId);
			break;

		case messages::_START_REQ:
			manager_->forwardMsg<messages::Message>(msg->senderClientId, messages::_START_REQ);
			break;

		case messages::_START_ROUND: {
			manager_->forwardMsg<messages::Message>(msg->senderClientId, messages::_START_ROUND);
			break;
		}

		case messages::_BULLET_COLLISION: {
			manager_->forwardMsg<messages::BulletCollision>(msg->senderClientId, 
				static_cast<messages::BulletCollision*>(msg)->fighter);
			break;
		}

		case messages::_FIGHTER_INFO:
		{
			manager_->forwardMsg<messages::FighterInfo>(msg->senderClientId,
				static_cast<messages::FighterInfo*>(msg)->x,
				static_cast<messages::FighterInfo*>(msg)->y,
				static_cast<messages::FighterInfo*>(msg)->r);
			break;
		}

		default:
			assert(false);
			break;
		}
	}

}

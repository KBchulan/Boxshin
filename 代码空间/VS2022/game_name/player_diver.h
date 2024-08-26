#ifndef _PLAYER_DIVER_H_
#define _PLAYER_DIVER_H_

#include "player.h"

extern Atlas game_atlas_gamer_diver;

class PlayerDive : public Player {
public:
	PlayerDive(){
		animation_player_idle.set_atlas(&game_atlas_gamer_diver);
		animation_player_idle.set_interval(75);
		animation_player_idle.set_loop(true);

	
		
	}

	~PlayerDive() = default;

	void data_input(const ExMessage& msg) {
		Player::data_input(msg);

	}

	void data_update(int delta) {
		animation_player_idle.data_update(delta);
		Player::data_update(delta);

	}

	void picture_draw() {
		Player::picture_draw();
	}





private:



};

#endif // !_PLAYER_DIVER_H_


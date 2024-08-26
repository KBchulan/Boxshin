#ifndef _PLAYER_LYPO_H_
#define _PLAYER_LYPO_H_

#include "player.h"

extern Atlas game_atlas_gamer_lypo_left;
extern Atlas game_atlas_gamer_lypo_right;

class PlayerLypo : public Player {
public:
	PlayerLypo() {
		animation_player_idle_left.set_atlas(&game_atlas_gamer_lypo_left);
		animation_player_idle_left.set_interval(75);
		animation_player_idle_left.set_loop(true);
		
		animation_player_idle_right.set_atlas(&game_atlas_gamer_lypo_right);
		animation_player_idle_right.set_interval(75);
		animation_player_idle_right.set_loop(true);
	}

	~PlayerLypo() = default;

	void data_input(const ExMessage& msg) {
		Player::data_input(msg);

	}

	void data_update(int delta) {
		Player::data_update(delta);

	}

	void picture_draw() {
		Player::picture_draw();
	}


private:

};

#endif // !_PLAYER_LYPO_H_

#ifndef _PLAYER_DIVER_H_
#define _PLAYER_DIVER_H_

#include "player.h"

extern Atlas game_atlas_gamer_diver_left;
extern Atlas game_atlas_gamer_diver_right;
extern Atlas game_atlas_gamer_diver_win;
extern Atlas game_atlas_gamer_diver_die;
extern Atlas game_atlas_gamer_diver_left_big;
extern Atlas game_atlas_gamer_diver_right_big;

class PlayerDive : public Player {
public:
	PlayerDive() {
		animation_player_idle_left.set_atlas(&game_atlas_gamer_diver_left);
		animation_player_idle_right.set_atlas(&game_atlas_gamer_diver_right);
		animation_player_win.set_atlas(&game_atlas_gamer_diver_win);
		animation_player_die.set_atlas(&game_atlas_gamer_diver_die);
		animation_player_big_left.set_atlas(&game_atlas_gamer_diver_left_big);
		animation_player_big_right.set_atlas(&game_atlas_gamer_diver_right_big);
	}
	~PlayerDive() = default;

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

#endif // !_PLAYER_DIVER_H_


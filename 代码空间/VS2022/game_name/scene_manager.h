#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include"scene.h"

extern Scene* map_scene;
extern Scene* set_scene;
extern Scene* exit_scene;
extern Scene* menu_scene;
extern Scene* game_scene;
extern Scene* selector_scene;
extern Scene* game_introduction_scene;
extern Scene* team_introduction_scene;

class SceneManager {
public:
	SceneManager() = default;
	~SceneManager() = default;

	void set_start_scene(Scene* scene) {
		current_scene = scene;
		current_scene->scene_enter();
	}

	void switch_to(int x) {
		current_scene->scene_exit();
		switch (x) {
		case 1:
			current_scene = menu_scene;
			break;
		case 2:
			current_scene = selector_scene;
			break;
		case 3:
			current_scene = game_scene;
			break;
		case 4:
			current_scene = map_scene;
			break;
		case 5:
			current_scene = set_scene;
			break;
		case 6:
			current_scene = exit_scene;
			break;
		case 7:
			current_scene = game_introduction_scene;
			break;
		case 8:
			current_scene = team_introduction_scene;
			break;
		default:
			break;
		}

		current_scene->scene_enter();
	}

	void data_input(const ExMessage& msg) {
		current_scene->data_input(msg);
	}

	void data_update(int delta) {
		current_scene->data_update(delta);
	}

	void picture_draw() {
		current_scene->picture_draw();
	}


private:
	Scene* current_scene = nullptr;

};

#endif // !_SCENE_MANAGER_H_

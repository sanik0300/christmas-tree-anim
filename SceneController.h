#pragma once
#include <SFML/Graphics.hpp>
#include "XTree.h"
using namespace sf;
struct SceneController
{
private:

	bool isMousePressed = false;
	int LastMouseX, LastMouseY;
	XTree* p;
public:
	RenderWindow *rw;
	int cameraoffsetZ;
	
	static int Xoffset, Yoffset;
	
	~SceneController();
	void init_tree(XTree* tree);
	void start_window_lifecycle();
	void rememberMousePress(int Xnew, int Ynew);
};


#include "SceneController.h"
#include "XTree.h"

 int SceneController::Xoffset;
 int SceneController::Yoffset;

 SceneController::~SceneController()
 {
	 delete this->rw;
	 delete this->p;
 }

void SceneController::init_tree(XTree *tree)
{
	this->p = tree;
}

void SceneController::start_window_lifecycle()
{
	Event _event;
	while (this->rw->isOpen())
	{
		while (this->rw->pollEvent(_event))
		{
			switch (_event.type)
			{
			case Event::Closed:
				this->rw->close();
				break;
			case Event::MouseMoved:
				if (!Mouse::isButtonPressed(Mouse::Left)) { break; }

				this->p->rotate(RotationDirection::X, _event.mouseMove.y - this->LastMouseY);
				this->p->rotate(RotationDirection::Y, _event.mouseMove.x - this->LastMouseX);
				break;
			case Event::MouseButtonPressed:
				if (_event.mouseButton.button != Mouse::Left || isMousePressed) { break; }

				this->rememberMousePress(_event.mouseButton.x, _event.mouseButton.y);
				this->isMousePressed = true;
				break;
			case Event::MouseButtonReleased:
				this->isMousePressed = false;
				break;
			}
			this->rw->clear(Color(255, 255, 255));
			this->p->draw(*(this->rw), Xoffset, Yoffset);
			this->rw->display();
		}
	}
}

void SceneController::rememberMousePress(int Xnew, int Ynew)
{
	this->LastMouseX = Xnew;
	this->LastMouseY = Ynew;
}

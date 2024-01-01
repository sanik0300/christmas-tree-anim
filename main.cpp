#include <SFML/Window.hpp>
#include <iostream>
#include "SceneController.h"
using namespace std;

void input_val(string description, int& what_to_enter, int deflt)
{
	cout << "Enter the " << description << ": ";
	cin >> what_to_enter;
	if (what_to_enter > 0) { return; }

	cout << "	Invalid value given, setting default " << deflt << endl;
	what_to_enter = deflt;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() 
{
	SceneController scenecontroller;
	int window_side, tree_height, tree_smallest_part, tree_largest_part, triangles_count, thickness;

	input_val("window side length in px", window_side, 900);
	input_val("tree height in px", tree_height, 800);
	input_val("side length of the largest triangle in tree in px", tree_largest_part, 500);
	input_val("side length of the smallest triangle in tree in px", tree_smallest_part, 10);
	input_val("amount of triangles in tree", triangles_count, 10);
	input_val("thickness of triangles in px", thickness, 40);

	scenecontroller.rw = new RenderWindow(VideoMode(window_side, window_side), "happy new year!");
	scenecontroller.cameraoffsetZ = tree_height;
	scenecontroller.init_tree(new XTree(tree_height, tree_smallest_part, tree_largest_part, triangles_count, thickness));
	
	SceneController::Xoffset = SceneController::Yoffset = window_side/2;
	cout << "Spin the tree with left mouse button pressed :)\n";

	scenecontroller.start_window_lifecycle();
	

	return 0;
}
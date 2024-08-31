#ifndef RESOURCES_LOADER_H
#define RESOURCES_LOADER_H

#include <fstream>
#include <SFML/Graphics.hpp>

class ResourcesLoader {
public:
	static sf::Texture *loadTexture(const std::string &spriteSheet, int left, int top, int width, int height);
	static std::vector<std::string> loadMap(int num);

private:
	static std::ifstream *openFile(const std::string &filePath);
};

#endif
#include "ResourcesLoader.h"

sf::Texture *ResourcesLoader::loadTexture(
	const std::string &spriteSheet,
	const int left, const int top,
	const int width, const int height
	) {
	const auto texture = new sf::Texture;
	texture->loadFromFile(spriteSheet, sf::IntRect(left, top, width, height));
	return texture;
}

std::vector<std::string> ResourcesLoader::loadMap(const int num) {
	const std::string path = "res/Maps/" + std::to_string(num) + ".txt";
	std::vector<std::string> map;

	std::ifstream *stream = openFile(path);

	if (stream == nullptr) {
		throw std::runtime_error("File couldn't be opened!");
	}

	while (!stream->eof()) {
		std::string fileString;
		*stream >> fileString;
		map.push_back(fileString);
	}

	stream->close();
	delete stream;
	return map;
}

std::ifstream *ResourcesLoader::openFile(const std::string &filePath) {
	const auto stream = new std::ifstream;
	stream->open(filePath);

	if (stream->is_open()) {
		return stream;
	}

	delete stream;
	return nullptr;
}

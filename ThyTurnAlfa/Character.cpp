#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Character.hpp"

Character::Character(std::string name, std::string imagePath, std::vector<std::unique_ptr<Movement>>& movements):
	m_name{ name }, m_imagePath{ imagePath }, movements { std::move(movements) } {}

bool Character::applyEffects() {
	for (auto it = activeEffects.begin(); it != activeEffects.end(); it++) {
		if (!(*it)->nextRound(*this)) {
			(*it)->cancelFrom(*this);
			activeEffects.erase(it);
		}
	}
	return true;
}

void Character::detachEffects() {
	for (auto& e : activeEffects) {
		e->cancelFrom(*this);
	}
	activeEffects.clear();
}

void Character::reset() {
    detachEffects();
	currentHp = m_hp;
	currentMp = m_mp;
	wAtk = 0;
	wDef = 0;
	isAlive = true;
}

bool Character::loadImage() {
    unsigned int textureID;
    glGenTextures(1, &textureID);
    int width, height, channels;
    unsigned char* data = stbi_load(m_imagePath.c_str(), &width, &height, &channels, 0);
    if (data) {
        GLenum format;
        if (channels == 1) {
            format = GL_RED;
        } else if (channels == 3) {
            format = GL_RGB;
        } else if (channels == 4) {
            format = GL_RGBA;
        }

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else { return false; }
    stbi_image_free(data);
    return true;
}

const std::string Character::getName() const { return m_name; }

const ImTextureID* Character::getTextureID() const { return (ImTextureID*)m_textureID; }

const int Character::getHp() const { return m_hp; }

const int Character::getMp() const { return m_mp; }

const int Character::getAtk() const { return m_atk; }

const int Character::getDef() const { return m_def; }

const int Character::getSpd() const { return m_spd; }

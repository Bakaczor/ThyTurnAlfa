#include <utility>

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Character.hpp"
#include "Shield.hpp"
#include "Effect.hpp"
#include "MovementFactory.hpp"
#include "Movement.hpp"

Character::Character(const Character& c):
	id{ c.id }, currentHp{ c.currentHp }, currentMp{ c.currentMp },
	wAtk{ c.wAtk }, wDef{ c.wDef }, isAlive{ c.isAlive }, m_name { c.m_name },
	m_imagePath { c.m_imagePath }, m_textureID { c.m_textureID }, 
	m_hp { c.m_hp }, m_mp { c.m_mp }, m_atk { c.m_atk }, m_def{ c.m_def }, m_spd{ c.m_spd },
	movements { c.movements } { }

bool Character::applyDamage(int dmg)
{
    for (auto& e : activeEffects) {
        Shield* ptr = dynamic_cast<Shield*>(e.get());
        if (ptr) {
            if (dmg > ptr->hp) {
                dmg -= ptr->hp;
                ptr->hp = 0;
            } else {
                ptr->hp -= dmg;
                return true;
            }
        }
    }
    if (dmg > 0) {
        if (dmg >= currentHp) {
            currentHp = 0;
            detachEffects(); // on_whom died so all effects must be detached
            isAlive = false;
            return false;
        } else {
            currentHp -= dmg;
        }
    }
    return true;
}

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
    detachEffects();
}

void Character::deserialize(Json::Value& root)
{
	m_hp = root["hp"].asInt();
	currentHp = m_hp;
	m_atk = root["atk"].asInt();
	m_def = root["def"].asInt();
	m_spd = root["spd"].asInt();
	m_mp = root["mp"].asInt();
	m_name = root["name"].asString();
	m_imagePath = root["imagePath"].asString();

	auto movementArray = root["movements"];
	for (auto move : movementArray) {
		auto pMovement = MovementFactory::create(move["name"].asString());
		if (pMovement != nullptr) {
			movements.push_back(std::move(pMovement));
		}
	}
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

const unsigned int Character::getPlayerId() const { return id / Const::Sizes::MAX_PARTY_SIZE; }

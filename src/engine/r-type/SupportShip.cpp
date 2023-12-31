/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** SupportShip
*/

#include "SupportShip.hpp"

SupportShip::SupportShip(EntityInfo info, int relatedPlayerId)
    : Character(info) {
    JsonParser parser;
    nlohmann::json json = parser.readFile("SupportShip.rType.json");
    setShootAsset(parser.get<std::string>(json, "ProjectileType"));
    setSpeed(RType::instance->getPlayer(relatedPlayerId)->getSpeed());
    setFireRate(parser.get<float>(json, "FireRate"));
    setProjectileSpeed(parser.get<float>(json, "ProjectileSpeed"));
    setDamage(parser.get<int>(json, "Damage"));
    setLife(parser.get<int>(json, "Life"));
    _relatedPlayerId = relatedPlayerId;
}

SupportShip::SupportShip(EntityInfo info) : Character(info) {
    JsonParser parser;
    nlohmann::json json = parser.readFile("SupportShip.rType.json");
    setShootAsset(parser.get<std::string>(json, "ProjectileType"));
    setFireRate(parser.get<float>(json, "FireRate"));
    setSpeed(6);
    setProjectileSpeed(parser.get<float>(json, "ProjectileSpeed"));
    setDamage(parser.get<int>(json, "Damage"));
    setLife(parser.get<int>(json, "Life"));
    _relatedPlayerId = -1;
}

SupportShip::~SupportShip() {}

void SupportShip::update() {
    if (_relatedPlayerId == -1) {
        for (auto& it : RType::instance->getPlayers()) {
            if (it->AEntity::getEntityHasCollided() &&
                !it->AEntity::getHasSupport() &&
                AEntity::getEntityHasCollided()) {
                _relatedPlayerId = it->getId();
                RType::instance->setPlayerHasSupport(_relatedPlayerId, true);
                break;
            }
        }
        if (_relatedPlayerId == -1)
            return;
    }
    if (_x != _oldX || _y != _oldY) {
        setOldPosition(_x, _y);
    }

    auto player = RType::instance->getPlayer(_relatedPlayerId);
    if (player == nullptr) {
        //destroy support
        return;
    }
    auto pos = player->getPosition();
    int x = std::get<0>(pos);
    int y = std::get<1>(pos);
    if (player->getEntityHasCollided() == true &&
        AEntity::getEntityHasCollided() == false) {
        player->setEntitiesHasCollided(false);
        setEntitiesHasCollided(false);
    }

    if (_launched) {
        if (_launchX <= 100 && _x < 830 && x > 10) {
            _direction == IEntity::RIGHT ? move(1, 0) : move(-1, 0);
            _launchX++;
            return;
        } else {
            _launchX = 0;
            _launched = false;
            setEntitiesHasCollided(false);
        }
    }

    shoot();
    bool touched = AEntity::getEntityHasCollided();
    IEntity::Direction playerDirection = player->getDirection();

    if (playerDirection == IEntity::LEFT && _direction == IEntity::RIGHT) {
        flip();
    } else if (playerDirection == IEntity::RIGHT &&
               _direction == IEntity::LEFT) {
        flip();
    }

    if (playerDirection == IEntity::LEFT && touched) {
        setPosition(x - player->getRadius() - 10, y);
    } else if (playerDirection == IEntity::RIGHT && touched) {
        setPosition(x + player->getRadius() + 10, y);
    } else {
        if (x == _playerOldX && y == _playerOldY) {
            return;
        } else if (x != _playerOldX && y == _playerOldY) {
            _playerOldX = x;
            setPosition(x, _y);
        } else {
            if (y > _playerOldY) {
                _playerOldY = y;
                y = y - 40;
            } else {
                _playerOldY = y;
                y = y + 40;
            }
            _playerOldX = x;
            setPosition(x, y);
        }
    }
}

void SupportShip::shoot() {
    if (!canShoot())
        return;
    auto pos = getPosition();
    EntityInfo info;
    info.x = std::get<0>(pos) + (_direction == RIGHT ? 30 : -30);
    info.y = std::get<1>(pos) - 2;
    info.name = getProjectileAsset();
    info.scaleX = 0.25;
    info.scaleY = 0.25;
    info.speed = getProjectileSpeed();
    info.damage = getDamage();
    info.spriteConfigJsonObjectName = getProjectileAsset();
    info.spriteConfigJsonFileName = "rTypeAnimationConfig.json";
    info.direction = _direction;
    RType::instance->createProjectile(
        info, _direction == IEntity::LEFT ? true : false,
        IGame::ProjectileGroup::SUPPORT);
    info.y = info.y + 4;
    RType::instance->createProjectile(
        info, _direction == IEntity::LEFT ? true : false,
        IGame::ProjectileGroup::SUPPORT);
    RType::instance->createSound("dropperShoot.ogg");
}

int SupportShip::getRelatedPlayerId() const {
    return _relatedPlayerId;
}

void SupportShip::launch() {
    if (AEntity::getEntityHasCollided()) {
        _launched = true;
    }
}

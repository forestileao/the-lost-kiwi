//
// Created by forestileao on 08/08/2021.
//

#ifndef SPAWNER_H
#define SPAWNER_H

#include <vector>

namespace Stages
{
    class Spawner
    {
    private:
        std::vector<sf::Vector2f> spawnPositions;
        const int maxEnemies = 15;
        const int maxObstacles = 10;
        int enemiesSpawned;
        int obstaclesSpawned;
        bool didSpawnedObstacles;
        Stage *pStage;
    public:
        Spawner(Stage* pStage);
        ~Spawner();
        void addSpawnPosition(sf::Vector2f spawnPos);
        void spawnObstacles();
        void spawnEnemy();
        void decrementEnemiesCount();
        void setEnemiesCount(unsigned int num);
        void setObstaclesCount(unsigned int num);
        bool didObstaclesSpawned() const;
    };
}

#endif //SPAWNER_H

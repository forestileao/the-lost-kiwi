//
// Created by forestileao on 08/08/2021.
//

#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include <vector>

namespace Stages
{
    class EnemySpawner
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
        EnemySpawner(Stage* pStage);
        ~EnemySpawner();
        void addSpawnPosition(sf::Vector2f spawnPos);
        void spawnObstacles();
        void spawnEnemy();
        void decrementEnemiesCount();
        void setEnemiesCount(unsigned int num);
        void setObstaclesCount(unsigned int num);
        bool didObstaclesSpawned() const;
    };
}

#endif //ENEMYSPAWNER_H

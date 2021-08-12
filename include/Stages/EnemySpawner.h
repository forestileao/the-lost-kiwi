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
        int enemiesSpawned;
        Stage *pStage;
    public:
        EnemySpawner(Stage* pStage);
        ~EnemySpawner();
        void addSpawnPosition(sf::Vector2f spawnPos);
        void spawnEnemy();
        void decrementEnemiesCount();
    };
}

#endif //ENEMYSPAWNER_H

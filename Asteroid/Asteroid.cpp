#include "raylib.h"
#include <vector>
#include <cstdlib> 
#include <ctime> 

class Player {
public:
    Vector2 position;
    Texture2D texture;
    float speed;
    int health;

    Player(Vector2 pos, Texture2D tex, float spd) : position(pos), texture(tex), speed(spd), health(100) {}

    void Update() {
        if (IsKeyDown(KEY_RIGHT)) position.x += speed;
        if (IsKeyDown(KEY_LEFT)) position.x -= speed;
        if (IsKeyDown(KEY_UP)) position.y -= speed;
        if (IsKeyDown(KEY_DOWN)) position.y += speed;

        // Manter o jogador dentro da tela
        if (position.x < 0) position.x = 0;
        if (position.x > GetScreenWidth() - texture.width) position.x = GetScreenWidth() - texture.width;
        if (position.y < 0) position.y = 0;
        if (position.y > GetScreenHeight() - texture.height) position.y = GetScreenHeight() - texture.height;
    }

    void Draw() {
        DrawTexture(texture, position.x, position.y, WHITE);
    }

    Rectangle GetBoundingBox() const {
        return Rectangle{ position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height) };
    }
};

class Asteroid {
public:
    Vector2 position;
    Texture2D texture;
    float speed;

    Asteroid(Vector2 pos, Texture2D tex, float spd) : position(pos), texture(tex), speed(spd) {}

    void Update() {
        position.y += speed;
        if (position.y > GetScreenHeight()) {
            position.y = -texture.height;
            position.x = static_cast<float>(rand() % (GetScreenWidth() - texture.width));
        }
    }

    void Draw() {
        DrawTexture(texture, position.x, position.y, WHITE);
    }

    Rectangle GetBoundingBox() const {
        return Rectangle{ position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height) };
    }
};

class Point {
public:
    Vector2 position;
    Texture2D texture;

    Point(Vector2 pos, Texture2D tex) : position(pos), texture(tex) {}

    void Draw() {
        DrawTexture(texture, position.x, position.y, WHITE);
    }

    Rectangle GetBoundingBox() const {
        return Rectangle{ position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height) };
    }

    void Reposition() {
        position.x = static_cast<float>(rand() % (GetScreenWidth() - texture.width));
        position.y = static_cast<float>(rand() % (GetScreenHeight() - texture.height));
    }
};

class Game {
public:
    int score;
    Player player;
    int enemyCount;
    std::vector<Asteroid> asteroids;
    std::vector<Point> points;

    Game(Player plyr, std::vector<Asteroid> aster, std::vector<Point> pts) :
        player(plyr), asteroids(aster), points(pts), score(0), enemyCount(static_cast<int>(aster.size())) {}

    void Update() {
        player.Update();
        for (auto &asteroid : asteroids) asteroid.Update();
        CheckCollisions();
    }

    void Draw() {
        player.Draw();
        for (auto &asteroid : asteroids) asteroid.Draw();
        for (auto &point : points) point.Draw();

        DrawText(TextFormat("Enemies: %i", enemyCount), 10, 10, 20, BLACK);
        DrawText(TextFormat("Grogu: %i%%", player.health), 10, 40, 20, BLACK);
        DrawText(TextFormat("Score: %i", score), 10, 70, 20, BLACK);
    }

private:
    void CheckCollisions() {
        for (auto &asteroid : asteroids) {
            if (CheckCollisionRecs(player.GetBoundingBox(), asteroid.GetBoundingBox())) {
                player.health -= 10; // Perde vida ao colidir com asteroide
                asteroid.position.y = -asteroid.texture.height; // Reposicionar asteroide
                if (player.health <= 0) {
                    // Resetar o jogo ou qualquer lógica de game over
                    player.health = 100; // Temporário: resetar a vida do jogador
                    score = 0; // Temporário: resetar o score
                }
            }
        }

        for (auto &point : points) {
            if (CheckCollisionRecs(player.GetBoundingBox(), point.GetBoundingBox())) {
                score += 10; // Ganha pontos ao pegar um item
                point.Reposition(); // Reposicionar o ponto
            }
        }
    }
};

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Space Game");
    SetTargetFPS(60);

    // Carregar texturas
    Texture2D playerTexture = LoadTexture("C:/raylib/raylib/src/Asteroid/player.png");
    Texture2D asteroidTexture = LoadTexture("C:/raylib/raylib/src/Asteroid/enemy.png");
    Texture2D pointTexture = LoadTexture("C:/raylib/raylib/src/Asteroid/Coin_Score.png");

    // Criar jogador
    Player player({screenWidth / 2.0f, screenHeight - 50}, playerTexture, 5.0f);

    // Criar asteroides
    std::vector<Asteroid> asteroids;
    for (int i = 0; i < 5; i++) {
        float posX = static_cast<float>(rand() % (screenWidth - asteroidTexture.width));
        float posY = static_cast<float>(-(rand() % screenHeight));
        asteroids.emplace_back(Vector2{posX, posY}, asteroidTexture, 3.0f);
    }

    // Criar pontos
    std::vector<Point> points;
    for (int i = 0; i < 3; i++) {
        float posX = static_cast<float>(rand() % (screenWidth - pointTexture.width));
        float posY = static_cast<float>(rand() % (screenHeight - pointTexture.height));
        points.emplace_back(Vector2{posX, posY}, pointTexture);
    }

    Game game(player, asteroids, points);

    while (!WindowShouldClose()) {
        // Atualizar o jogo
        game.Update();

        // Desenhar o jogo
        BeginDrawing();
        ClearBackground(RAYWHITE);

        game.Draw();

        EndDrawing();
    }

    // Descarregar texturas
    UnloadTexture(playerTexture);
    UnloadTexture(asteroidTexture);
    UnloadTexture(pointTexture);

    CloseWindow();
    return 0;
}

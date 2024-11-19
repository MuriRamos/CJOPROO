#include "raylib.h"
#include <vector>

// Estrutura da plataforma
struct Platform 
{
    float x, y;
    bool active;
    Texture2D texture;
    float scale;
};

// Estrutura do jogador
struct Player 
{
    float x, y;
    float width, height;
    float speedY;
    Texture2D texture;
    float scale;
};

// Estrutura da parede
struct Wall 
{
    float x, y;
    float width, height;
    Texture2D texture;
    float scale;
};

enum GameState { START_SCREEN, GAMEPLAY, GAME_OVER };

int main() 
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Jumper_Joe");

    // Espaço para alocação de Texturas do jogo
    Texture2D playerTexture = LoadTexture("C:/raylib/raylib/src/Jumper_Joe/Joe.png");
    Texture2D platformTexture = LoadTexture("C:/raylib/raylib/src/Jumper_Joe/Plataform.png");
    Texture2D backgroundTexture = LoadTexture("C:/raylib/raylib/src/Jumper_Joe/Background_View.png");
    Texture2D wallTexture = LoadTexture("C:/raylib/raylib/src/Jumper_Joe/Castle_Walls.png");
    Texture2D startScreenTexture = LoadTexture("C:/raylib/raylib/src/Jumper_Joe/Jumper_Joe_Start.png");
    Texture2D gameOverScreenTexture = LoadTexture("C:/raylib/raylib/src/Jumper_Joe/Game_Over.png");

    Player player = { screenWidth / 2.0f - 25, screenHeight / 2.0f - 25, 50, 50, 0, playerTexture, 1.0f };
    float gravity = 0.2f;
    float jumpStrength = 10.0f;

    std::vector<Platform> platforms;
    platforms.push_back({ screenWidth / 2.0f - 50, screenHeight - 30, true, platformTexture, 1.0f });

    //Colisão das paredes
    std::vector<Wall> walls;
    walls.push_back({ 0, 0, 50, screenHeight, wallTexture, 1.0f });
    walls.push_back({ screenWidth - 50, 0, 50, screenHeight, wallTexture, 1.0f });

    int score = 0;
    GameState gameState = START_SCREEN;
    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
       //Tela de inicio
       if (gameState == START_SCREEN) 
       {
          if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
          {
             gameState = GAMEPLAY;
             score = 0;
             player.x = screenWidth / 2.0f - 25;
             player.y = screenHeight / 2.0f - 25;
             player.speedY = 0;
             platforms.clear();
             platforms.push_back({ screenWidth / 2.0f - 50, screenHeight - 30, true, platformTexture, 1.0f });
          }
             BeginDrawing();
             ClearBackground(RAYWHITE);
             DrawTexture(startScreenTexture, 0, 0, WHITE);
             DrawText(TextFormat("Score: %i", score), 10, 10, 20, DARKGRAY);
             EndDrawing();
       }
       // Jogabilidade
       else if (gameState == GAMEPLAY) 
       {
          player.speedY += gravity;
          player.y += player.speedY;

          // Comandos do Personagem 
          if (IsKeyDown(KEY_LEFT) && player.x > 50) player.x -= 5;
          if (IsKeyDown(KEY_RIGHT) && player.x < screenWidth - player.width - 50) player.x += 5;
          if (IsKeyDown(KEY_UP)) player.y -= 15;

          // Colisões de plataformas
          for (Platform& platform : platforms) 
          {
             if (platform.active &&
               player.speedY > 0 &&
               player.x + player.width > platform.x &&
               player.x < platform.x + platform.texture.width * platform.scale &&
               player.y + player.height > platform.y &&
               player.y + player.height < platform.y + platform.texture.height * platform.scale) 
               {
                  player.speedY = -jumpStrength;
                  platform.active = false;
                  score++;
                  // Gerar Plataformas após colisões
                  platforms.push_back({ (float)(GetRandomValue(50, screenWidth - platform.texture.width * platform.scale - 50)),
                                          (float)(GetRandomValue(0, screenHeight / 2)), true, platformTexture, 1.0f });
               }
          }

          
          if (player.y > screenHeight) 
          {
             gameState = GAME_OVER;
          }

          // Construção do jogo
          BeginDrawing();
          ClearBackground(RAYWHITE);

          DrawTexture(backgroundTexture, 0, 0, WHITE);
          DrawText(TextFormat("Score: %i", score), 10, 10, 20, DARKGRAY);

          // Construção do Personagem
          DrawTextureEx(player.texture, (Vector2){player.x, player.y}, 0.0f, player.scale, WHITE);

          // Construção da Plataforma 
          for (const Platform& platform : platforms) 
          {
             if (platform.active) 
             {
                DrawTextureEx(platform.texture, (Vector2){platform.x, platform.y}, 0.0f, platform.scale, WHITE);
             }
          }

          // Construção das Paredes
          for (const Wall& wall : walls) 
          {
             DrawTextureEx(wall.texture, (Vector2){wall.x, wall.y}, 0.0f, wall.scale, WHITE);
          }

          EndDrawing();
       }

          // Tela de Game_Over
          else if (gameState == GAME_OVER) 
          {
             if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
             {
                gameState = START_SCREEN;
             }

             BeginDrawing();
             ClearBackground(RAYWHITE);
             DrawTexture(gameOverScreenTexture, 0, 0, WHITE);
             DrawText(TextFormat("Final Score: %i", score), 10, 10, 20, DARKGRAY);
             EndDrawing();
          }
    }

    //Carregar Texturas
    UnloadTexture(playerTexture);
    UnloadTexture(platformTexture);
    UnloadTexture(backgroundTexture);
    UnloadTexture(wallTexture);
    UnloadTexture(startScreenTexture);
    UnloadTexture(gameOverScreenTexture);

    CloseWindow();
    return 0;
}

#include "raylib.h"
#include <stdbool.h>

void menu(void);
void initGame(void);

int main()
{
    menu();
}
void menu(void)
{
    int screen_width = 900, screen_hight = 600;

    InitWindow(screen_width, screen_hight, "Run");
    InitAudioDevice();
    SetTargetFPS(60);

    // Definir a posição e tamanho do botão "Play"
    Rectangle playButton = {screen_width / 2 - 95, screen_hight / 2 - 100, 200, 50};

    // Definir a posição e tamanho do botão "Sair"
    Rectangle exitButton = {screen_width / 2 - 80, screen_hight / 2, 200, 50};

    // Ligar ou desligar a musica
    Rectangle musicButton = {screen_width / 2 - 40, screen_hight / 2 + 100, 50, 50};

    // Background do menu;
    Rectangle menu = {0, 0, screen_width, screen_hight};

    Texture2D texturaMenu = LoadTexture("textures/menu.png");
    Texture2D texturaPlay = LoadTexture("textures/button-play.png");
    Texture2D texturaExit = LoadTexture("textures/button-exit.png");
    Texture2D texturaSoundOn = LoadTexture("textures/sound-on.png");
    Texture2D texturaSoundOff = LoadTexture("textures/sound-off.png");
    Sound open = LoadSound("sounds/open.mp3");
    SetSoundVolume(open, 5);

    int musica = 0, screenView = 0;

    while (!WindowShouldClose())
    {
        if (musica == 0)
        {
            PlaySound(open);
            musica = 1;
        }
        if (CheckCollisionPointRec(GetMousePosition(), playButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            screenView = 1;
            initGame();
        }
        if (CheckCollisionPointRec(GetMousePosition(), exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            CloseWindow();
            CloseAudioDevice();
        }
        if (CheckCollisionPointRec(GetMousePosition(), musicButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (musica == 1)
            {
                PauseSound(open);
                musica = 2;
            }
            else if (musica == 2)
            {
                ResumeSound(open);
                musica = 1;
            }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (screenView == 0)
        {
            DrawTexture(texturaMenu, menu.x, menu.y, WHITE);
            DrawTexture(texturaPlay, playButton.x, playButton.y, WHITE);
            DrawTexture(texturaExit, exitButton.x, exitButton.y, WHITE);

            if (musica == 1)
                DrawTexture(texturaSoundOn, musicButton.x, musicButton.y, WHITE);

            else
                DrawTexture(texturaSoundOff, musicButton.x, musicButton.y, WHITE);
        }
        EndDrawing();

        if (screenView == 1)
            break;
    }
    CloseWindow();
    CloseAudioDevice();
}

void initGame(void)
{
    CloseWindow();
    int screen_width = 1280, screen_hight = 800;

    InitWindow(screen_width, screen_hight, "Run");
    SetTargetFPS(60);

    Texture2D textureCin = LoadTexture("textures/cin.png");
    Texture2D textureCasa = LoadTexture("textures/casa.png");
    Texture2D texture = LoadTexture("textures/fundo.png");
    Texture2D textureRedbull = LoadTexture("textures/redbull.png");
    Texture2D textureOnda = LoadTexture("textures/onda.png");
    Texture2D texturePlayer1 = LoadTexture("textures/player_1.png");
    Texture2D texturePlayer2 = LoadTexture("textures/player_2.png");
    Texture2D texturePlayer1_2 = LoadTexture("textures/player1_2.png");
    Texture2D texturePlayer2_2 = LoadTexture("textures/player2_2.png");
    Texture2D texturaTelaPerdeu = LoadTexture("textures/perdeu.png");
    Texture2D texturaTelaGanhou = LoadTexture("textures/ganhou.png");
    Sound grito = LoadSound("sounds/grito.mp3");
    
    
    // background

    Rectangle back = {-1000, -180, 13000, 800};

    // rua

    Rectangle rua = {-2000, -312, 13000, 800};

    // posição casa

    Rectangle casa = {-250, 20, 300, 300};

    // lista de lugar onde havera solo para o personagem andar

    Rectangle solo[] = {
        {-1000, 320, 2000, 1},
        {1200, 420, 500, 1},
        {1800, 320, 1000, 1},
        {2900, 220, 1500, 1},
        {3000, 140, 140, 1},
        {4500, 220, 140, 1},
        {4800, 140, 140, 1},
        {5000, 60, 140, 1},
        {5300, 20, 140, 1},
        {5600, -40, 140, 1},
        {6115, 420, 2000, 1},
        {6200, 340, 140, 1},
        {6340, 260, 140, 1},
        {6480, 180, 140, 1},
        {6620, 100, 140, 1},
        {6860, 20, 140, 1},
        {7000, -60, 140, 1},
        {8300, 350, 1000, 1},
        {9450, 400, 400, 1},
        {10000, 320, 2000, 1},

    };

    // lista de lugar onde havera parede

    Rectangle parede[] = {
        {-1000, 321, 2000, 8000},
        {1200, 421, 500, 8000},
        {1800, 321, 1000, 8000},
        {2900, 221, 1500, 8000},
        {3000, 141, 140, 8000},
        {4500, 221, 140, 8000},
        {4800, 141, 140, 8000},
        {5000, 61, 140, 8000},
        {5300, 21, 140, 8000},
        {5600, -40, 140, 8000},
        {6115, 421, 2000, 8000},
        {6200, 341, 140, 8000},
        {6340, 261, 140, 8000},
        {6480, 181, 140, 8000},
        {6620, 101, 140, 8000},
        {6860, 21, 140, 8000},
        {7000, -59, 140, 8000},
        {8300, 351, 1000, 8000},
        {9450, 401, 400, 8000},
        {10000, 321, 2000, 8000},
    };

    // cracha

    Rectangle cracha = {-50, 300, 20, 20};

    // struct da onda
    Rectangle onda = {-2600, -200, 1000, 800};

    // redbull

    Rectangle redbull = {7330, -50, 15, 30};

    // struct onde tem a posição do personagem (x,Y), sua largura e tamanho

    Rectangle player = {100, 270, 50, 50};

    // struct pro cin

    Rectangle cin = {11200, -80, 210, 474};

    bool fim = false, podeEntrar = false, pegar = false, pulo = false;
    float puloSpeed = 10.0f, gravidade = 0.5f, playerPosition, playerspeed = 5, playerspeedonda = 5.5;
    int modoJogo = 1, screenView = 0, parou = 0;

    playerPosition = player.y;
    Camera2D camera = {0};
    camera.target = (Vector2){player.x + 250.0f, playerPosition - 50};
    camera.offset = (Vector2){screen_width / 2.0f, screen_hight / 2.0f};
    camera.zoom = 1;

    while (!WindowShouldClose())
    {

        // verificar se o botao direito foi clicado
        if (IsKeyDown(KEY_RIGHT))
        {
            player.x += playerspeed;
            parou = 0;
        }
        // verificar se o botao esquerdo foi clicado
        if (IsKeyDown(KEY_LEFT))
        {
            player.x -= playerspeed;
            parou = 1;
        }
        // movimento da onda
        onda.x += playerspeedonda;

        // verificar se o botao pular/para cima foi clicado
        if (IsKeyDown(KEY_UP) && !pulo)
        {
            pulo = true;
            puloSpeed = 10.0f;
            gravidade = 0.5f;
        }

        if (pulo)
        {
            player.y -= puloSpeed;
            puloSpeed -= gravidade;

            // detectar colisão com o solo e redefinir pulo
            for (int i = 0; i < 20; i++)
            {
                if (CheckCollisionRecs(player, solo[i]))
                {
                    pulo = false;
                    player.y = solo[i].y - player.height;
                    break;
                }
            }
        }
        else
        {
            // Detectar colisão com o solo e permitir pular novamente
            for (int i = 0; i < 20; i++)
            {
                if (CheckCollisionRecs(player, solo[i]))
                {
                    pulo = false;
                    break;
                }
                else
                {
                    // caso o personagem nao tenha pulado e passo do tamanho do solo e caiu no buraco entao ele so vai cair
                    pulo = true;
                    puloSpeed = 0;
                }
            }
        }

        // detectar colisão com a parede e parar o jogador
        for (int i = 0; i < 20 && fim == false; i++)
        {
            if (CheckCollisionRecs(player, parede[i]))
            {
                playerspeed = 0;
                break;
            }
            else
            {
                playerspeed = 5;
            }
        }

        if (CheckCollisionRecs(player, onda) || player.y > 700)
        {
            PlaySound(grito);
            modoJogo = 1;
            screenView = 1;
        }

        if (CheckCollisionRecs(player, cracha))
        {
            podeEntrar = true;
        }

        if (CheckCollisionRecs(player, cin))
        {
            fim = true;
            if (podeEntrar == true)
            {
                screenView = 1;
                modoJogo = 3;
            }
            else if (podeEntrar == false)
            {
                PlaySound(grito);
                screenView = 1;
                modoJogo = 2;
            }
        }

        // movimentação da camera
        camera.target = (Vector2){player.x + 250, playerPosition - 50};

        BeginDrawing();
            BeginMode2D(camera);
            ClearBackground(WHITE);
            if (screenView == 0)
            {
                DrawRectangle(rua.x, rua.y, rua.width, rua.height, DARKBLUE);
                DrawRectangle(redbull.x, redbull.y, redbull.width, redbull.height, DARKBLUE);
                DrawRectangle(cin.x, cin.y, cin.width, cin.height, DARKGRAY);
                DrawRectangle(casa.x, casa.y, casa.width, casa.height, ORANGE);
                DrawRectangle(onda.x, onda.y, onda.width, onda.height, BLUE);
                DrawRectangle(back.x, back.y, back.width, back.height, WHITE);
                DrawTexture(texture, back.x, back.y, WHITE);
                // desenhar os objetos na tela
                if (podeEntrar == false)
                {
                    if (parou == 0)
                        DrawTexture(texturePlayer1, player.x, player.y, WHITE);
                    else
                        DrawTexture(texturePlayer1_2, player.x, player.y, WHITE);
                }
                else
                {
                    if (parou == 0)
                        DrawTexture(texturePlayer2, player.x, player.y, WHITE);
                    else
                        DrawTexture(texturePlayer2_2, player.x, player.y, WHITE);
                }
                for (int i = 0; i < 20; i++)
                {
                    DrawRectangle(solo[i].x, solo[i].y, solo[i].width, solo[i].height, DARKGREEN);
                    DrawRectangle(parede[i].x, parede[i].y, parede[i].width, parede[i].height, BLACK);
                }
                if (CheckCollisionRecs(player, redbull))
                {
                    pegar = true;
                }
                if (!pegar)
                {
                    DrawTexture(textureRedbull, redbull.x, redbull.y, WHITE);
                }
                else
                {
                    playerspeedonda = 5;
                    playerspeed = 5.33;
                }
                DrawRectangle(cracha.x, cracha.y, cracha.width, cracha.height, RED);
                DrawTexture(textureCasa, casa.x, casa.y, WHITE);
                DrawTexture(textureCin, cin.x, cin.y, WHITE);
                DrawTexture(textureOnda, onda.x, onda.y, WHITE);
            }
            EndMode2D();
            if(modoJogo == 1 && screenView == 1){
                camera.target = (Vector2){0, 0};
                DrawTexture(texturaTelaPerdeu, -40, 0, WHITE);
                if (IsKeyDown(KEY_SPACE))
                {
                    initGame();
                }
            }if(modoJogo == 2 && screenView == 1){
                camera.target = (Vector2){0, 0};
                DrawTexture(texturaTelaPerdeu, -40, 0, WHITE);
                if (IsKeyDown(KEY_SPACE))
                {
                    initGame();
                }
            }if(modoJogo == 3 && screenView == 1){
                camera.target = (Vector2){0, 0};
                DrawTexture(texturaTelaGanhou, -40, 0, WHITE);
            }
            
        EndDrawing();
    }
    CloseWindow();
    CloseAudioDevice();
}

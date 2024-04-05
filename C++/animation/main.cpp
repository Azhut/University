#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.hpp>
#include <time.h>

//----------Класс и прототипы--------------------------------------------------------
# if true

using sf::Texture;
using sf::Image;
using sf::Sprite;

struct Animation
{
    Texture textures[100];
    Sprite  sprites[100];
    char    nameAnim[25];
    int     countCadres;
    int     stateCadre;
};

class Person
{
private:
    Animation animations[15];
    int       countAnimations;

    clock_t lastTime;

    sf::Vector2f position;
    sf::Vector2f scale;

    int nowNumberAnim;

    void GetFormat        (const char str [], char format[]);
    void DeleteFormatInStr(const char str [], char newStr[]);
    int  GetNumberAnim    (const char word[]);

public:
    Person();

    void SetDefaultSprite(const char path[]);

    void AddAnim(const char path[], const char nameState[], int countCadres);
    void Animate(const char name[], float      msBetweenCadres);

    void Move       (float x, float y);
    void SetScale   (float x, float y);
    void SetPosition(float x, float y);
};

#endif
//---------------Конец---------------------------------------------------------------

sf::RenderWindow window(sf::VideoMode(800, 600), "Animation");

int main()
{
    Person person;

    person.AddAnim("чебурашка кадры\\frame.png", "fly", 20);
    person.SetScale   (0.3, 0.3);
    person.SetPosition(0.0, 0.0);

    while (window.isOpen())
    {
        window.clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        person.Animate("fly", 50);

        window.display();
    }
}

//----------Реализация Функций-------------------------------------------------------
#if true

void Person::GetFormat(const char str[], char format[])
{
    int sizeStr = strlen(str);
    bool isFormat = false;
    for (int i = 0, j = 0; i < sizeStr; i++)
    {
        if (str[i] == '.') isFormat = true;

        if (isFormat)
        {
            format[j] = str[i];
            j++;
        }
    }
}

void Person::DeleteFormatInStr(const char str[], char newStr[])
{
    int sizeStr = strlen(str);
    for (int i = 0; i < sizeStr; i++)
    {
        if (str[i] == '.') break;

        newStr[i] = str[i];
    }
}

int Person::GetNumberAnim(const char word[])
{
    int numberAnimation = -1;
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(word, animations[i].nameAnim) == 0)
        {
            numberAnimation = i;
            break;
        }
    }

    return numberAnimation;
}

Person::Person() : countAnimations(1)
{
    scale = { 1.0, 1.0 };

    for (int i = 0; i < 10; i++)
    {
        strcpy(animations[i].nameAnim, "");
    }

    lastTime = 0;
}

void Person::AddAnim(const char path[], const char nameState[], int countCadres)
{
    for (int i = 0; i < countCadres; i++)
    {
        char fullPath[50] = "";
        char format[10] = "";
        char pathNoFormat[50] = "";

        GetFormat(path, format);
        DeleteFormatInStr(path, pathNoFormat);

        strcat(fullPath, pathNoFormat);

        //В конце прибавляем номер анимации начиная с нуля
        int sizePath = strlen(fullPath);
        char num[4] = "";
        itoa(i, num, 10);

        strcat(fullPath, num);

        //В конец приписываем формат файла
        strcat(fullPath, format);

        //Загрузка спрайта
        animations[countAnimations].textures[i].loadFromFile(fullPath);
        animations[countAnimations].sprites[i].setTexture(animations[countAnimations].textures[i]);
    }

    strcat(animations[countAnimations].nameAnim, nameState);
    animations[countAnimations].countCadres = countCadres;
    animations[countAnimations].stateCadre = 0;

    countAnimations++;
}

void Person::Animate(const char name[], float msBetweenCadres)
{
    int nowNumberAnim = GetNumberAnim(name);

    if (nowNumberAnim == -1) return;

    clock_t secondsInGame = clock();

    int stateCadre = animations[nowNumberAnim].stateCadre;

    if (stateCadre == animations[nowNumberAnim].countCadres)
    {
        animations[nowNumberAnim].stateCadre = 0;
        stateCadre                           = 0;
    }

    animations[nowNumberAnim].sprites[stateCadre].setPosition(position);
    animations[nowNumberAnim].sprites[stateCadre].setScale(scale);

    if (secondsInGame - lastTime >= msBetweenCadres)
    {
        lastTime = clock();

        animations[nowNumberAnim].stateCadre++;
    }

    window.draw(animations[nowNumberAnim].sprites[stateCadre]);
}

void Person::Move(float x, float y)
{
    position = { x, y };

    animations[nowNumberAnim].sprites[animations[nowNumberAnim].stateCadre].setPosition(position);
}

void Person::SetScale(float x, float y)
{
    scale = { x, y };

    animations[nowNumberAnim].sprites[animations[nowNumberAnim].stateCadre].setScale(scale);
}

void Person::SetPosition(float x, float y)
{
    position = { x, y };

    animations[nowNumberAnim].sprites[animations[nowNumberAnim].stateCadre].setPosition(position);
}

void Person::SetDefaultSprite(const char path[])
{
    animations[0].textures[0].loadFromFile(path);
    animations[0].sprites[0].setTexture(animations[0].textures[0]);
}

#endif
//---------------Конец---------------------------------------------------------------


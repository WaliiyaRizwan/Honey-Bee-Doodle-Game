//the-bee-game
//By Waliiya Rizwan

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<sstream>
#include<time.h>

using namespace sf;
using namespace std;
class Doodle{
    private:
    struct Point{int x, y;};
    int score;
    public:
        Doodle(){
            score = 0;
        }
        void Game(){
        srand(time(0));
        RenderWindow app(VideoMode (1000,667), "Doodle Game");
        app.setFramerateLimit(60);

        SoundBuffer b;
        if (!b.loadFromFile("canary.wav")){
            cout<<"Sound Error"<<endl;
        }
        Sound s;
        s.setBuffer(b);
        s.play();
        s.setLoop(true);

        Texture t1, t2, t3;

        t1.loadFromFile("images/background.jpg");
        t2.loadFromFile("images/platform (3).png");
        t3.loadFromFile("images/doodle.png");

        Sprite sBackground(t1), sPlat(t2), sPers(t3);

        Point Plat[10];
        for(int i=0; i<10; i++){

            Plat[i].x = rand()% 950;
            Plat[i].y = rand()% 600;
        }

        int x=100, y=100, h=200;
        float dx=0, dy=0;

        while(app.isOpen()){
            Event e;
            while(app.pollEvent(e)){
                if (e.type == Event::Closed)
                    app.close();
            }

            if(Keyboard::isKeyPressed(Keyboard::Right))
                x+=4;
             if(Keyboard::isKeyPressed(Keyboard::Left))
                x-=4;
            dy+=0.2;
            y+=dy;
            if(y>600){
                dy=-10;
            }
            if(y<h){
                for(int i=0; i<10; i++){

                    y=h;
                    Plat[i].y =Plat[i].y-dy;
                    if(Plat[i].y>600){
                            Plat[i].y =0;
                            Plat[i].x = rand()%950;


                    }
                }
            }

            for (int i=0; i<10; i++){

                if((x+50>Plat[i].x) && (x+20<Plat[i].x+68) && (y+70>Plat[i].y) && (y+70<Plat[i].y+45) && (dy>0))
                {
                     dy=-10;
                     score++;
                }
            }
            sPers.setPosition(x,y);
            app.draw(sBackground);
            app.draw(sPers);

            for(int i=0; i<10; i++){
                sPlat.setPosition(Plat[i].x, Plat[i].y);
                app.draw(sPlat);
            }
            Font arial;
            arial.loadFromFile("arial.ttf");
            ostringstream ssScore;
            ssScore<<"Score: "<<score;
            Text lblScore;
            lblScore.setCharacterSize(30);
            lblScore.setPosition(10,10);
            lblScore.setFont(arial);
            lblScore.setColor(Color::Blue);
            lblScore.setString(ssScore.str());
            app.draw(lblScore);

            app.display();
        }
        s.stop();
        }
};
int main(){

        Doodle d;
        d.Game();

        return 0;
}


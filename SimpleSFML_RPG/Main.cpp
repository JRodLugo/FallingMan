//goal is to have an image bouncing up and down within the window
//new goal have multiple images falling to create a screan saver then upload it to GIT hub
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

// object for the ball within the program
class GameEnt {
    private:
        // the shape iself
        CircleShape circle();
        // how fast the ball will be dragged down
        float gravity;
        
    public:
        //constructor
        GameEnt() {

        }
        //destructor
        ~GameEnt() {

        }
        // balls color
        int circleColor() {

        }
};


//main function
int main(){
   //varibles for the circles position
    float PosX, PosY;
    PosX = 150.f;
    PosY = -5.f;
    
    //creates the window within the code and specifes the size and the name
    RenderWindow window(VideoMode(400, 400), "Falling Man");
    

    Texture texture;
    texture.loadFromFile("./Assets/FallingMan.png");
    Sprite sprite;
    sprite.setTexture(texture);
    
    sprite.setPosition(PosX, PosY);

    //controls the frame rate within the program
    Clock clock;
    window.setFramerateLimit(60);
    

    //application loop
    while (window.isOpen()){
        //for computing the frame rate
        float currentTime = clock.restart().asSeconds();
        float fps = 1.0f / (currentTime);
        cout << "FPS: " << fps << endl;

        Event event;

        while (window.pollEvent(event)){

            if (event.type == Event::Closed)
                window.close();

            
        }

        //test to see if the ball will fall
        window.clear();
        PosX = PosX - 0.035;
        PosY = PosY + 0.4;
        window.draw(sprite);
        for (int i = 0; i < 50; i ++) {
            if (PosX > 400) {
                PosX *= -1;
            }
            else if (PosX < 0) {
                PosX *= 1;
            }
            if (PosY > 400) {
                PosY *= -1;
            }
            else if (PosY < 0) {
                PosY *= 1;
            }
        }
        sprite.setPosition(PosX, PosY);
        window.display();
    }

    return 0;
}
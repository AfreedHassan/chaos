#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

static const int windowWidth = 1600;
static const int windowHeight = 900;

int main() {
  try {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}),
                            "Chaos");
    glEnable(GL_TEXTURE_2D);

    // Create a graphical text to display
    sf::Font font;
    if (!font.openFromFile("assets/NewYork.ttf")) {
      throw ::std::runtime_error("Failed to load font!");
    }
    sf::Text text(font, "Hello SFML", 50);
    text.setFillColor(sf::Color(255, 0, 0));

    sf::Texture texture;
    sf::CircleShape circle(50.f, 100);
    circle.setFillColor(sf::Color(100, 100, 100));
    circle.setTexture(&texture);

    circle.setPosition({500.f, 500.f});

    // Start the game loop
    bool running = true;
    while (running) {
      // Process events
      while (const std::optional event = window.pollEvent()) {
        // Close window: exit
        if (event->is<sf::Event::Closed>()) {
          running = false;
        } else if (const auto *resized = event->getIf<sf::Event::Resized>()) {
          // adjust the viewport when the window is resized
          glViewport(0, 0, resized->size.x, resized->size.y);
        }
      }

      // Clear screen
      window.clear();

      // Draw the string
      window.draw(text);
      window.draw(circle);

      // Update the window
      window.display();
    }
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << '\n';
  }
}

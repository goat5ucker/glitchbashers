#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

#include "../libs/tinyxml2.cpp"     // да, это очень плохое решение - таким образом подключать библиотеки.
                                    // но у меня не хватило мозговых клеток в моменте, чтобы сделать это
                                    // правильным образом. оно работает и меня волнует только тем, что это
                                    // наполовину прилично и немного нелегально. жесть.
#include "settings.hpp"
#include "level.hpp"
#include "player.hpp"


int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "\\\\glitchbashers!\\\\");
    if (!ImGui::SFML::Init(window))
        return -1;

    sf::Clock clock;
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event);

            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        ImGui::SFML::Update(window, clock.restart());
        ImGui::Begin("you shouldn't be here");
        ImGui::Button("nuke all files on your system");
        ImGui::End();

        ImGui::Begin("what the -");
        ImGui::Button("no, really, what the -");
        ImGui::End();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}

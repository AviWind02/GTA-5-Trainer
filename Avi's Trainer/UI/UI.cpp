#include "../util/common.h"


namespace base::GUI
{

    void text(const std::string& text, const Color& color, const Rect& rect)
    {
        HUD::SET_TEXT_CENTRE(rect.center);
        HUD::SET_TEXT_COLOUR(color.r, color.g, color.b, color.a);
        HUD::SET_TEXT_FONT(color.f);
        HUD::SET_TEXT_SCALE(rect.size.x, rect.size.y);
        HUD::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
        HUD::SET_TEXT_EDGE(1, 0, 0, 0, 0);
        HUD::SET_TEXT_OUTLINE();
        HUD::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
        HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(const_cast<char*>(text.c_str()));
        HUD::END_TEXT_COMMAND_DISPLAY_TEXT(rect.pos, NULL);
    }


    void DrawRectangle(const Vector2& pos, float width, float height, const Color& color)
    {
        // Get the aspect ratio of the game's resolution.
        const float aspectRatio = GRAPHICS::GET_ASPECT_RATIO(false);

        // Determine the scale based on the aspect ratio.
        const float scale = (aspectRatio >= 1.7777f) ? 1080.0f : 1920.0f;

        // Calculate the screen coordinates of the rectangle.
        const float x = pos.x * scale / aspectRatio;
        const float y = pos.y * scale;
        const float w = width * scale / aspectRatio;
        const float h = height * scale;

        // Draw the rectangle using the DRAW_RECT native function.
        GRAPHICS::DRAW_RECT({ x, y }, w, h, color.r, color.g, color.b, color.a, true);
    }

    // Define variables for the background position, size, and color.
    Vector2 MENU_POS = { 0.5f, 0.5f };
    float MENU_WIDTH = 0.6f;
    float MENU_HEIGHT = 0.8f;
    Color MENU_COLOR = { 0, 0, 0, 200, 0 };


    // Function to draw the menu background using the defined variables.
    void DrawMenuBackground()
    {
        DrawRectangle(MENU_POS, MENU_WIDTH, MENU_HEIGHT, MENU_COLOR);
    }


    struct Option
    {
        std::string text;
        bool isSelected = false;
    };

    // Define a vector to store the options.
    std::vector<Option> options;

    // Function to add an option to the list.
    void AddOption(const std::string& text)
    {
        options.push_back({ text, false });
    }


    const float TEXT_HEIGHT = 0.035f;
    const Color SELECTED_COLOR = { 255, 255, 255, 255 };

    // Function to draw the option list.
    void DrawOptionList(const Vector2& pos, float width, float height, int selectedOption)
    {
        // Calculate the position and size of the rectangle.
        const Rect rect = { pos, { width, height }, true };

        // Calculate the maximum number of options to display based on the size of the rectangle.
        const int maxOptions = static_cast<int>(rect.size.y / TEXT_HEIGHT);

        // Calculate the total number of options and the number of options to display.
        const int numOptions = static_cast<int>(options.size());
        const int displayOptions = std::min(numOptions, maxOptions);

        // Calculate the current scroll offset based on the selected option.
        const int scrollOffset = std::max(0, std::min(selectedOption - (maxOptions - 1), numOptions - maxOptions));

        // Draw the background rectangle.
        DrawRectangle(rect.pos, rect.size.x, rect.size.y, MENU_COLOR);

        // Draw the options inside the rectangle.
        for (int i = 0; i < displayOptions; i++)
        {
            const int optionIndex = i + scrollOffset;

            // Calculate the position of the current option.
            const Vector2 optionPos = { rect.pos.x, rect.pos.y + (i * TEXT_HEIGHT) };

            // Determine if the current option is selected.
            const bool isSelected = (optionIndex == selectedOption);

            // Draw the option text in the appropriate color.
            const Color textColor = isSelected ? SELECTED_COLOR : MENU_COLOR;
            text(options[optionIndex].text, textColor, { optionPos, { rect.size.x, TEXT_HEIGHT }, true });
        }
    }

    // Function to handle scrolling the option list.
    void ScrollOptionList(int amount)
    {
        // Calculate the total number of options and the maximum number of options to display.
        const int numOptions = static_cast<int>(options.size());
        const int maxOptions = static_cast<int>(MENU_HEIGHT / TEXT_HEIGHT);

        // Update the selected option and clamp it to the valid range.
        const int selectedOption = std::clamp(options[selectedOption].isSelected + amount, 0, numOptions - 1);

        // Redraw the option list with the updated selection.
        DrawOptionList(MENU_POS, MENU_WIDTH, MENU_HEIGHT, selectedOption);
    }

    bool IsKeyDown(int key)
    {
        return (GetAsyncKeyState(key) & 0x8000) != 0;
    }

    void tick()
    {
        //Draw the background for the script
        DrawMenuBackground();

        // Add some options to the list.
        AddOption("Option 1");
        AddOption("Option 2");
        AddOption("Option 3");
        AddOption("Option 4");
        AddOption("Option 5");
        AddOption("Option 6");
        AddOption("Option 7");
        AddOption("Option 8");
        AddOption("Option 9");
        AddOption("Option 10");

        // Define the position, width, and height of the option list.
        const Vector2 OPTION_POS = { 0.5f, 0.5f };
        const float OPTION_WIDTH = 0.6f;
        const float OPTION_HEIGHT = 0.5f;

        // Set the initial selected option.
        int selectedOption = 0;

        // Draw the option list.
        DrawOptionList(OPTION_POS, OPTION_WIDTH, OPTION_HEIGHT, selectedOption);

        // Handle input to scroll the option list.
        if (IsKeyDown(VK_UP))
        {
            ScrollOptionList(-1);
        }
        else if (IsKeyDown(VK_UP))
        {
            ScrollOptionList(1);
        }

    }

}
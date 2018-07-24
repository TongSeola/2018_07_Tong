#include "Pane.h"

class StatPane : public Pane
{
    public:
        StatPane(int x, int y, int width, int height);
        ~StatPane();

        // virtual void Draw();
        void Draw();
};

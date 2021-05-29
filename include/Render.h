#ifndef RENDER_H
#define RENDER_H
#include "Definition.h"

namespace nes
{
    class Screen : public sf::Drawable
    {
    public:
        void create(u_int32_t w, uint32_t h, float pixel_size, sf::Color color);
        void setPixel(u_long x, u_long y, sf::Color color);

    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        sf::Vector2u screenRES;
        float pixels;
        sf::VertexArray vertices;
    };
};
#endif
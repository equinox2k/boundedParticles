#include "CircleBoundedParticleSystemQuad.h"

using namespace cocos2d;

#ifndef MAXPARTICLES
#define MAXPARTICLES 1000
#endif

CircleBoundedParticleSystemQuad::CircleBoundedParticleSystemQuad()
{
    this->quad = (V3F_C4B_T2F_Quad*)malloc(MAXPARTICLES * sizeof(V3F_C4B_T2F_Quad));
}

CircleBoundedParticleSystemQuad::~CircleBoundedParticleSystemQuad(void)
{
    free(this->quad);
}

//CircleBoundedParticleSystemQuad* CircleBoundedParticleSystemQuad::create(std::vector<Point> polyPoints)
//{
//    CircleBoundedParticleSystemQuad* ret = new CircleBoundedParticleSystemQuad();
//    if (ret && ret->init())
//    {
//        ret->_polyPoints = polyPoints;
//        ret->autorelease();
//    }
//    else
//    {
//        CC_SAFE_DELETE(ret);
//    }
//    return ret;
//}

CircleBoundedParticleSystemQuad * CircleBoundedParticleSystemQuad::create(const std::string& plistFile, Vec2 center, float radius)
{
    CircleBoundedParticleSystemQuad *ret = new CircleBoundedParticleSystemQuad();
    if (ret && ret->initWithFile(plistFile))
    {
        ret->center = center;
        ret->radius = radius;
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return ret;
}

CircleBoundedParticleSystemQuad* CircleBoundedParticleSystemQuad::createWithTotalParticles(int numberOfParticles, Vec2 center, float radius)
{
    CircleBoundedParticleSystemQuad* ret = new CircleBoundedParticleSystemQuad();
    if (ret && ret->initWithTotalParticles(numberOfParticles))
    {
        ret->center = center;
        ret->radius = radius;
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

void
CircleBoundedParticleSystemQuad::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
    if(_particleCount > 0)
    {
        int totalQuads = 0;
        
        for (int i = 0; i < _particleCount; i++) {
            V3F_C4B_T2F_Quad *currentQuad;
            currentQuad = &(_quads[i]);
            
            float x = ((currentQuad->tl.vertices.x + currentQuad->br.vertices.x) / 2.0f) * this->getScale();
            float y = ((currentQuad->tl.vertices.y + currentQuad->br.vertices.y) / 2.0f) * this->getScale();
            
            float dx = this->center.x - x;
            float dy = this->center.y - y;
            
            if(dx*dx+dy*dy<radius*radius){
                memcpy(&quad[totalQuads], currentQuad, sizeof(V3F_C4B_T2F_Quad));
                totalQuads += 1;
                if (totalQuads >= MAXPARTICLES) {
                    break;
                }
            }
        }
        
        if (totalQuads > 0) {
            _quadCommand.init(_globalZOrder, _texture, getGLProgramState(), _blendFunc, quad, totalQuads, transform, flags);
            renderer->addCommand(&_quadCommand);
        }
        
    }
}


#ifndef __sapsaldog__CircleBoundedParticleSystemQuad__
#define __sapsaldog__CircleBoundedParticleSystemQuad__

#include "cocos2d.h"

using namespace cocos2d;

class CircleBoundedParticleSystemQuad : public ParticleSystemQuad
{
public:
    static CircleBoundedParticleSystemQuad* create(const std::string& plistFile, Vec2 center, float radius);
    static CircleBoundedParticleSystemQuad* createWithTotalParticles(int numberOfParticles, Vec2 center, float radius);
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;
protected:
    CircleBoundedParticleSystemQuad();
    virtual ~CircleBoundedParticleSystemQuad();
    Vec2 center;
    float radius;
    V3F_C4B_T2F_Quad *quad;
private:
    CC_DISALLOW_COPY_AND_ASSIGN(CircleBoundedParticleSystemQuad);
};


#endif



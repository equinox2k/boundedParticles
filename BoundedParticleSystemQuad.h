#ifndef __Equinox2k__BoundedParticleSystemQuad__
#define __Equinox2k__BoundedParticleSystemQuad__

#include "cocos2d.h"

using namespace cocos2d;

class BoundedParticleSystemQuad : public ParticleSystemQuad
{
public:
    static BoundedParticleSystemQuad* create(std::vector<Point> polyPoints);
    static BoundedParticleSystemQuad* create(const std::string& plistFile, std::vector<Point> polyPoints);
    static BoundedParticleSystemQuad* createWithTotalParticles(int numberOfParticles, std::vector<Point> polyPoints);
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;
protected:
    BoundedParticleSystemQuad();
    virtual ~BoundedParticleSystemQuad();
    std::vector<Point> _polyPoints;
    V3F_C4B_T2F_Quad *quad;
private:
    CC_DISALLOW_COPY_AND_ASSIGN(BoundedParticleSystemQuad);
};


#endif


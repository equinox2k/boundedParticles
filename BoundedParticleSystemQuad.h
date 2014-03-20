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
    virtual void draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated) override;
protected:
    BoundedParticleSystemQuad(){}
    virtual ~BoundedParticleSystemQuad(){}
    std::vector<Point> _polyPoints;
private:
    CC_DISALLOW_COPY_AND_ASSIGN(BoundedParticleSystemQuad);
};


#endif


#include "BoundedParticleSystemQuad.h"

using namespace cocos2d;

bool PolygonContainsPoint(std::vector<Point> polyPoints, Point point) {
    int i, j, nvert = polyPoints.size();
    bool c = false;
    for(i = 0, j = nvert - 1; i < nvert; j = i++) {
        if(((polyPoints.at(i).y >= point.y) != (polyPoints.at(j).y >= point.y)) && (point.x <= (polyPoints.at(j).x - polyPoints.at(i).x) * (point.y - polyPoints.at(i).y) / (polyPoints.at(j).y - polyPoints.at(i).y) + polyPoints.at(i).x)) {
            c = !c;
        }
    }
    return c;
}

BoundedParticleSystemQuad* BoundedParticleSystemQuad::create(std::vector<Point> polyPoints)
{
    BoundedParticleSystemQuad* ret = new BoundedParticleSystemQuad();
    if (ret && ret->init())
    {
        ret->_polyPoints = polyPoints;
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

BoundedParticleSystemQuad * BoundedParticleSystemQuad::create(const std::string& plistFile, std::vector<Point> polyPoints)
{
    BoundedParticleSystemQuad *ret = new BoundedParticleSystemQuad();
    if (ret && ret->initWithFile(plistFile))
    {
        ret->_polyPoints = polyPoints;
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return ret;
}

BoundedParticleSystemQuad* BoundedParticleSystemQuad::createWithTotalParticles(int numberOfParticles, std::vector<Point> polyPoints)
{
    BoundedParticleSystemQuad* ret = new BoundedParticleSystemQuad();
    if (ret && ret->initWithTotalParticles(numberOfParticles))
    {
        ret->_polyPoints = polyPoints;
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

void BoundedParticleSystemQuad::draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated)
{
    CCASSERT( _particleIdx == _particleCount, "Abnormal error in particle quad");

    if(_particleIdx > 0)
    {
        
        V3F_C4B_T2F_Quad *quad;
        quad = (V3F_C4B_T2F_Quad*)malloc(_particleIdx * sizeof(V3F_C4B_T2F_Quad));
        
        int totalQuads = 0;
        for (int i = 0; i < _particleIdx; i++) {
            V3F_C4B_T2F_Quad *currentQuad;
            currentQuad = &(_quads[i]);
            
            float x = ((currentQuad->tl.vertices.x + currentQuad->br.vertices.x) / 2.0f) * this->getScale();
            float y = ((currentQuad->tl.vertices.y + currentQuad->br.vertices.y) / 2.0f) * this->getScale();
            bool create = PolygonContainsPoint(_polyPoints, Point(x + this->getPositionX(), y + this->getPositionY()));
            if (create) {
                memcpy(&quad[totalQuads], currentQuad, sizeof(V3F_C4B_T2F_Quad));
                totalQuads += 1;
            }
        }
        
        if (totalQuads > 0) {
            _quadCommand.init(_globalZOrder, _texture->getName(), _shaderProgram, _blendFunc, quad, totalQuads, transform);
            renderer->addCommand(&_quadCommand);
        }
    }
}

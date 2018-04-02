Bounded Particles
=================

Cocos2d-x V3 bounded quad particle system is a way of masking particles so the do not exit a given shape and thus creates a masking effect.

There are two ways to mask your particles.


Example of use...


1. Polygon masking

    std::vector<Point> polyPoints;
    polyPoints.push_back(Point(100.0f, 100.0f));
    polyPoints.push_back(Point(200.0f, 100.0f));
    polyPoints.push_back(Point(200.0f, 200.0f));
    polyPoints.push_back(Point(100.0f, 200.0f));

    auto particle = BoundedParticleSystemQuad::create("particles/myParticle.plist", polyPoints);
    particle->setPosition(Point(150.0f, 100.0f));
    this->addChild(particle);


2. Circular masking

    Vec2 center = Vec2(0, 0);
    float radius = 300;

    auto particle = CircleBoundedParticleSystemQuad::create("res/particle.plist", center, radius);
    particle->setPosition(center);
    this->addChild(particle);

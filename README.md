Bounded Particles
=================

Cocos2d-x V3 bounded quad particle system is a way of masking particles so the do not exit a given shape and thus creates a masking effect.

Example of use...

    std::vector<Point> polyPoints;
    polyPoints.push_back(Point(100.0f, 100.0f));
    polyPoints.push_back(Point(200.0f, 100.0f));
    polyPoints.push_back(Point(200.0f, 200.0f));
    polyPoints.push_back(Point(100.0f, 200.0f));

    auto particle = BoundedParticleSystemQuad::create("particles/myParticle.plist", polyPoints);
    particle->setPosition(Point(150.0f, 100.0f));
    this->addChild(particle);



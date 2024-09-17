#include <iostream>

class Plane {
private:
  std::string plane;
  std::string body;
  std::string engine;

public:
  Plane(std::string palneType) : plane(palneType) {}
  void setEngine(std::string engine) { this->engine = engine; }
  void setBody(std::string body) { this->body = body; }
  std::string getEngine() { return engine; }
  std::string getBody() { return body; }
  void show() {
    std::cout << "Plane Type: " << plane << std::endl;
    std::cout << "Body: " << body << std::endl;
    std::cout << "Engine: " << engine << std::endl;
  }
};

class PlaneBuilder {
protected:
  Plane *_plane;

public:
  virtual void getPartsDone() = 0;
  virtual void buildBody() = 0;
  virtual void buildEngine() = 0;
  Plane *getPlane() { return _plane; }
};

class PropellerBuilder : public PlaneBuilder {
public:
  void getPartsDone() { _plane = new Plane("Propeller plane"); }
  void buildBody() { _plane->setEngine("Propeller Engine"); }
  void buildEngine() { _plane->setBody("Propeller Body"); }
};

class JetBuilder : public PlaneBuilder {
public:
  void getPartsDone() { _plane = new Plane("Jet plane"); }
  void buildBody() { _plane->setEngine("Jet Engine"); }
  void buildEngine() { _plane->setBody("Jet Body"); }
};

class Director {
 

public:
  Plane *createPlane(PlaneBuilder *builder) {
    builder->getPartsDone();
    builder->buildBody();
    builder->buildEngine();
    return builder->getPlane();
  }
};

int main() {
  Director dir;
  JetBuilder jb;
  PropellerBuilder pb;
  Plane *jet = dir.createPlane(&jb);
  Plane *pro = dir.createPlane(&pb);
  jet->show();
  pro->show();
  delete jet;
  delete pro;
  return 0;
}

// C++ code
#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <vector>

// C++ code
#include <emscripten/bind.h>
#include <vector>

int area(int width, int height) { return width * height; }

class MyClass {
public:
  MyClass(int x, std::string y) : x(x), y(y) {}

  void incrementX() { ++x; }

  int getX() const { return x; }
  void setX(int x_) { x = x_; }

  static std::string getStringFromInstance(const MyClass &instance) {
    return instance.y;
  }

private:
  int x;
  std::string y;
};

// Binding code
EMSCRIPTEN_BINDINGS(my_class_example) {
  class_<MyClass>("MyClass")
      .constructor<int, std::string>()
      .function("incrementX", &MyClass::incrementX)
      .property("x", &MyClass::getX, &MyClass::setX)
      .class_function("getStringFromInstance", &MyClass::getStringFromInstance);
  emscripten::function("rectangle_area", &area);
}

// class MyClass {
// public:
//   std::vector<int> vecValue;

//   MyClass() {}

//   void pushValue(int value) { vecValue.push_back(value); }

//   int getValueAtIndex(int index) { return vecValue[index]; }

//   int getVectorSize() { return vecValue.size(); }
// };

// EMSCRIPTEN_BINDINGS(my_module) {
//   emscripten::class_<MyClass>("MyClass")
//       .constructor<>()
//       .function("pushValue", &MyClass::pushValue)
//       .function("getValueAtIndex", &MyClass::getValueAtIndex)
//       .function("getVectorSize", &MyClass::getVectorSize)
//       .allow_raw_pointer<MyClass *>(
//           "MyClassRawPtr"); // Specify allow_raw_pointer for MyClass*
// }
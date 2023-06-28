#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <vector>

int area(int width, int height) { return width * height; }

class TestClassSharedPtr {
public:
  std::vector<int> vecValue;

  TestClassSharedPtr() {}

  void pushBack(int value) { vecValue.push_back(value); }

  int getValueAtIndex(int index) { return vecValue[index]; }

  int getSize() { return vecValue.size(); }

  int getValueAtIndexwithPtr(std::shared_ptr<TestClassSharedPtr> ptr,
                             int index) {
    return ptr->vecValue[index];
  }
};

class doubleVectorIterator {
public:
  std::vector<double>::iterator iterator;

  std::vector<double>::iterator get_iterator() { return iterator; }

  void set_iterator(std::vector<double>::iterator it_) { iterator = it_; }

  void set_object(doubleVectorIterator it_) { iterator = it_.iterator; }

  double get_value() { return (*(this->iterator)); }
};

struct VectorIterator {
  doubleVectorIterator iterator;
};

class constDoubleVectorIterator {
public:
  std::vector<double>::const_iterator iterator;

  std::vector<double>::const_iterator get_iterator() { return iterator; }

  void set_iterator(std::vector<double>::const_iterator it_) { iterator = it_; }
};

class TestClassVecIterator {
public:
  std::vector<double> vecValues;
  int size() { return vecValues.size(); }
  void pushBack(double value) { vecValues.push_back(value); }

  doubleVectorIterator begin() {
    doubleVectorIterator pt;
    pt.set_iterator(vecValues.begin());
    return pt;
  }

  doubleVectorIterator end() {
    doubleVectorIterator pt;
    pt.set_iterator(vecValues.end());
    return pt;
  }

  constDoubleVectorIterator cbegin() const {
    constDoubleVectorIterator cpt;
    cpt.set_iterator(vecValues.cbegin());
    return cpt;
  }

  constDoubleVectorIterator cend() const {
    constDoubleVectorIterator cpt;
    cpt.set_iterator(vecValues.cend());
    return cpt;
  }

  double getValueForIterator(doubleVectorIterator *iteratorClass) {
    return (*(*iteratorClass).iterator);
  }

  void erase(doubleVectorIterator it) { vecValues.erase(it.iterator); }

  double sum() {
    double result = 0;
    for (auto it = vecValues.begin(); it != vecValues.end(); ++it) {
      result += *it;
    }
    return result;
  }
};

class TestClassBackForth {
public:
  int m_value;
  void set_integer(int value_) { m_value = value_; }

  int get_integer(TestClassBackForth *ptr) { return ptr->m_value; }
};

TestClassBackForth *passThrough(TestClassBackForth *ptr) { return ptr; }

TestClassBackForth passThroughObject(TestClassBackForth obj) { return obj; }

EMSCRIPTEN_BINDINGS(my_module) {
  emscripten::class_<TestClassVecIterator>("TestClassVecIterator")
      .constructor<>()
      .function("pushBack", &TestClassVecIterator::pushBack)
      .function("size", &TestClassVecIterator::size)
      .function("begin", &TestClassVecIterator::begin,
                emscripten::allow_raw_pointers())
      .function("end", &TestClassVecIterator::end,
                emscripten::allow_raw_pointers())
      .function("cbegin", &TestClassVecIterator::cbegin,
                emscripten::allow_raw_pointers())
      .function("cend", &TestClassVecIterator::cend,
                emscripten::allow_raw_pointers())
      .function("erase", &TestClassVecIterator::erase)
      .function("sum", &TestClassVecIterator::sum)
      .function("getValueForIterator",
                &TestClassVecIterator::getValueForIterator,
                emscripten::allow_raw_pointers());

  emscripten::value_object<VectorIterator>("VectorIterator")
      .field("VectorIterator", &VectorIterator::iterator);

  emscripten::class_<doubleVectorIterator>("doubleVectorIterator")
      .constructor<>()
      .function("get_iterator", &doubleVectorIterator::get_iterator,
                emscripten::allow_raw_pointers())
      .function("set_iterator", &doubleVectorIterator::set_iterator,
                emscripten::allow_raw_pointers())
      .function("get_value", &doubleVectorIterator::get_value,
                emscripten::allow_raw_pointers())
      .function("set_object", &doubleVectorIterator::set_object,
                emscripten::allow_raw_pointers());

  emscripten::class_<constDoubleVectorIterator>("constDoubleVectorIterator")
      .constructor<>()
      .function("get_iterator", &constDoubleVectorIterator::get_iterator,
                emscripten::allow_raw_pointers());

  emscripten::class_<TestClassBackForth>("TestClassBackForth")
      .constructor<>()
      .function("set_integer", &TestClassBackForth::set_integer)
      .function("get_integer", &TestClassBackForth::get_integer,
                emscripten::allow_raw_pointers());

  function("passThrough", &passThrough, emscripten::allow_raw_pointers());
  function("passThroughObject", &passThroughObject,
           emscripten::allow_raw_pointers());

  emscripten::class_<TestClassSharedPtr>("TestClassSharedPtr")
      .smart_ptr_constructor("TestClassSharedPtr",
                             &std::make_shared<TestClassSharedPtr>)
      .function("pushBack", &TestClassSharedPtr::pushBack)
      .function("getValueAtIndex", &TestClassSharedPtr::getValueAtIndex)
      .function("getSize", &TestClassSharedPtr::getSize)
      .function("getValueAtIndexwithPtr",
                &TestClassSharedPtr::getValueAtIndexwithPtr);

  emscripten::function("rectangle_area", &area);
}
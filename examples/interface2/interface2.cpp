#include <xtd/xtd.core>

using namespace std;
using namespace xtd;

namespace examples {
  class istringable : public interface {
  public:
    virtual std::string to_string() const = 0;
  };
  
  class program : public istringable {
  public:
    program() = default;
    std::string to_string() const override {return "program";}
  };
}

int main() {
  std::shared_ptr<examples::istringable> stringable = std::make_shared<examples::program>();
  cout << stringable->to_string() << endl;
}

// This code produces the following output:
//
// program

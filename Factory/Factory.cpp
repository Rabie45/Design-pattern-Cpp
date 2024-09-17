#include <iostream>
#include <memory>

class IBank {
public:
  virtual void withdraw() = 0;
  virtual ~IBank() = default; // Virtual destructor
};

class BankA : public IBank {
public:
  void withdraw() override {
    std::cout << "Your request is handling by bank A" << std::endl;
  }
};

class BankB : public IBank {
public:
  void withdraw() override {
    std::cout << "Your request is handling by bank B" << std::endl;
  }
};

class IBankFactory {
public:
  virtual std::unique_ptr<IBank> GetBank(int bankcode) = 0;
  virtual ~IBankFactory() = default; // Virtual destructor
};

class BankFactory : public IBankFactory {
public:
  std::unique_ptr<IBank> GetBank(int bankcode) override {
    if (bankcode == 1) {
      return std::make_unique<BankA>();

    } else if (bankcode == 2) {
      return std::make_unique<BankB>();
    }
    return nullptr;
  }
};

int main() {
  BankFactory BankFactory;
  std::unique_ptr<IBank> bank = BankFactory.GetBank(1);

  if (bank) {
    bank->withdraw(); // Polymorphic call
  } else {
    std::cout << "Invalid bank type selected." << std::endl;
  }
  return 0;
}